#include <stdio.h>
#include <string.h>

void cript(char string[]);
void descript(char string[]);


main(){
	char string[100];
	printf("Digite uma frase: ");
	gets(string);
	cript(string);
	puts(string);
	descript(string);
	puts(string);
	
}
void cript(char string[]){
	int i;
	for(i=0; i<strlen(string); i++)
		if(!(string[i] == ' '))
			string[i] += 3;
}
void descript(char string[]){
	int i;
	for(i=0; i<strlen(string); i++)
		if(!(string[i] == ' '))
			string[i] -= 3;
	
}
