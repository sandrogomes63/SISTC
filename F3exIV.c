#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

//função incremntar +1 e imprimir
void fun1(int *d) {
	 ++d[0];
	 printf("Novo valor gerado em fun1: %d\n", d[0]);
	 sleep(2);
}

//função imprimir
void fun2(int *d) {
	 sleep(1);
	 printf("Valor processado por fun2: %d\n", d[0]);
	}
	
//função para ajudar a perceber se o sinal SIGCHLD foi recebido e processado como desejado
void myHandler (int signum){
	printf("Recebi SIGCHLD\n");
}

int main(){

	struct sigaction act;
	act.sa_handler = myHandler; //função de tratamento quando recebe o sinal
	sigemptyset(&act.sa_mask); //garante que nenhum sinal é bloqueado durante o tratamento de SIGCHLD
	act.sa_flags = SA_NOCLDWAIT; //processos filho nao passam pelo estado zombie
	sigaction(SIGCHLD, &act, NULL); //configura o sinal SIGCHLD com as config da struct act
	
	 int dados = 0;	//variavel dados
	 
	 while(1) {
		 
		fun1(&dados); //chama fun1, envia endereço da var dados
	 
		pid_t r = fork();	//biforca, cria processo filho
	 
			if(r == -1) {	//erro fork
				perror("fork");
				exit(1);
			}
			
			if(r==0) {		//processo filho
				
				fun2(&dados); //chama fun2, envia endereço da var dados
				exit(0);
			}
	 }
}

/*OUTPUT
 * sandro@toshibasandro:~/SISTC/Ficha3$ ./exIV
Novo valor gerado em fun1: 1
Novo valor gerado em fun1: 2
Valor processado por fun2: 1
Recebi SIGCHLD
Novo valor gerado em fun1: 3
Valor processado por fun2: 2
Recebi SIGCHLD
Novo valor gerado em fun1: 4
Valor processado por fun2: 3
Recebi SIGCHLD
Novo valor gerado em fun1: 5
Valor processado por fun2: 4
Recebi SIGCHLD
Novo valor gerado em fun1: 6
Valor processado por fun2: 5
Recebi SIGCHLD
Novo valor gerado em fun1: 7
^C
*/ 
