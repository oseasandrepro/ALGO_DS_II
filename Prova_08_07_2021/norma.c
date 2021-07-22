#include <stdio.h>
#include <math.h>

#define SIZE 5

double norma(double *V, int N);

int main(void)
{
	double V[SIZE] = {1, 2, 4, 1, 5};
	printf("Norma: %.2f\n", norma(V,SIZE));
	return 0;
}

double norma(double *V, int N)
{
	//Assume N>=1
	//retornar a raiz quadrada de V[0]^2+V[1]^2+...+V[N-1]
	if( N==1)
		return sqrt(V[N-1]*V[N-1]);
	else
	{
		double k;
		k = norma(V, N-1);
		return sqrt((k*k)+(V[N-1]*V[N-1]));
	}
}
