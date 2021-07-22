#include <stdio.h>
#include <string.h>

#define SIZE 1001

int rmax;
int smax[SIZE];
int R[SIZE];
int H[SIZE];
int D[SIZE];
int U[SIZE];

void maxtarefa(int* H, int* R, int N, int d, int* D, int S, int* max, int* U);

int main(void)
{
	int t = 0;
	int n;
	rmax = 0;
	scanf("%d", &n);
	for( int i = 1; i<=n; i++)
		scanf("%d", &H[i]);
	for( int i = 1; i<=n; i++)
		scanf("%d", &R[i]);
		
		
	memset(U, 0, sizeof(U));
	
	maxtarefa(H, R, n, 0, D, 0, &rmax, U);
	
	printf("** %d **\n", rmax);
	for( int i = 1; i<=n; i++)
		printf("%4d", smax[i]);
	printf("\n");

	
	
}

void maxtarefa(int* H, int* R, int N, int d, int* D, int S, int* max, int* U)
{
	if( (d == N) )
	{
		if( (*max)<S )
		{
			(*max) = S;
			for(int i = 1; i<=d; i++)
				smax[i] = D[i];
				
		}
	}
	else
	{
		for( int i = 1; i<=N; i++)
		{
			if( !U[i] )
			{
				D[d+1] = i;
				U[i] = 1;
				if( H[i]>=d+1)
					S=S+R[i];	
					
				maxtarefa(H, R, N, d+1, D, S, max, U);
				U[i] = 0;
				if( H[i]>=d+1)
					S=S-R[i];
			}
		}
	}
}
