#include <stdio.h>

#define N 5

//retorna média aritimentica de A1,A2,...,An
//assume n>=1
float med(int n, float A[]);

int main(void)
{
	float notas[] = {5, 6, 7, 8, 7};
	
	printf("%.3f\n", med(N, notas) );
	return 0;
}

float med(int n, float A[])
{
	if( n == 1)
		return A[n-1];
	else
		return med(n-1, A) * ((n-1.0)/n) + (A[n-1]/n);
}
