#include <stdio.h>
#include <string.h>

#define SIZE 1001

int U[SIZE];
int R[SIZE];
int A[SIZE];

void cSoma(int* A, int N, int K, int S, int d, int* R, int* U);

int main(void)
{
	int n, k;
	memset(U, 0, sizeof(U));
	
	scanf("%d%d", &n, &k);
	for( int i = 1; i<=n; i++)
		scanf("%d", &A[i]);
		
	cSoma(A, n, k, 0, 0, R, U);
}

void cSoma(int* A, int N, int K, int S, int d, int* R, int* U)
{
	if( S == K)
	{
		printf("{ ");
		for( int i = 1; i<=d; i++)
			printf("%d ", A[R[i]]);
		printf("}\n");
	}
	else
	{
		for( int i = 1; i<=N; i++)
		{
			if(!U[i] && R[d]<i)
			{
				R[d+1] = i; U[i] = 1;
				cSoma(A, N, K, S+A[i], d+1, R, U);
				U[i] = 0;
			}
		}
	}
}
