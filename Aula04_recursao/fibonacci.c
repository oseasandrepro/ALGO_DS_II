#include <stdio.h>


int fibonacci(int n);
/* É Recursivo
   Retorna o n-esimo fibonacci
   Assume n>=1 
   Problema: tem repeticao de 
   subproblemas na arvore de recursão*/
   
int main(void)
{
	int n;
	scanf("%d", &n);
	if( n!=0 ){
		for( int i = 1; i<=n; i++){
			((i%10)==0)?printf("%d\n",fibonacci(i)):printf("%d, ",fibonacci(i));
		}
	}
	return 0;
}

int fibonacci(int n)
{
	if( n == 1 || n==2)
		return 1;
	else
		return fibonacci(n-1) + fibonacci(n-2);
}
