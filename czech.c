//open, close, read, write, lseek, malloc, free, getpid
//kill, signal, sigation, sigemptyset, setcontext
//getcontext, usleep, nanosleep, pause


#include "./navy_project/include/my.h"

///Users/dakolyay/Desktop/navy_project/include
bool check1(char *attack,char** carte){ // атакует

	//printf("attack: ");
	bool check = true;
	//char attack[2];
	

	if((int)attack[0] < 'A' || (int)attack[0] > 'H' || (int)attack[1] < '1' || (int)attack[1] > '8'){
		//check = true;
		printf("wrong position\n");
		//printf("attack: ");
		return false;
	}
	else{
		int j = (((int)(attack[0])) - 'A') * 2;
		int i = (((int)(attack[1])) - '0') - 1;

		if(carte[i][j] != ' ' || carte[i][j] != '.'){
			printf("%s: hit", attack);
			carte[i][j] = 'o';

		} 
		else{
			carte[i][j] = 'x';
			printf("%s: missed", attack);
		}	

		return true;
	}



/*
	while(check){

		//char *attack[2];
		scanf("%s\n", attack);
		printf("%c\n", attack[0]);
		if((int)attack[0] < 'A' || (int)attack[0] > 'H' || (int)attack[1] < '1' || (int)attack[1] > '8'){
			check = true;
			printf("wrong position\n");
			printf("attack: ");
		}
		else{
			printf("ok\n");
			check = false;
		}
	}

	int j = (((int)(attack[0])) - 'A') * 2;
	int i = (((int)(attack[1])) - '0') - 1;

	if(carte[i][j] != ' ' || carte[i][j] != '.'){
		printf("%s: hit", attack);
		carte[i][j] = 'o';

	} 
	else{
		carte[i][j] = 'x';
		printf("%s: missed", attack);
	}	
*/
}





/*
char** init(int c){

	if(c == 1)
	{
		char** map1 = malloc(8*sizeof(char*));
		for (int i = 0; i < 8; ++i)
		{
			map1[i] = malloc(15*sizeof(char));

			for (int j = 0; j < 15; ++j)
			{
				map1[i][j] = '.';
			}
		}
		return map1;
	}

	else if(c == 2)
	{
		char** map2 = malloc(8*sizeof(char*));
		for (int i = 0; i < 8; ++i)
		{

			map2[i] = malloc(15*sizeof(char));
			for (int j = 0; j < 15; ++j)
			{
				map2[i][j] = '.';
			}
		}
		return map2;
	}

	else{
		return NULL;
	}
	return NULL; 
}
*/
/*
void put_my_boat(int arr[], char a, char** map){


	
	//printf("ok\n");
	if(arr[1] == arr[3]){ // вертикально рассматриваем j
		for(int j = arr[2]; j <= arr[4]; j++ ){
			map[j-1][arr[1]*2] = a;
		}
		
	}

	else if(arr[2] == arr[4]){ //горизонтально
		for(int i = arr[1] * 2; i <= arr[3] * 2; i+=2){
			map[arr[2]-1][i] = a; 
			//printf("It is %d\n", arr[3] );
		}
	}

	else{
	 	err();
	}

	//show_map(map);

}
*//*
bool checking(char *arr){

	
	if((int)arr[0] < '2' || (int)arr[0] > '5'){
		return false;
	}
	if((int)arr[2] < 'A' || (int)arr[2] > 'H'){
		return false;
	}
	if((int)arr[3] < '1' || (int)arr[3] > '8'){
		return false;
	}
	if((int)arr[5] < 'A' || (int)arr[5] > 'H'){
		return false;
	}
	if((int)arr[6] < '1' || (int)arr[6] > '8'){
		return false;
	}

	return true;

}
*/
/*
void converter(char *arr, char** mp){

	if(checking(arr)){

		int new_arr[10];
		char a = arr[0]; 
		int boat_size = (int)a - 48;
		new_arr[0] = boat_size;


		new_arr[1] = (int)arr[2] - 'A'; //A = 65 буква
		new_arr[2] = (int)arr[3] - '0'; // 0 = 48
		new_arr[3] = (int)arr[5] - 'A'; //A = 65 буква
 		new_arr[4] = (int)arr[6] - '0';

 		put_my_boat(new_arr, a, mp);
 	}
 	else{
 		err();
 	}

 	for (int i = 0; i < 5; ++i)
 	{
 		printf("%d ", new_arr[i] );
 	}
 	printf("\n");


}
*/
/*
//if the struct is the pointer == use ->
void hatme(int sigg, siginfo_t *sin, void* useless){
	
	int l = 0;
	if(sigg == SIGUSR1){
		kill(sin->si_pid, SIGUSR2);
	}	
	else if(sigg == SIGUSR2){
		l = l + 1;
	}
	
	else{
		err();
	}
}
*/
int main(int argc, char *argv[]){


	

	if( argc == 2 ){ //pos1

		int pid1 = getpid();
		printf("my_pid: %d\n", getpid());
		printf("waiting for enemy connection...\n\n");

		struct sigaction sigme;
		sigme.sa_sigaction = &hatme; //fuction pointers
		sigme.sa_flags = SA_SIGINFO;

		if((sigaction(SIGUSR1,&sigme,NULL)) == 0){
			pause();
			printf("enemy connected\n\n");
		}
		else{
			return 84;
		}

		char** map = init(1);
		char inp1[50];
		int a = open("pos1.txt", O_RDONLY);
		
		if(a > 0)
		{
			int w;
			int flag = 1;
			while((w = read(a, inp1, 8)) > 0)
			{
				converter(inp1, map);
			}
			show_map(map);
			//check1(map);
			char attack[2];
			printf("attack: ");
			scanf("%s", attack);
			while(check1(attack, map) == false){
				scanf("%s", attack);
				//printf("attack: ");
			}


			if( w == 0){
				close(a);
			}
			else{
				return 84;
			}

		}

		else
		{
			return 84;
		}

		
	}

	else if( argc == 3 ){

		int pid2 = getpid();
		printf("my_pid: %d\n", pid2);
		kill(atoi(argv[1]), SIGUSR1);

		struct sigaction sigme;
		sigme.sa_sigaction = &hatme; //fuction pointers
		sigme.sa_flags = SA_SIGINFO;

		if((sigaction(SIGUSR2,&sigme,NULL)) == 0){
			pause();
			//printf("enemy connected\n");
		}
		else{
			return 84;
		}

		printf("successfully connected\n\n");


		char** map = init(2);
		char inp2[50];
		int b = open("pos2.txt", O_RDONLY);

		if(b > 0)
		{
			int v;
			int flag = 2;
			while((v = read(b, inp2, 8)) > 0)
			{
				converter(inp2, map);
			}
			show_map(map);
			if( v == 0)
			{
				close(b);
			}
			else
			{
				return 84;
			}
		}
		else
		{
			return 84;
		}

	}



	return 0;
}