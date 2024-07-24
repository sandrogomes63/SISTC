#include <stdio.h>

int main() {
	int a, b, t, r;
	printf("Dividendo:\n");
	scanf("%d", &a);
	printf("Divisor:\n");
	scanf("%d", &b);
	
	t = a / b;
	r = a - t * b;
	
	printf("Resultado:%d	Resto:%d\n", t, r);
}	
