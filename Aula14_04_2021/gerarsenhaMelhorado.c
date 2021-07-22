#include <stdio.h>
#include <string.h>

#define MAX_LENGTH	5
#define MIN_LENGTH	3

void gerarSenha(int m, int M, int d, char* R, int ma, int mi, int nu);


int main(void)
{
	char R[MAX_LENGTH];
	gerarSenha(MIN_LENGTH, MAX_LENGTH, -1, R, 0, 0, 0);
	return 0;
}

void gerarSenha(int m, int M, int d, char* R, int ma, int mi, int nu)
{
	if( d<=M)
	{
		if( ma && mi && nu)
		{
			for(int i = 0; i<d; i++)
				printf("%c", R[i]);
			printf("\n");
		}
		for( int i = 'a'; i<='z'; i++)
		{
			R[d+1] = i;
			gerarSenha(m, M, d+1, R, ma, 1, nu);
		}
		for( int i = 'A'; i<='Z'; i++)
		{
			R[d+1] = i;
			gerarSenha(m, M, d+1, R, 1, mi, nu);
		}
		for( int i = '0'; i<='9'; i++)
		{
			R[d+1] = i;
			gerarSenha(m, M, d+1, R, ma, mi, 1);
		}
	}
}
