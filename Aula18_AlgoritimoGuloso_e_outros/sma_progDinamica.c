#include <stdio.h>
#include <string.h>
#include <limits.h>

#define SIZE 8005

int T[SIZE][SIZE];
int s[SIZE];
int e[SIZE];

int S(int *s, int* e, int N, int i, int j);

int main(void)
{
	int n;
	
	memset(T, -1, sizeof(T));
	
	scanf("%d", &n);
	for( int i = 1; i<=n; i++)
		scanf("%d%d", &s[i], &e[i]);
	
	s[0] = e[0] = INT_MIN;		//Tarefa 0
	s[n+1] = e[n+1] = INT_MAX;	//Tarefa n+1
	
	
	printf("%d\n", S(s, e, n, 0, n+1) );
}

int S(int *s, int* e, int N, int i, int j)
{
	if( T[i][j] == -1)
	{
		int cmax = 0;
		for( int z = 1; z<=N; z++)
		{
			if( e[i] <= s[z] && e[z]<=s[j]  )
			{
				int c = S(s, e, N, i, z) + S(s, e, N, z, j) + 1;
				if( cmax < c )
					cmax = c;
			}
		}
		T[i][j] = cmax;
	}
	return T[i][j];
}
