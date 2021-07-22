#include <stdio.h>

//retorna  Cn,k(combinacao de n tomados k a k
int comb(int n, int k)
{
	if( n == k){
		return 1;
	}
	else{
		return comb(n-1, k) * (n/(n-k));
	}
}

int main(void)
{
	printf("%d\n", comb(4,3) );
	return 0;
}
