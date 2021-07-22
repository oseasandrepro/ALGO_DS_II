#include <stdio.h>


float medPonderada(float *A, float *P, float S, int N);
/*
	Retorna: a media aritimetica ponderada dos N elementos do vetor A
	usa P como vetor dos pesos e S como a soma dos N pesos. 
	para soma dos N-1 pesos é só fazer: S-P[N]
	Assume: N>=1
*/

int main(void)
{
	float A[100];
	float P[100];
	int n; int s;
	
	while( 1 )
	{
		scanf("%d", &n);
		if(n==0)
			break;
		for( int i = 1; i<=n; i++)
			scanf("%f", &A[i]);
		for( int i = 1; i<=n; i++)
			scanf("%f", &P[i]);
		s = 0;
		for( int i = 1; i<=n; i++)
			s += P[i];
		
		
		printf("Média aritimetica Ponderada: %.2f\n", medPonderada(A,P,s,n) );
		
	}
	return 0;
}

float medPonderada(float *A, float *P, float S, int N)
{
	if( N == 1)
		return (P[N]*A[N])/S;
	else
		return medPonderada(A,P, S-P[N], N-1) * (S-P[N])/S + (P[N]*A[N])/S;
}
