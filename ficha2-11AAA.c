#include <stdio.h>
#include <unistd.h>

void fun1(int *d) {
	++d[0];
	printf("Novo valor gerado em fun1: %d\n", d[0]);
	sleep(2);
}

void fun2(int *d) {
	sleep(1);
	printf("Valor processado por fun2: %d\n", d[0]);
}

int main(){
	int dados = 0;
	
	while(1) {
		fun1(&dados);	//incrementa 1 em dados por referencia
		fun2(&dados);	//print do valor de dados recebido por referencia 
	}
}
//intervalo de 3s entre as impressoes
/*
 sandro@toshibasandro:~/SISTC/Ficha2$ ./ex11
Novo valor gerado em fun1: 1
Valor processado por fun2: 1
Novo valor gerado em fun1: 2
Valor processado por fun2: 2
Novo valor gerado em fun1: 3
Valor processado por fun2: 3
Novo valor gerado em fun1: 4
Valor processado por fun2: 4
Novo valor gerado em fun1: 5
Valor processado por fun2: 5
Novo valor gerado em fun1: 6

 */ 
