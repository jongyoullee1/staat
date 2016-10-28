#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>


void info(char* fp){
	struct stat *ans = (struct stat *)malloc(sizeof(struct stat));
	stat(fp, ans);
	
	printf("File Name: %s\nFile Size: %ldB\nMode: %o\nTime of last access: %s",fp, (long)ans->st_size, ans->st_mode, ctime(&(ans->st_atime)));
}

int main() {
	info("info.c");
	return 0;
}

