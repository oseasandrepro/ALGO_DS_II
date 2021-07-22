#include <stdio.h>

#define SIZE 101
int R[SIZE];

void dados(int N, int M, int d, int* R);

int main(void)
{
	dados(3, 2, 0, R);
	return 0;
}

void dados(int N, int M, int d, int* R)
{
	if( d == N)
	{
		for( int i = 1; i<=N; i++)
		{
			printf("%d", R[i]);
		}
		printf("\n");
	}
	else
	{
		for( int i = 1; i<=M; i++)
		{
			R[d+1] = i;
			dados(N, M, d+1, R);
		}
	}
}
