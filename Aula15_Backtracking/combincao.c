#include <stdio.h>

#define TAM 6
#define SIZE 101
int U[SIZE];
int R[SIZE];

void combinacao(int N, int K, char* A, int d, int* R);

int main(void)
{
	char A[TAM] = {-1, '$', '#', '(', '=', '&'};
	
	memset(U, 0, sizeof(U));
	
	combinacao(TAM-1, 3, A, 0, R);
	
	return 0;
}

void combinacao(int N, int K, char* A, int d, int* R)
{
	if( d == K)
	{
		for( int i = 1; i<=K; i++)
		{
			int k = R[i];
			printf("%2c", A[k]);
		}
		printf("\n");
	}
	else
	{
		for( int i = 1; i<=N; i++)
		{
			if( !U[i] && (R[d]<i || d==0) )
			{
				R[d+1] = i;
				U[i] = 1;
				combinacao(N, K, A, d+1, R);
				U[i] = 0;
			}
		}
	}
}

