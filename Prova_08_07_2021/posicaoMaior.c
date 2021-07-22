#include <stdio.h>

#define SIZE 5

int posicaoMaior(int *A, int N);

int main(void)
{
	int A[SIZE] = {3, 13, 8, 12, 1};
	printf("posicao do maior: %d\n", posicaoMaior(A,SIZE));
	
	return 0;
}

int posicaoMaior(int *A, int N)
{
	//Assume N>=1
	//retornar a posicao do maior elemtneo entre
	//os N primeiros elemnetos do Vetor A
	if( N == 1)
		return N;
	else
	{
		int p;
		p = posicaoMaior(A, N-1);
		if( A[p] > A[N-1])
			return p;
		else
			return N-1;
	}
}
