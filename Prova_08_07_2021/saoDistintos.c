#include <stdio.h>

#define SIZE 5

int saoDistintos(int *A, int N);

int main(void)
{
	int A[SIZE] = {1, 3, 4, 2, 5};
	
	printf("sao distintos? ");
	
	saoDistintos(A, SIZE)==0?printf("nao\n"):printf("sim\n");
	
	return 0;
}

int saoDistintos(int *A, int N)
{
	//Assume N>=0
	//Retorna 0 se os primeiros elementos de A
	//são distintos, e 0 caso contrario
	if( N==0)
		return 1;
	else
	{
		int p,q;
		p = saoDistintos(A, N-1);
		q = 1;
		for( int i = (N-1)-1; i>=0; i--)
		{
			if(A[N-1] == A[i]){
				q = 0;
				break;
			}
		}
		return p&&q;
	}
}
