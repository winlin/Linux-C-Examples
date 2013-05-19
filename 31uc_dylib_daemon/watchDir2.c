/*
 *另一个，监视文件变化的方法是：
 *特定间断进行两次ftw()，产生两个statlist链表，然后，再对这两个链表从头到尾
 *进行对比，这样既可以找到“新建的，删除的，修改的”
 *但是，当ftw进行递归的深度太大的话，会占用太多的内存空间，因为，每个文件
 *我们都保存了一个stat和文件名，双向指针。
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <ftw.h>
#include <time.h>
#include <fcntl.h>

typedef struct node{
	struct stat mStat;
	char mPath[1024];
	struct node* mNext;
}Node;

Node* statList=NULL;
int count=0;
short* array=NULL;
int fd;  /* 记录文件 */
char* logpath="./log.txt";   /* 记录文件路径 */


/* 与链表记录比较返回文件的原始大小 */
long compare(const struct stat* sta)
{
	long temp;
	Node* p=statList;
	int i=0;
	while(p){
		if(p->mStat.st_ino==sta->st_ino){
			array[i]=1;
			temp=p->mStat.st_size;
			memcpy(&(p->mStat),sta,sizeof(struct stat));
			return temp;  //如果存在返回原来大小
		}
		i++;
		p=p->mNext;
	}
		
	return -1;                    //新建的文件返回-1       
}
/* 获得修改文件的一条记录 */
void getRecord(char* log,const char* fpath,const struct stat* sb,long preSize)
{
	struct tm* ptm=localtime(&(sb->st_mtime));
	if(preSize!=-1)
		sprintf(log,"Time:%02d %02d  File:%s  Modified  Size:%ld  OldSize:%ld\n",
			 ptm->tm_mon,ptm->tm_mday,fpath,(long)sb->st_size,preSize);
	else
		sprintf(log,"Time:%02d %02d  File:%s  Create  Size:%ld\n",
			 ptm->tm_mon,ptm->tm_mday,fpath,sb->st_size);
	
}

/* ftw()遍历时对每个目录执行的操作 */
int everyFile(const char* fpath,const struct stat* sb,int typeflag )
{
	if(strcmp(fpath,logpath)==0)
		return 0;
	long re=compare(sb);
	char log[1024];
	int wnumber;
	if(re!=-1){
		if(sb->st_size==re);
		else{
			getRecord(log,fpath,sb,re);
			if((wnumber=write(fd,log,strlen(log)))<0||wnumber!=strlen(log)){
				perror("write");
				exit(-1);
			}
		}
	}
	else if(re==-1){
		Node* p=NULL;
		p=(Node*)calloc(1,sizeof(Node));
		memcpy(&(p->mStat),sb,sizeof(struct stat));
		p->mNext=statList;
		statList=p;
		
		getRecord(log,fpath,sb,re);
		if((wnumber=write(fd,log,strlen(log)))<0||wnumber!=strlen(log)){
			perror("write");
			exit(-1);
		}
	}
	return 0;
}

int firstScan(const char* fpath,const struct stat* sb,int typeflag )
{
	if(strcmp(fpath,logpath)==0)
		return 0;
	Node* p=NULL;
	p=(Node*)calloc(1,sizeof(Node));
	memcpy(&(p->mStat),sb,sizeof(struct stat));
	strcpy(p->mPath,fpath);
	p->mNext=statList;
	statList=p;

	count++;
	return 0;
}

void delFile()
{
	Node* p=statList;
	Node* tmp=p;
	int i=0;
	while(array[i]&&p){
		tmp=p;
		p=p->mNext;
		i++;
	}
	char log[1024];
	struct tm* ptm=localtime(&(p->mStat.st_mtime));
	sprintf(log,"Time:%02d %02d  File:%s  Deleted\n",
			 ptm->tm_mon,ptm->tm_mday,p->mPath);

	tmp->mNext=p->mNext;
	free(p);
	int wnumber;
	if(i!=count){
		if((wnumber=write(fd,&log,strlen(log)))<0||wnumber!=strlen(log)){
			perror("write");
			exit(-1);
		}
	}
}

int main(int argc,char* argv[])
{
	if(argc<2){
		printf("Usage: %s directory [log file path].\n",argv[0]);
		return 0;
	}
	if(argc==3)
		logpath=argv[2];
	
	if(fork()!=0)
		return 0;
	int i;
	for(i=0;i<256;++i)
		close(i);
	if(setsid()<0){
		perror("setsid");
		exit(-1);
	}
	umask(0000);
	if(chdir(argv[1])<0){
		perror("chdir");
		exit(-1);
	}

	fd=open(logpath,O_CREAT|O_WRONLY|O_APPEND,0644);
	if(fd<0){
		perror("open");
		exit(-1);
	}
	/* 首先建立一个原始状态链表 */
	ftw(argv[1],firstScan,20);
	array=(short*)calloc(0,count*sizeof(short));
	while(1){
		ftw(argv[1],everyFile,20);
		delFile();
		sleep(2);
	}
	
	return 0;
}
