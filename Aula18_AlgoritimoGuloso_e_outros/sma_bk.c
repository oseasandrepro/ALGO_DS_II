#include <stdio.h>
#include <string.h>


int R[8001];
int s[8001];
int e[8001];

void sma_bk(int *s, int *e, int N, int d, int* R, int* pcmax);

int main(void)
{
	int n;
	int cmax = 0;
	memset(R, 0, sizeof(R));
	
	scanf("%d", &n);
	for( int i =1; i<=n; i++)
		scanf("%d%d", &s[i], &e[i]);
	
	sma_bk(s, e, n, 0, R, &cmax);
	printf("%d\n", cmax);	
	return 0;
}

void sma_bk(int *s, int *e, int N, int d, int* R, int* pcmax)
{
	if( d == N)
	{
		int c = 0;
		for( int i =1; i<=N; i++)
			if( R[i] == 1 )
				c +=1;
		if( *pcmax<c )
			*pcmax = c;
	}
	else
	{
		R[d+1]  = 0;
		sma_bk(s, e, N, d+1, R, pcmax);
		int posso = 1;
		for( int i = 1; i<=d; i++)
			if( R[i] && e[i]>s[d+1] && e[d+1]>s[i]){
				posso = 0;
				break;
			}
		if( posso ){
			R[d+1] = 1;
			sma_bk(s, e, N, d+1, R, pcmax);
		}
	}	
}
