#include <stdio.h>

/* assume: L[1...N] é ordenado(ascendente), 
   inicio+fim+1 = N>=0
   retorna a posicao(indice) de x na lista
   se nao encontrar x retorna 0
*/
int buscaBinaria(int L[], int ini, int fim, int x);

int main(void)
{
	int L[100];
	int n, i, x;
	
	printf("%d\n", (int)2.5);
	printf(":");
	scanf("%d", &n);
	printf("[...] = ");
	for( i = 0; i<n; i++)
	{
		scanf("%d", &x);
		L[i] = x;
	}
	
	printf(":");
	scanf("%d", &x);
	printf("%d\n", buscaBinaria(L, 0, n-1, x) );
	
	return 0;
}

int buscaBinaria(int L[], int ini, int fim, int x)
{
	if( (fim - ini + 1) == 0 )
		return 0;
	else
	{
		int m = (ini+fim)/2;
		if( L[m] == x)
			return m;
		else if( L[m] > x)
			return buscaBinaria(L, ini, m-1, x);
		else
			return buscaBinaria(L, m+1, fim, x);
	}
}
