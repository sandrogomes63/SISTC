#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h> 
#include <float.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


//NELEM must be a multiple of 2
#define NELEM 20000000
#define NITER 27
#define NPROC 30
void rectangular2polar(double *, double *, int); 
double mytime();

int main() { 
  double t0;  
  int k = NELEM/NPROC;
  double *dados_in = (double *) malloc(sizeof(double)*NELEM); 
  double *dados_out = (double *) malloc(sizeof(double)*NELEM);
  
  pid_t pid[NPROC];
  
  if(dados_in == NULL || dados_out == NULL) { 
    perror("malloc"); 
    exit(1); 
  } else {
    //assign random initial values
    double maxv = DBL_MAX;
    srand48(time(NULL));
    for(int i = 0; i < NELEM; ++i)
      dados_in[i] = 2*(drand48()-0.5)*maxv;
  }

  //get current time, for benchmarking 
  t0 = mytime();   
	
  //This cycle is used only for benchmarking purposes
		for(int j=0; j < NPROC; j++){	//ciclo for para criação dos 30 processos
			//printf("PID: %d\n", j);
			//printf("NPROC: %d\n", NPROC);

			pid[j] = fork();			//criação processos filho
				if( pid[j]==0){	
					int local = j * k;	//k = parte que o processo deve converter X indice do processo filho 
										//para percorrer toda a memoria de dados in/out
					for(int i=0; i < NITER; ++i){
						rectangular2polar(local+dados_out, local+dados_in, k);
					}
			exit(0);
				}			
		}
		for(int l=0; l < NITER; l++){	//ciclo for para aguardar que cada processo termine
			waitpid(pid[l], NULL, 0);
		}
  printf("Computation took %.1f s\n", mytime() - t0);
 
  return 0; 
  } 

double mytime() {
  struct timeval tp;
  struct timezone tzp;

  gettimeofday(&tp,&tzp);
  return ( (double) tp.tv_sec + (double) tp.tv_usec * 1.e-6 );
}

/* 
 * conversão de coordenadas retangulares em polares
 * 2x10⁶ elementos
 * 27 iterações para dar aproximadamente 10s de processamento
 * 30 processos filho criados para dividir a conversão dos elementos
 * pelo nº de processos filho
 * em vez de 1 processo fazer toda a conversão
 * 30 processos convertem uma parte igualmente distribuida k=NELEM/PROC
 * mais rapidez no processamento de dados
 */ 
