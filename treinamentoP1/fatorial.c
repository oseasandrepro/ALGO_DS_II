#include <stdio.h>

int fat(int n);

int main(void)
{
	int x;
	scanf("%d", &x);
	printf("fatorial: %d\n", fat(x));
	return 0;
}

int fat(int n)
{
	if( n==0 || n==1)
	{
		return 1;
	}
	else
	{
		return fat(n-1)*n;
	}
}
