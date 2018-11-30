#include <stdio.h>

int convertHexa(int numeroDigitado, char *string);
int convertOctal(int numeroDigitado, char *string);
void apresentarInvertido(int strlen, char *string);

int main(void){
	char string[1000];
	int numeroDigitado, strlen;
	puts("Digite um numero decimal natural: ");
	scanf("%d", &numeroDigitado);
	strlen = convertHexa(numeroDigitado, string);
	apresentarInvertido(strlen, string);
	strlen = convertOctal(numeroDigitado, string);
	apresentarInvertido(strlen, string);
}

int convertHexa(int numeroDigitado, char *string){
	int i, resto;
	for(i=0; ;i++){
		resto = numeroDigitado%16;
		if(resto < 10)
			string[i] = resto + 48;
		else
			string[i] = resto + 55;
		if(numeroDigitado < 16){
			if(numeroDigitado< 10)
				string[i] = numeroDigitado + 48;
			else
				string[i] = numeroDigitado + 55;
			break;
		}
		numeroDigitado /= 16;
	}
	return i;
}
int convertOctal(int numeroDigitado, char *string){
	int i;
	for(i=0; ;i++){
		string[i] = numeroDigitado%8 + 48;
		if(numeroDigitado < 8)
			break;
		numeroDigitado /= 8;
	}
	return i;
}
void apresentarInvertido(int strlen, char *string){
	int i;
	for(i = strlen; i>=0; i--)
		putchar(string[i]);
	putchar('\n');
}
