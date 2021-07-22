#include <stdio.h>

#define SIZE 5

int moedas[SIZE] = {1, 5, 10, 25, 50};

int numTrocos(int T, int M[SIZE], int N);

int main(void)
{
	printf("%d\n", numTrocos(11, moedas, SIZE) );
	
	return 0;
}

int numTrocos(int T, int M[SIZE], int N)
{
	if( T > 0)
	{
		int i;
		int m = 0;
		for( i = N-1; i>=0; i--){
			if( T>=M[i] )
				m += numTrocos(T-M[i], M, i+1);
		}
		return m;
			
	}
	else
		return 1;
}
