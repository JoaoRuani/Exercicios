#include <stdio.h>
#include <locale.h>

char situacao(float p1, float p2, float p3, int faltas, int aulas, float *media);

int main(void){
	setlocale(LC_ALL,"portuguese");
	float p1, p2, p3, media;
	int aulas, faltas;
	printf("Digite a 1º, 2º e 3º nota respectivamente: ");
	scanf("%f %f %f", &p1, &p2, &p3);
	printf("Digite a quantidade de aulas aplicadas: ");
	scanf("%d", &aulas);
	printf("Digite a quantidade de faltas: ");
	scanf("%d", &faltas);
	printf("O aluno foi: %c\n", situacao(p1, p2, p3, faltas, aulas, &media));
	printf("Com media: %f\n", media);
}
char situacao(float p1, float p2, float p3, int faltas, int aulas, float *media){
	float percen = faltas*100/aulas;
	*media = (p1+p2+p3)/3;
	if(percen <= 25){
		if(*media >=6)
			return 'A';
		return 'R';	
	}
	return 'F';
}
