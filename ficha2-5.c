#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/mman.h>


int main(){
	
	char *ptr = malloc(8); //alocar umbloco de 8 bytes
	char p [] = "pai";		//string 'pai'
	char f [] = "filho";	//string 'filho'
	strcpy(ptr, p);
	
	pid_t r = fork(); //biforcaçao, cria processo filho, 
						//no processo filho r==0
	
	if (r==0){	
		strcpy(ptr, f);	//copia string filho para o malloc
		printf("%s\n", ptr);	//impressao malloc (filho)
		
		exit (0);	//termina processo filho
	}
	
	waitpid(r,NULL,0);	//aguarda o fim do processo filho
	
	printf("%s\n", ptr);	//imprime malloc (pai)
}
