#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/wait.h>


void myhandler(int signum){
	printf("Recebi o sinal SIGCHLD\n");
}

int main() {
	 
	 //Bloquear sinais SIGINT e SIGQUIT
	 sigset_t s;
	 sigemptyset (&s);
	 sigaddset(&s, SIGINT);
	 sigaddset(&s, SIGQUIT);
	 sigprocmask(SIG_BLOCK, &s, NULL);
	 
	 //Ignorar SIGTERM em todos os processos
	 signal(SIGTERM, SIG_IGN);
	 
	 //funçao de atendimento para SIGCHLD
	 signal(SIGCHLD, myhandler);
	 
	 while(1) {
		 printf("Processo pai\n");
		 sleep(2);
		 
		 pid_t r = fork();
			
			if(r == 0) {
				//SIGCHLD default
				signal(SIGCHLD, SIG_DFL);
				
				//Bloqueio de SIGSTP nos novos processos
				sigemptyset(&s);
				sigaddset(&s, SIGTSTP);
				sigprocmask(SIG_BLOCK, &s, NULL);
				printf("Processo filho\n");
				sleep(1);
				return(0);
			} else if ( r > 0) {
				wait(NULL);
			}
	 }
	 return(0);
}

/*
 * OUTPUT
 * sandro@toshibasandro:~/SISTC/Ficha3$ ./exIII
Processo pai
Processo filho
Recebi o sinal SIGCHLD
Processo pai
Processo filho
Recebi o sinal SIGCHLD
Processo pai
Processo filho
Recebi o sinal SIGCHLD
Processo pai
Processo filho
Recebi o sinal SIGCHLD
*/ 
