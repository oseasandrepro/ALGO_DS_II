#include <stdio.h>
#include <string.h>

#define SIZE 10001
int U[SIZE];
int A[SIZE];
int R[SIZE];

void arranjo(int* A, int N, int K, int d, int* R, int* U);

int main(void)
{
	int n, k;
	scanf("%d %d", &n, &k);
	for( int i = 1; i<=n; i++)
		scanf("%d", &A[i]);
		
	memset(U, 0, sizeof(U));
	arranjo(A, n, k, 0, R, U);
}

void arranjo(int* A, int N, int K, int d, int* R, int* U)
{
	if( d == K)
	{
		for( int i = 1; i<=d; i++){
			printf("%d ", A[R[i]]);
		}
		printf("\n");
	}
	else
	{
		for( int i = 1; i<=N; i++)
		{
			if( !U[i] )
			{
				R[d+1] = i;
				U[i] = 1;
				arranjo(A, N, K, d+1, R, U);
				U[i] = 0;	
			}
		}
	}
}
