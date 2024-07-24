#include <stdio.h>
#include <string.h>

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


int main(){
	vehic_t v1 = {{'1', '4', '7', '9', 'H', 'P'}, 
		"Carlos Reis Salvador Almada",
		2999999.99};
vehic_print(&v1);
return 0;
}
