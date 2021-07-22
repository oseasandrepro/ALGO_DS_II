#include <stdio.h>

#define SIZE 5

int somaAlternante(int *A, int N);

int main(void)
{
	int A[SIZE] = {1, 2, 4, 1, 5};
	printf("soma: %d\n", somaAlternante(A,SIZE) );
	
	return 0;
}

int somaAlternante(int *A, int N)
{
	//Assume N>=1
	//retornar (-1)^(i-1)*A[i]+ ... + (-1)^(i-1)*A[N-1]
	//i = 0, 1, 2, 3, ......, N-1
	if( N==1)
		return A[N-1];
	else
	{
		int a;
		if( (N%2)==0 )
			a = A[N-1]*(-1);
		else
			a = A[N-1];
			
		return (somaAlternante(A,N-1)+a);
	}
}

