#include <stdio.h>
#include <string.h>

#define MAX_LENGTH	5
#define MIN_LENGTH	3

#define SIZE 62
char caracteres[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

int ehValida(int m, int M,int d, char* R);
void gerarSenha(int m, int M, int d, char* R);


int main(void)
{
	char R[MAX_LENGTH];
	gerarSenha(MIN_LENGTH, MAX_LENGTH, -1, R);
	return 0;
}

int ehValida(int m, int M, int d, char* R)
{
	int resposta;
	resposta = 0;
	
	if( d>=m && d<=M )
	{
		int ma,mi,nu;
		ma = mi = nu = 0;
		for( int i = 0; i<d; i++)
		{
			if( R[i]>='a' && R[i]<='z')
				mi = 1;
			if( R[i]>='A' && R[i]<='Z')
				ma = 1;
			if( R[i]>='0' && R[i]<='9')
				nu = 1;
		}
		resposta = ma && mi && nu;
	}
	
	return resposta;
}

void gerarSenha(int m, int M, int d, char* R)
{
	if( d<=M)
	{
		if( ehValida(m, M, d, R) )
		{
			for(int i = 0; i<d; i++)
				printf("%c", R[i]);
			printf("\n");
		}
		for( int i = 0; i<SIZE; i++)
		{
			R[d+1] = caracteres[i];
			gerarSenha(m, M, d+1, R);
		}
	}
}
