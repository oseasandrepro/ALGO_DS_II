#include <stdio.h>

#define SIZE 100

double media(double* V, int N);

int main(void)
{
	double vetor[SIZE];
	int n, i;
	
	scanf("%d", &n);
	for( i = 0; i<n; i++){
		scanf("%lf", &vetor[i]);
	}
	printf("%.3f\n", media(vetor, n) );
	return 0;
}

double media(double* V, int N)
{
	if( N==1)
		return V[N-1];
	else
		return media(V,N-1)*(N-1)/N + V[N-1]/N;
}
