#include <stdio.h>

int R[101];

void escreveBin(int k, int d, int* R);

int main(void)
{
	escreveBin(3, 0, R);
	return 0;
}

void escreveBin(int k, int d, int* R)
{
	if( d == k)
	{
		for( int i = 1; i<=k; i++)
			printf("%d", R[i]);
		printf("\n");
	}
	else
	{
		for( int i = 0; i<=1; i++ )
		{
			R[d+1] = i;
			escreveBin(k, d+1, R);
		}
	}
}
