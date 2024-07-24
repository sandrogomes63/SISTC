#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define VEHIC_MAXPLEN 81
typedef struct {
	char plate[6];
	char owner[VEHIC_MAXPLEN];
	double value;
}	vehic_t;

void vehic_print(vehic_t *v){
		int i = 0;
		while (i < 6){
			printf("%c ", v->plate[i]);
			i++;
		}
		printf("\n%.6s\n", v->plate);
		printf("%s\n", v->owner);
		printf("%.2lf\n", v->value);
}

void vehic_read(vehic_t *v1){
	char s[100];
	//Plate
	printf("Plate:\n");
	fgets(s, sizeof(s), stdin);
	memcpy(v1->plate, s, sizeof(s));
	
	//Owner
	printf("Owner:\n");
	fgets(v1->owner, sizeof(v1->owner), stdin);

	//Value
	printf("Value\n");
	//scanf("%le", &v1->value);
	fgets(s, sizeof(s), stdin);
	v1->value = atof(s);
	
}

int main(){
	vehic_t v1;
	vehic_read(&v1);
	vehic_print(&v1);
	return 0;
}
