/* 
Exemplo de entrada:
4
6.0 7.0 4.0 5.0
2.0 2.0 3.0 3.0
*/
#include <stdio.h>

#define SIZE 100

double MP(double* A, double* P, int N);

int main(void)
{
	double A[SIZE];
	double P[SIZE];
	int n, i;
	
	scanf("%d", &n);
	for( i = 0; i<n; i++){
		scanf("%lf", &A[i]);
	}
	for( i = 0; i<n; i++){
		scanf("%lf", &P[i]);
	}
	printf("%.3f\n", MP(A, P, n) );
	return 0;
}

double MP(double* A, double* P, int N)
{
	if( N==1)
		return A[N-1];
	else
	{
		double S; S = 0;
		for( int i = 0; i<N; i++)
			S += P[i];
		printf("%.2f**\n", S);
		return MP(A, P, N-1) * (S-P[N-1])/S + (A[N-1]*P[N-1])/S;
	}	
}
