#include <stdio.h>
#include <locale.h>
#include <math.h>
#define quantidadeCabos 5

main(){
	setlocale(LC_ALL,"portuguese");
	float comprimentoPonte, alturaHaste, somaCabo, divisaoHaste, divisaoPonte;
	int i;
	
	do{
		printf("Digite o comprimento da ponte em kilômetros");
		scanf("%f", &comprimentoPonte);
	}while(comprimentoPonte<2 || comprimentoPonte >4);	
	
	comprimentoPonte *= 1000; //CONVERTE EM METROS
	divisaoHaste = alturaHaste/quantidadeCabos; //DEFINE A DISTÂNCIA ENTRE OS CABOS NA HASTE
	divisaoPonte = (comprimentoPonte/2) / quantidadeCabos; //DEFINE A DISTÂNCIA ENTRE OS CABOS NA PONTE
	alturaHaste = comprimentoPonte / 20; //DEFINE A ALTURA DA HASTE
	somaCabo = alturaHaste*alturaHaste + (comprimentoPonte/2)*(comprimentoPonte/2); //PITÁGORAS PARA DESCOBRIR O PRIMEIRO CABO
	somaCabo = sqrt(somaCabo); //RAIZ DA FORMULA
	
	for(i=0; i<quantidadeCabos; i++){//CALCULA OS OUTROS 4 CABOS
		alturaHaste -= divisaoHaste;
		comprimentoPonte -= divisaoPonte;
		somaCabo += sqrt(alturaHaste*alturaHaste + (comprimentoPonte/2)*(comprimentoPonte/2));
	}
	
	somaCabo *=4;//MULTIPLICA O COMPRIMENTO DOS CABOS PELAS 4 HASTES
	
	printf("%.2f metros de cabo", somaCabo);
}
