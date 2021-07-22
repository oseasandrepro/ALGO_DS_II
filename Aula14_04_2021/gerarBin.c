#include <stdio.h>
#define KN	5
void GerarBin(int K, int d, int *R);

int main(void)
{
	int R[100];
	GerarBin(KN, -1, R);
	return 0;
}

void GerarBin(int K, int d, int *R)
{
	if( d == K-1)
	{
		for( int i = 0; i<K; i++)
			printf("%d", R[i]);
		printf("\n");
	}
	else
	{
		for( int i = 0; i<2; i++)
		{
			R[d+1] = i;
			GerarBin(K, d+1, R);
		}
	}
}
