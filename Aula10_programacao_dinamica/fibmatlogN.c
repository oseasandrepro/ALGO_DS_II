#include <stdio.h>
#include <string.h>

#define SIZE 2

void expMatRec(long double M[SIZE][SIZE], int n);
void prodMat( long double A[SIZE][SIZE], long double B[SIZE][SIZE]);
void printmat(long double B[SIZE][SIZE]);
long double fib(int n);

int main(void)
{
	int x;
	scanf("%d", &x);
	
	printf("fib:\n");
	for( int i = 1; i<=x; i++)
		printf("%0.LG\n", fib(i) );
		
	printf("\n");
	
	return 0;
}

//Recebe as matrizes A e B efetua o produto e armazena em B
void prodMat(long double A[SIZE][SIZE], long double B[SIZE][SIZE])
{
	long double aux[SIZE][SIZE];
	aux[0][0] = (A[0][0]*B[0][0]) + (A[0][1]*B[1][0]);
	aux[0][1] = (A[0][0]*B[0][1]) + (A[0][1]*B[1][1]);
	
	aux[1][0] = (A[1][0]*B[0][0]) + (A[1][1]*B[1][0]);
	aux[1][1] = (A[1][0]*B[0][1]) + (A[1][1]*B[1][1]);

	memcpy(B, aux, 4*sizeof(long double));
}

//Recebe a matriz M e o inteiro n, efeuta a potência M^n
void expMatRec(long double M[SIZE][SIZE], int n)
{
	if( n > 0)
	{
		long double N[SIZE][SIZE];
		if( n%2 == 0)
		{	
			memcpy(N, M, 4*sizeof(long double));
			
			expMatRec(N, n/2);
			prodMat(N,N);
			
			memcpy( M, N, 4*sizeof(long double));
		}
		else
		{
			memcpy(N, M, 4*sizeof(long double));
			expMatRec(N, (n-1)/2);
			
			prodMat(N,N);
			prodMat(M,N);
			
			memcpy(M, N, 4*sizeof( long double));
		}
	}
	else
	{
		long double R[SIZE][SIZE] = {	{1.0, 0.0}, 
						{0.0, 1.0} };
		memcpy(M, R, 4*sizeof(long double));
	}
}

long double fib(int n)
{
	long double R[SIZE][SIZE];
	long double M[SIZE][SIZE] = {	{1.0, 1.0}, 
					{1.0, 0.0} };
	memcpy(R, M, 4*sizeof(long double));
	
	expMatRec(R, n-2);
	
	return (R[0][0] + R[0][1]);
}

void printmat(long double B[SIZE][SIZE])
{
	printf("------------------\n");
	for( int i = 0; i<SIZE; i++)
	{
		for( int j = 0; j<SIZE; j++){
			printf("%4Lf", B[i][j]);
		}
		printf("\n");
	}	
	printf("------------------\n");
}
