#include <stdio.h>

#define SIZE 6

int M[SIZE] = {1, 5, 10, 25, 50, 100};

int moedas(int M[SIZE], int T, int N);

int main(void)
{
	int x;
	
	scanf("%d", &x);
	
	printf("quantidade minina de moedas: %d\n",moedas(M,x, SIZE));
	return 0;
}

int moedas(int M[SIZE], int T, int N)
{
	if( N==0 )
		return 0;
	else
	{
		if( T == 0)
			return 0;
		else if(T>=M[N-1] )
			return (T/M[N-1]) + moedas(M, T%M[N-1], N-1);
		else
			return moedas(M, T, N-1);
	}
}
