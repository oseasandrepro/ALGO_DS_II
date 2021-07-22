#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>

#define	MAX(a, b) ( ((a)>(b))?(a):(b))

#define SIZE 101
#define BLOCKED

int grade[SIZE][SIZE];
int T[SIZE][SIZE];

void construirCenario(int , int );
int maxcoin_recursao(int M[][SIZE], int N, int i, int j);

int main(void)
{
	int max;
	int N;
	scanf("%d", &N);
	srand(time(NULL));
	
	construirCenario(N, rand()%(N+1) );
	
	max = maxcoin_recursao(grade, N, 1, 1);
	if( max<0)
		printf("%d: Nenhum\n", max);
	else
		printf("MAX COIN: %d\n", max);
		
	return 0;
}

int maxcoin_recursao(int M[][SIZE], int N, int i, int j)
{
	if( i<=N && j<=N)
	{
		int s1, s2;
		s1 = maxcoin_recursao(M, N, i, j+1);
		s2 = maxcoin_recursao(M, N, i+1, j);
		
		if( M[i][j] == -1 )
		{
			return INT_MAX;
		}
		else{
			return ( MAX(s1,s2)+M[i][j] );
		}
	}
	else
		return INT_MAX;
}


void construirCenario(int N, int k)
{
	memset(grade, 0, sizeof(grade));
	srand(time(NULL));
	int i,j;
	for( int i = 1; i<=k; i++){
		i = (rand()%N)+1;
		rand();
		j = (rand()%N)+1;
		grade[i][j] = -1;
		
	}
	
	for( int i = 1; i<=N; i++)
	{
		for( int j = 1; j<=N; j++)
		{
			if( grade[i][j] != -1)
				grade[i][j] = rand()%(N+1);
		}
	}
	
	for( int i = 1; i<=N; i++)
	{
		for( int j = 1; j<=N; j++)
		{
			(grade[i][j]==-1)?printf("%2c",'X'):printf("%2d", grade[i][j]);
		}
		printf("\n");
	}
}
