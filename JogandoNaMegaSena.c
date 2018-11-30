#include <stdio.h>

#define valorSorteio 3e6
#define apostaMinima 3.5
#define Njogo 6

void randResult(int vetor[]);
int isequal(int vetor1[], int vetor2[]);


void main(){
	srand(time(NULL));
	int i, x, j, resultadoMS[Njogo], jogador1[Njogo];
	for(x=0; x<1e6; x++){
		randResult(resultadoMS);
		randResult(jogador1);
		for(i=0; i<Njogo; i++){
			printf("%d\t", jogador1[i]);
		}
		printf("\n");
		for(j=0; j<Njogo; j++){
			printf("%d\t", resultadoMS[j]);
		}
		printf("\n*******************************************************\n");
		if(isequal(resultadoMS, jogador1)){
			printf("GANHOU");
			break;		
		}
	}	
	
}
void randResult(int vetor[]){
	int i=0, x, rand1, aux;	
	do{
		aux = 1;
		rand1 = (rand() % 60)+1;
		for(x = 0; x<=i; x++){
			if(rand1 == vetor[x]){
				aux = 0;
				break;
			}
		}
		if(aux){
			vetor[i] = rand1;
			i++;	
		}		
	}while(i<Njogo);
}
int isequal(int vetor1[], int vetor2[]){
	int i;
	for(i=0; i<Njogo; i++){
		if(vetor1[i] != vetor2[i])
			return 0;	
	}
	return 1;
}
