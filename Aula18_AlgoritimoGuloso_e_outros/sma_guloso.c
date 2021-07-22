#include <stdio.h>
#include <math.h>
#include <limits.h>

#define SIZE 8005

int s[SIZE];
int e[SIZE];

void mergesort(int* e, int ini, int fim);
void merge(int* e, int ini, int m, int fim);

int sma_guloso(int *s, int *e, int N, int i, int j);

int main(void)
{
	int n;
	scanf("%d", &n);
	for( int i = 1; i<=n; i++)
		scanf("%d%d", &s[i], &e[i]);
	mergesort(e, 1, n);
	s[0] = e[0] = INT_MIN;
	s[n+1] = e[n+1] = INT_MAX;
	
	
	printf("%d\n", sma_guloso(s, e, n, 0, n+1) ); 
	return 0;
}

int sma_guloso(int *s, int *e, int N, int i, int j)
{
	
	for( int z = i+1; z<=j-1; z++)
		if( (e[i]<=s[z]) && (e[z]<=s[j]) )
			return 1 + sma_guloso(s, e, N, z, j);
	return 0;
}

void mergesort(int* e, int ini, int fim)
{
	if( fim-ini+1 > 1 )
	{
		int m = floorf((ini+fim)/2.0);
		mergesort(e, ini, m);
		mergesort(e, m+1, fim);
		merge(e, ini, m, fim);
	}
}
//order em paralelo s[] e e[]
void merge(int* e, int ini, int m, int fim)
{
	int i, j;
	int saux[SIZE];
	int eaux[SIZE];
	i = ini; j = m+1;
	for( int k = ini; k<=fim; k++)
	{
		if( (j>fim) || (i<= m && e[i]<e[j]) )
		{
			eaux[k] = e[i];
			saux[k] = s[i];
			i+=1;
		}
		else
		{
			eaux[k] = e[j];
			saux[k] = s[j];
			j+=1;
		}
	}
	for(int k = ini; k<=fim; k++)
	{
		 e[k] = eaux[k];
		 s[k] = saux[k];
	}
		
}
