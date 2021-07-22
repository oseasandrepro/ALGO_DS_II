#include <stdio.h>
#define BUFFER_SIZE 1000001

unsigned int T[BUFFER_SIZE];

unsigned int fibonacci(unsigned int n);
/* É Recursivo
   Retorna o n-esimo fibonacci
   Assume n>=1 
   Aqui para evitar repeticao de 
   subproblemas usamos a tecnica de memorização(Cache!)*/
   
int main(void)
{
	unsigned int n;
	memset(T, -1, BUFFER_SIZE);
	printf("%d\n", T[0]);
	scanf("%d", &n);
	if( n!=0 ){
		for( unsigned int i = 1; i<=n; i++){
			((i%15)==0)?printf("%d\n",fibonacci(i)):printf("%d, ",fibonacci(i));
		}
	}
	return 0;
}

unsigned int fibonacci(unsigned int n)
{
	if( T[n] == -1)
	{
		if( n==1 || n==2)
			T[n] = 1;
		else
			T[n] = fibonacci(n-1) + fibonacci(n-2);
	}
	return T[n];
}
