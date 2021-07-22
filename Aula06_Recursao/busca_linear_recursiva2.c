#include <stdio.h>

/* x pode estar ou não na lista
   Assume N>=0
   retorna a posição(indice) de x em L se x pertecne a L, 
   se não retorna 0.
*/
int busca(int L[], int N, int x);

int main(void)
{
	int L[100];
	int n, i, x;
	
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
	printf("%d\n", busca(L, n, x) );
	
	return 0;
}

int busca(int L[], int N, int x)
{
	if( N==0)
		return 0;
	else
	{
		int p = busca(L, N-1, x);
		if ( p!= 0)
			return p;
		else if( L[N] == x)
			return N;
		else
			return 0;
	}
}
