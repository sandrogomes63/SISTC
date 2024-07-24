#include <stdio.h>

void minha_divisao ( int dividendo, int divisor,
	int *ptr_quociente, int *ptr_resto){		
		*ptr_quociente = dividendo / divisor;
		*ptr_resto = dividendo - (*ptr_quociente) * divisor;
}

int main(int argc, char* argv[]) {
	int a, b, t, r;
	
	if (argc >= 2){
		a = *argv[1];
		b = *argv[2];
	}
		
	printf("Dividendo:\n");
	scanf("%d", &a);
	printf("Divisor:\n");
	scanf("%d", &b);
	
	minha_divisao(a, b, &t, &r);
	
	printf("Resultado:%d	Resto:%d\n", t, r);
}	
