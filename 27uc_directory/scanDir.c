#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

int scandir(const char *dirp, struct dirent ***namelist,
              int (*filter)(const struct dirent *),
              int (*compar)(const struct dirent **, const struct dirent **));
int alphasort(const struct dirent **a, const struct dirent **b);

int filter(const struct dirent* p)
{
	return (strlen(p->d_name)>5);
}

int main(int argc,char* argv[])
{
	const char* path=".";
	if(argc>1)
		path=argv[1];

	struct dirent** namelist;
	int n=scandir(path,&namelist,0,alphasort);
	int i;
	for(i=0;i<n;++i){
		printf("%d:%s\n",i+1,namelist[i]->d_name);
		free(namelist[i]);
	}
	free(namelist);
        return 0;
}
