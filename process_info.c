
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){

	pid_t pid;
	pid = fork();
	

	if( pid == 0){
	printf("PID: %d\n", getpid());
	}

	else if(pid > 0){
		printf("PPID: %d\n", getppid());
		//sleep(20);
	}
/*
	if( getppid() == 1){
		printf("i am here");
	}
*/
	printf("PGID: %d\n", getpgid(pid));
	
	return 0;
}