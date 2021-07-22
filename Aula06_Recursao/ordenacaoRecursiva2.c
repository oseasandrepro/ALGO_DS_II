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
		int maior = N-1;
		for( int i = 0; i<N; i++)
			if( L[i] > L[maior] )
				maior = i;
		if( maior != N-1){
			int aux = L[maior];
			L[maior] = L[N-1];
			L[N-1] = aux;
		}
			
		ordenacaoRecursiva(L, N-1);
	}
}
