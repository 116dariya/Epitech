
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>

char word[1000];
char *args[1000];
char history[1000][1000];
int main(){	
	int run = 1;
	int cnt = 1;
	while(run == 1){
		//gets(word);
		fgets(word, strlen(word), stdin);
		strcpy(history[cnt] ,word);
		if(strstr(word , "history")!=NULL){
			for(int i=1 ; i <= cnt ; i++){
				printf("%d " , i);
				printf("%s\n" , history[i]);		
			
			}
			continue;
		}
		
		else if(strstr(word, "!")!=NULL){
			printf("%s\n" , history[cnt-1]);
			continue;
		}
		
		else if(strstr(word , "!!")!=NULL){
			int j;
			scanf("%d" , &j);
			if(j <= cnt){
				printf("%s\n" , history[j]);
			}
			continue;
		}

		
		else if(strstr(word , "exit")!=NULL){
			printf("%s\n" ,"Bye");
			return 0;	
		}
		cnt++;

		int q;
		char* token = strtok(word , " ");
		args[0]=token;
		token = strtok(NULL , " ");
		int cnt2 = 1;
		while(token!=NULL){
			args[cnt2]=token;
			token = strtok(NULL , " ");
			cnt2++;
		} 
		args[cnt2]=NULL;
		// 1 часть
		pid_t pid;
		pid = fork();
		if(pid<0){
			fprintf(stderr , "FORK FAILED\n");
			continue;
		}	
		else if(pid==0){
		execvp(args[0] , args);	
		// 2 часть
		exit(0);
		}//3 часть
		else{	
		
			sleep(2);
			system("ps -l");
			system("kill -9 <PID>");
			exit(0);

		//if(q == 1) wait(NULL);
		//printf("CHILD COMPLETE\n");
		
		}
	}
	run = 2;
	return 0;
}