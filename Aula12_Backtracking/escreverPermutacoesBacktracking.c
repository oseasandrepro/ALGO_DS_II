#include <stdio.h>

#define TAM 5

int vetor[TAM] = {-1, 1, 3, 5, 4};
int R[TAM];

void escreverPermutacoes(int* V, int N, int i,int* R);

int main(void)
{
	
	escreverPermutacoes(vetor, TAM-1, 0, R);
	
	printf("\n");
	return 0;
}

void escreverPermutacoes(int *V, int N, int i, int *R)
{
	if( i<N )
	{
		for( int j = 1; j<=N; j++)
		{
			int ediferente = 1;
			for(int z = 1; z<=i; z++)
			{
				if(j == R[z] ){
					ediferente = 0;
					break;
				}
			}
			if( ediferente ){
				R[i+1] = j;
				escreverPermutacoes(V, N, i+1, R);
			}
		}
	}
	else
	{
		for( int j = 1; j<=N; j++){
			int index = R[j];
			printf("%d ", V[index]);
		}
		printf("\n");
	}
}
