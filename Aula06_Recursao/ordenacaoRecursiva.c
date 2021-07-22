#include <stdio.h>

void ordenacaoRecursiva(int L[], int N);

int main(void)
{
	int vetor[100];
	int n, i, x;
	
	printf(":");
	scanf("%d", &n);
	printf("[...] = ");
	for( i = 0; i<n; i++)
	{
		scanf("%d", &x);
		vetor[i] = x;
	}
	
	ordenacaoRecursiva(vetor, n);
	for( i = 0; i<n; i++)
		printf("%4d", vetor[i]);
	printf("\n");
	
	
	
	return 0;
}

void ordenacaoRecursiva(int L[], int N)
{
	if( N>0)
	{
		ordenacaoRecursiva(L, N-1);
		int i = N-1;
		while( i>0 && L[i-1] > L[i])
		{
			int aux = L[i];
			L[i] = L[i-1];
			L[i-1] = aux;
			i = i -1;
		}
	}
}
