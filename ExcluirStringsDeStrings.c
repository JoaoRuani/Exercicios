#include <stdio.h>

void StrDelStr(char *s1, char *s2);
int StrLen(char *s1);

int main(void){
	char stringCompleta[] = "sai decasa";
	char retirar[] = "a";
	StrDelStr(stringCompleta, retirar);
	int i;
	puts(stringCompleta);
	return 0;
}
void StrDelStr(char *s1, char *s2){
	int i, j, x, k, l;
	for(i = 0; i<= StrLen(s1) - StrLen(s2); i++){
		if(s1[i] == s2[0]){
			for(j = i, x = 0; j<StrLen(s2)+i; j++, x++){
				if(s1[j]!= s2[x])
					break;
			}
			if(x == StrLen(s2)){
				for(k = i, l = j; l<=StrLen(s1); k++, l++)
					s1[k] = s1[l];
			}
		}
	}
}
int StrLen(char *s1){
	int i;
	for(i = 0; s1[i]!='\0'; i++);
	return i;
}

