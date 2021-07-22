#include <stdio.h>
#include <stdlib.h>

#define N 7

void swap(int* , int*); 
//trocar o valor da primeira variavel pelo valor da segunda variavel
int ObterPosicaoDoMaximo(int V[], int n);
//retornar a posicao do maior elemento entre os n primeiros elementos do vetor
void ordenar(int V[], int n);
//ordenar o vetor

int	ObterNumeroDeLinhasDoarquivo(char* filename);
int*	ObterNinteirosdoarquivoPorLinha(char* filename, int n);

int main(void)
{
	int n = ObterNumeroDeLinhasDoarquivo("numeros.txt");
	int* vetor = ObterNinteirosdoarquivoPorLinha("numeros.txt", n);
	int i;
	
	printf("antes:\n");
	for(i = 0; i<n; i++)
		printf("%d\n", vetor[i]);
		
	ordenar(vetor, n);
	printf("\ndepois:\n");	
	for(i = 0; i<n; i++)
		printf("%4d\n", vetor[i]);
	printf("\n");
	
	free(vetor);
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

int	ObterNumeroDeLinhasDoarquivo(char* filename)
{
	FILE* arquivo = fopen(filename, "r");
	int cont = 0; 
	int x;
	while( fscanf(arquivo,"%d",&x) > 0)
		cont++;
	fclose(arquivo);
	
	return cont;
}
int*	ObterNinteirosdoarquivoPorLinha(char* filename, int n)
{
	FILE* arquivo = fopen(filename, "r");
	int* vetor = (int*)malloc(sizeof(int)*n);
	int i;
	for( i= 0; i<n; i++){
		fscanf(arquivo,"%d",&vetor[i]);
	}
	
	fclose(arquivo);
	return vetor;
}

