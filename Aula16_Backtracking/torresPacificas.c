#include <stdio.h>
#include <string.h>

#define SIZE 9
char tabuleiro[SIZE][SIZE];

int R[101];
int U[101];

void exibir_tabuleiro(int *R);
void torrePacifica(int d, int* R, int* U);

int main(void)
{
	memset(U, 0, sizeof(U) );
	
	torrePacifica(0, R, U);
	return 0;
}

void torrePacifica(int d, int* R, int* U)
{
	if( d == 8)
	{
		exibir_tabuleiro(R);
		printf("\n");
	}
	else
	{
		for( int i = 1; i<SIZE; i++)
		{
			if( !U[i] )
			{
				R[d+1] = i;
				U[i] = 1;
				torrePacifica(d+1, R, U);
				U[i] = 0;
				
			}
		}
	}
}

void exibir_tabuleiro(int *R)
{
	memset(tabuleiro, ' ', sizeof(tabuleiro));
	for( int i = 1; i<SIZE; i++)
		tabuleiro[i][R[i]] = 'T';
	
	for( int i = 1; i<SIZE; i++)
	{
		printf("|");
		for( int j = 1; j<SIZE; j++)
		{
			printf("%c",tabuleiro[i][j]);
		}
		printf("|");
		printf("\n");	
	}
}
