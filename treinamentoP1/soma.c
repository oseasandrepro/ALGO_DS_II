#include <stdio.h>

#define SIZE 100
int A[SIZE];

int soma(int* A, int N);
int soma1(int* A, int ini, int fim);

int main(void)
{
	int x,n;
	
	scanf("%d", &n);
	for( int i = 0; i<n; i++)
		scanf("%d", &A[i]);
	
	//printf("soma: %d\n", soma1(A,0,n-1));
	printf("soma: %d\n", soma(A,n));
	return 0;
}

int soma(int* A, int N)
{
	if( N == 0)
		return 0;
	else
	{
		return A[N-1] + soma(A,N-1);
	}
}

int soma1(int* A, int ini, int fim)
{
	if( !(ini<=fim))
		return 0;
	else
	{
		int meio = (ini+fim+1)/2;
		return A[meio] + soma1(A,ini,meio-1) + soma1(A,meio+1,fim);
	}
}
