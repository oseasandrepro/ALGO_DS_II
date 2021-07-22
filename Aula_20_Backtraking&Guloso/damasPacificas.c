#include <stdio.h>
#include <string.h>

#define SIZE 1001

int R[SIZE];

void damasPacificas(int N, int d, int* R);
void exibir_tabuleiro(int *R, int N);

int main(void)
{
	int n;
	memset(R,0, sizeof(R));
	
	scanf("%d", &n);
	damasPacificas(n, 0, R);
	
	return 0;
}

void damasPacificas(int N, int d, int* R)
{
	if( d == N)
	{
		exibir_tabuleiro(R, N);	
	}
	else
	{
		for( int i = 1; i<=N; i++)
		{
			int pode = 1;
			for( int x = 0; x<d; x++)
			{
				int c1 = i-(x+1);
				int c2 = i+(x+1);
				pode = pode && (c1<=0 || R[d-x]!=c1) && (R[d-x] != i) &&  (c2>N || R[d-x]!=c2);
				if( !pode )
					break;
			}
			if( pode )
			{
				R[d+1] = i;
				damasPacificas(N, d+1, R);
			}
		}
	}
}

void exibir_tabuleiro(int *R, int N)
{
	for( int i = 1; i<=N; i++)
	{
		for( int j = 1; j<=N; j++)
		{
			printf("|");
			(R[i] == j)?printf("D"):printf(" ");
			
		}
		printf("|\n");
	}
	printf("------------\n");

}
