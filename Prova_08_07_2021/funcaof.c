#include <stdio.h>

#define MIN(a,b) ( (a) < (b)) ? (a) : (b)
#define SIZE 10001

int A[SIZE];
int B[SIZE];
int T[SIZE][SIZE];

int f(int* A, int* B, int x, int y);

int main(void)
{
	int x, y, n;
	scanf("%d", &n);
	for( int i = 1; i<=n; i++)
		scanf("%d", &A[i]);
	for( int i = 1; i<=n; i++)
		scanf("%d", &B[i]);
	scanf("%d%d", &x, &y);
	
	printf("%d\n", f(A, B, x, y) );
	
	for( int i = 0; i<=x; i++)
	{
		for( int j = 0; j<=y; j++)
		{
			printf("%4d ", T[i][j]);
		}
		printf("\n");
	}
	return 0;
}

int f(int* A, int* B, int x, int y)
{
	for( int i = 1; i<=y; i++)
		T[0][i] = i;
		
	for( int j = 1; j<=x; j++)
		T[j][0] = j;
	int c;	
	for( int i = 1; i<=x; i++)
	{
		for( int j = 1; j<=y; j++)
		{
			if( A[i] == B[j] )
				c = 0;
			else
				c = 1;
			T[i][j] = MIN( MIN(T[x-1][y-1]+c, T[x-1][j]+1) , T[i][j-1]+1 );
		}
	}
	
	return T[x][y];
}
