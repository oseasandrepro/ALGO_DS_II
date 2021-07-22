#include <stdio.h>

/* supõe x pertence a L
   retorna a posição(indice) de x em L 
*/
int busca(int L[], int n, int x);

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

int busca(int L[], int n, int x)
{
	if( L[n] == x)
		return n;
	else
		return busca(L, n-1, x);
}
