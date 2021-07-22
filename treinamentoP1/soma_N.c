#include <stdio.h>

int soma(int N);

int main(void)
{
	int n;
	scanf("%d", &n);
		
	printf("soma: %d\n", soma(n));
	return 0;
}

int soma(int N)
{
	if( N==1 )
		return 1;
	else
		return N + soma(N-1);
	return 0;
}
