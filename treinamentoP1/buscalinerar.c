#include <stdio.h>

#define SIZE 4
int L[SIZE] = {3, 2, 5, 7};

int busca(int *L, int N, int x);

int main(void)
{
	int x;
	scanf("%d", &x);
	printf("%d\n", busca(L, SIZE, x));
	
	return 0;
}

int busca(int *L, int N, int x)
{
	if( L[N-1] == x)
		return N-1;
	else 
		busca(L,N-1, x);
}
