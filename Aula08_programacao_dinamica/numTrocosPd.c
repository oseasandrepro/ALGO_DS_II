#include <stdio.h>

#define SIZE 5

int M[SIZE] = {1, 5, 10, 25, 50};

int numTrocosPd(int T, int M[5], int N);

int main(void)
{
	int troco;
	scanf("%d", &troco);
	printf("formas de dar o troco: %d\n", numTrocosPd(troco,M,SIZE) );
	
	return 0;
}

int numTrocosPd(int T, int M[5], int N)
{
	int C[T+1][N];
	int i, j, z;
	for( i = 0; i<N; i++)
		C[0][i] = 1;
		
	for( i = 1; i<=T; i++)
	{
		for( j = 0; j<N; j++)
		{
			int m = 0;
			for( z = j; z>=0; z--)
			{
				if( i>=M[z] )
					m = m + C[i-M[z]][z];
			}
			C[i][j] = m;
		}
	}
	return  C[T][N-1];
}
