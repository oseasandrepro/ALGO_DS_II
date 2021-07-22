#include <stdio.h>
#include <string.h>

#define	SIZE 101
#define	TAM 4

int R[SIZE];
int U[SIZE];

void permutacoes(int N, int* A, int d, int* R);

int main(void)
{

	int A[TAM] ={0, 2, 3, 4};
	memset(U, 0, sizeof(U));
	permutacoes(TAM-1, A, 0, R);
	return 0;
}

void permutacoes(int N, int* A, int d, int* R)
{
	if( d == N)
	{
		for( int i = 1; i<=N; i++)
		{
			int k = R[i];
			printf("%2d",A[k]); 
		}
		printf("\n");
	}
	else
	{
		for( int i = 1; i<=N; i++)
		{
			if( !U[i] )
			{
				U[i] = 1;
				R[d+1] = i;
				permutacoes(N, A, d+1, R);
				U[i] = 0;
			}
		}
	}
}
