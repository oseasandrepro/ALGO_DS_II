#include <stdio.h>

int L[100];
int C[100];

/*unir duas listas ordenadas*/
void merge(int *V, int ini, int m, int fim);

/* assume fim-inicio+1 >= 0
   garante: V[ini...fim] ordenado
*/
void mergeSort(int *V, int ini, int fim);


int main(void)
{
	
	int n, i, x;
	
	printf(":");
	scanf("%d", &n);
	printf("[...] = ");
	for( i = 0; i<n; i++)
	{
		scanf("%d", &x);
		L[i] = x;
	}
	
	mergeSort(L, 0, n-1);
	
	printf("vetor ordenaddo:\n");
	for(i = 0; i<n; i++)
		printf("%4d", L[i]);
	printf("\n");
	
	return 0;
}


void merge(int *V, int ini, int m, int fim)
{
	int i, j, k;
	i = ini; j = m+1;
	for( k = ini; k<fim+1; k++ )
	{
		if( (j>fim) || (i<=m && V[i]<V[j]))
		{
			C[k] = V[i];
			i = i + 1;
		}
		else
		{
			C[k] = V[j];
			j = j + 1;
		}
	}
	for( k = ini; k<fim+1; k++)
		V[k] = C[k];
}

void mergeSort(int *V, int ini, int fim)
{
	if( (fim - ini + 1) > 1)
	{
		int m = (ini+fim)/2;
		mergeSort(V, ini, m);
		mergeSort(V, m+1, fim);
		merge(V, ini, m, fim);
	}
		
}

