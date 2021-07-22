#include <stdio.h>

double comb(double n, double p);

int main(void)
{
	double n,p;
	scanf("%lf %lf", &n, &p);
	printf("%.0f\n", comb(n,p));
	
	return 0;
}

double comb(double n, double p)
{
	if( n == p)
		return 1;
	else
		return comb(n-1,p) * n/(n-p);
}
