//Gerar todos subconjuntos de 1 a n
#include <stdio.h>
#include <string.h>
#define N 6

void gerarSubconjuntos(int n, int d, int *R);

int main(void)
{
	int R[N];
	memset(R, 0, sizeof(R));
	gerarSubconjuntos(N, 0, R);
	
	return 0;
}

void gerarSubconjuntos(int n, int d, int *R)
{
	if( d == N-1)
	{
		printf("{");
		for( int i = 1; i<=d; i++){
			if( R[i] ){
				if(i==d)
					printf("%d", i);
				else
					printf("%d,", i);
			}
		}
		printf("}\n");
	}
	else
	{
		R[d+1] = 1;
		gerarSubconjuntos(N, d+1, R);
		R[d+1] = 0;
		gerarSubconjuntos(N, d+1, R);
		
	}
}
