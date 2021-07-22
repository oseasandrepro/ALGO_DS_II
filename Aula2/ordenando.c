#include <stdio.h>

#define N 7

void swap(int* , int*); 
//trocar o valor da primeira variavel pelo valor da segunda variavel
int ObterPosicaoDoMaximo(int V[], int n);
//retornar a posicao do maior elemento entre os n primeiros elementos do vetor
void ordenar(int V[], int n);
//ordenar o vetor

int main(void)
{
	int vetor[N] = {11, 3, 2, 7, 5, 9, 5};
	int i;
	
	printf("antes:");
	for(i = 0; i<N; i++)
		printf("%4d", vetor[i]);
		
	ordenar(vetor, N);
	printf("\n\ndepois:");	
	for(i = 0; i<N; i++)
		printf("%4d", vetor[i]);
	printf("\n");
		
	return 0;
}

void swap(int * Pvar1, int* Pvar2)
{
	int aux = *Pvar1;
	*Pvar1 = *Pvar2;
	*Pvar2 = aux;
}

int ObterPosicaoDoMaximo(int V[], int n)
{
	int posicaomax = 0;
	int i;
	for(i = 0; i<n; i++){
		if(V[i] > V[posicaomax])
			posicaomax = i;
	}
	return posicaomax;
}

void ordenar(int V[], int n)
{
	int auxn, posicaomax;
	for(auxn = n; auxn>=2; auxn--)
	{
		posicaomax = ObterPosicaoDoMaximo(V, auxn);
		if( V[auxn-1] != V[posicaomax])
			swap(&V[auxn-1], &V[posicaomax] );
	}
}
