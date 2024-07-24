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


int memcpy_new(void *dest, const void *src, size_t n){
	char *s1 = dest;
	const char *s2 = src;
	
	for (int i = 0; i < n; i++){
		if (s1[i] != s2[i]) {
			return -1;
		}
	}
	return 0;
}

int main(){
	char str1[] = "Teste!";
	int data1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	char str2[1000];
	int data2[1000];
	
	char * a = strcpy(str2, str1);
	
	memcpy_new(data2, data1, sizeof(data1));
	
	if (memcpy_new(str2,str1,sizeof(str1)) == 0){
		printf("Iguais!\n");
	}else {
		printf("Diferentes!\n");
	}
	
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
