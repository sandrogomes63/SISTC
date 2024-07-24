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

int strcmp_new(const char *s1, const char *s2){
	while (*s1 && *s2 && *s1 == *s2){
		s1++;
		s2++;
	}
		if (*s1 == '\0' && *s2 == '\0'){
			return 0;
		} else {
			return -1;
		}
}

int main(){
	char str1[] = "Teste!";
	int data1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	char str2[1000];
	int data2[1000];
	
	char str3[] = "Teste!";
	
	char * a = strcpy(str2, str1);
	memcpy(data2, data1, sizeof(data1));
	
	if (strcmp_new(str1,str3) == 0){
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
