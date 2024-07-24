#include <stdio.h>

void minha_divisao ( int dividendo, int divisor,
	int *ptr_quociente, int *ptr_resto){		
		*ptr_quociente = dividendo / divisor;
		*ptr_resto = dividendo - (*ptr_quociente) * divisor;
}

int main() {
	int a, b, t, r;
	printf("Dividendo:\n");
	scanf("%d", &a);
	printf("Divisor:\n");
	scanf("%d", &b);
	
	minha_divisao(a, b, &t, &r);
	
	printf("Resultado:%d	Resto:%d\n", t, r);
}	
