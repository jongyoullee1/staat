#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <string.h>
#include <errno.h>


void info(char* fp){
	struct stat *ans = (struct stat *)malloc(sizeof(struct stat));
	if(stat(fp, ans) == -1) printf("Error #%d: %s", errno, strerror(errno));
	long s = (long)ans->st_size;
	char *a;

	if (s < 1024){
		strcpy(a, "B");
	} else if ( s > 1024 && s <1024*1024 ){
		strcpy(a, "KB");
		s = s%1024;
	} else if (  s > 1024*1024 && s < 1024*1024*1024){
		strcpy(a, "MB");
		s = s%1024*1024;
	} else {
		strcpy(a, "GB");
		s = s%1024*1024*1024;
	}	
	/**/
	int mode =  ans->st_mode & 0777;
	printf("File Name: %s\nFile Size: %ld%s\nMode: %d\nTime of last access: %s",fp, s, a ,mode,  ctime(&(ans->st_atime)));

	char perm[10];
	int i = 8;
	while (mode) {
    perm[i] = (mode % 2) ? 'x' : '-'; mode /= 2; i--;
    perm[i] = (mode % 2) ? 'w' : '-'; mode /= 2; i--;
    perm[i] = (mode % 2) ? 'r' : '-'; mode /= 2; i--;
  }
	perm[9] = 0;


	printf("\nFile Permissions: \t%s\n", perm);

}

int main() {
	info("info.c");
	return 0;
}

