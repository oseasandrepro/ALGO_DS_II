#include <stdio.h>

int Hepalindromo(char* str, int ini, int fim);
/* Assume fim-ini+1>=0
   retorna 1 se A[ini...fim] representa um palindromo */

int main(void)
{
	char linha[150];
	int ini,fim;
	int r=0;
	ini = 0;
	
	scanf("%s", linha);
	
	fim = strlen(linha)-1;
	r = Hepalindromo(linha, ini, fim);
	
	(r==0)?printf("Nao he palindromo\n"):printf("He palindromo\n");
	
	return 0;
}

int Hepalindromo(char* str, int ini, int fim)
{
	if( ini>=fim )
		return 1;
	else
		return ((str[ini] == str[fim]) && Hepalindromo(str, ini+1, fim-1) );
}
