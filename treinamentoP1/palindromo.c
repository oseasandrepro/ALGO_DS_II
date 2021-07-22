#include <stdio.h>
#include <string.h>

#define SIZE 150

int palindromo(char* string, int ini, int fim);

int main(void)
{
	int flag, inicio, fim;
	char str[SIZE];
	
	scanf("%s", str);
	
	inicio = 0;
	fim = strlen(str)-1;
	
	flag = 0;
	flag = palindromo(str, inicio, fim);
	
	(flag==0)?printf("Nao He palindromo\n"):printf("He palndromo!\n");
	
	return 0;
}

int palindromo(char* string, int ini, int fim)
{
	if( (fim-ini+1) == 1)
		return 1;
	else{
		return ( palindromo(string, ini+1, fim-1) && (string[ini]==string[fim]) );
	}
}
