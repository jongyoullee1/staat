#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <string.h>


void info(char* fp){
	struct stat *ans = (struct stat *)malloc(sizeof(struct stat));
	stat(fp, ans);
	long s = (long)ans->st_size;
	char *a;
	if (s < 1000){
		strcpy(a, "B");
	} else if ( s > 1000 && s <1000000 ){
		strcpy(a, "KB");
		s = s%1000;
	} else if (  s > 1000000 && s < 1000000000 ){
		strcpy(a, "MB");
		s = s%1000000;
	} else {
		strcpy(a, "GB");
		s = s%1000000000;
	}

	



	printf("File Name: %s\nFile Size: %ld%s\nMode: %o\nTime of last access: %s",fp, s, a , ans->st_mode, ctime(&(ans->st_atime)));
}

int main() {
	info("info.c");
	return 0;
}

