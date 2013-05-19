#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

struct Student{
	unsigned long id;
	char name[20];
	char gender;  //M,W
	float score;
};
typedef struct Student Stu;

int main()
{
	//a(add) id|s(search) id|m(modify) id score |q(qiut)
	printf("=========MENU=========\n");
	printf(" a. Add a student\n");
	printf(" s. Search for a student\n");
	printf(" m. Modify a student's score\n");
	printf(" q.Quit\n");
	printf("======================\n\n");
	Stu a;
	int fd=open("info.dat",O_RDWR|O_CREAT,0600);
	if(fd<0){
		printf("Open file failed.\n");
		return -1;
	}
	unsigned long len=lseek(fd,0,SEEK_END);
	unsigned long  num=len/sizeof(Stu);
	printf("Current the number of stdents:%ld \n",num);
	char cmd;
	float score;
	unsigned long id;
	while(1){
		printf(">>");
		scanf(" %c",&cmd);
		if(cmd=='q'){
			close(fd);
			break;
		}
		switch(cmd){
		case 'a':
			printf("input your name sex score:\n");
			scanf("%s %c%f",a.name,&a.gender,&a.score);
			a.id=++num;
			lseek(fd,0,SEEK_END);
			write(fd,&a,sizeof(a));
			break;
		case 's':
			printf("input the ID which you want to find.\n");
			scanf("%ld",&id);
			if(id<0||id>num){
				printf("the ID you input is invalid.\n");
				break;
			}
			lseek(fd,(id-1)*sizeof(Stu),SEEK_SET);
			read(fd,&a,sizeof(Stu));
			printf("ID:%ld\t Name:%s\t Sex:%c\t Score:%f\n",id,a.name,a.gender,a.score);
			break;
		case 'm':
			printf("input the ID and score:\n");
			scanf("%ld%f",&id,&score);
			if(id<0||id>num){
				printf("the ID invalid.\n");
				break;
			}
			if(score<0||score>100){
				printf("the score invalid.\n");
				break;
			}
			lseek(fd,(id-1)*sizeof(Stu),SEEK_SET);
			read(fd,&a,sizeof(Stu));
			a.score=score;
			lseek(fd,-sizeof(Stu),SEEK_CUR);  //Attention!! -sizeof(Stu)
			write(fd,&a,sizeof(Stu));
			break;
		case 'q':
			close(fd);
			return 0;
		default:
			break;
		}
	}
		
        return 0;
}
