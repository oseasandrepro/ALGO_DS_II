#include <stdio.h>
#include <string.h>

#define SIZE 2

void expMat(long double M[SIZE][SIZE], int n);
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
void expMat(long double M[SIZE][SIZE], int n)
{
	int i;
	long double R[SIZE][SIZE] = {	{1.0, 0.0}, 
					{0.0, 1.0} };
	
	for( i = 0; i<n; i++)
		prodMat(M, R);
		
	memcpy(M, R, 4*sizeof(long double));
}

long double fib(int n)
{
	long double R[SIZE][SIZE];
	long double M[SIZE][SIZE] = {	{1.0, 1.0}, 
					{1.0, 0.0} };
	memcpy(R, M, 4*sizeof(long double));
	
	expMat(R, n-2);
	
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
