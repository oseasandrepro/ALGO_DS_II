#include <stdio.h>

int fibpd(int n);

int main(void)
{
	int x;
	scanf("%d", &x);
	printf("%d-esimo fibonacci: %d\n", x, fibpd(x));
	
	return 0;
}

int fibpd(int n)
{
	int T[n+1];
	int i;
	
	T[1] = 1; T[2] = 1;
	for( i = 3; i<=n; i++)
		T[i] = T[i-1] + T[i-2];
	return T[n];
}
