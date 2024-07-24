#include <stdio.h>
#include <string.h>

char *strcpy(char *destino, const char *source){
	char *copia = destino;
	while (*copia++ = *source++);
	return destino;
}

void *memcpy(void *destino, const void *source, size_t n){
	char *s = (char *) source;
	char *end = s + n;
	char *d = (char *) destino;
	
	while( s != end)
		*d++ = *s++;
		
	return destino;
}

int main(){
	char str1[] = "Teste!";
	int data1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	char str2[1000];
	int data2[1000];

	char * a = strcpy(str2, str1);
	memcpy(data2, data1, sizeof(data1));
	
	printf("%ld\n", sizeof(str1));
	printf("%ld\n", sizeof(data1));
	printf("%ld\n", sizeof(str2));
	printf("%ld\n", sizeof(data2));
	printf("%s\n", a);
	
	for (int i = 0; i<10; i++){
		printf("%d, ", data2[i]);
	}
	
	printf("\n");
return(0);
}

//Há outra forma de mostrar data2???
