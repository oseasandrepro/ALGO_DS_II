/* Solução teoricamente possivel Mas,
 inviavel na pratica */

#include <stdio.h>

double comb(double n, double p);

int main(void)
{
	double n,p;
	scanf("%lf %lf", &n, &p);
	
	printf("%f\n", comb(n,p) );
	return 0;
}

double comb(double n, double p)
{
	if( p == 0)
		return 1.0;
	else{
		return  comb(n,p-1) * (n-(p-1)) / p;
	}
}
