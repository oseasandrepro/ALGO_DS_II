#include <stdio.h>

long long int fat(long long int n);

int main(void)
{
	long long int n;
	long long int fatorial = 1;
	
	printf("n:");
	scanf("%lld", &n);
	
	fatorial = fat(n);
	printf("Fatorial: %lld\n", fatorial);
}

long long int fat(long long int n)
{
	if( n<=1 )
		return 1;
	else
		return n*(n-1)*fat(n-2);
		
}
