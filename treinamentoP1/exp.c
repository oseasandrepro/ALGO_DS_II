#include <stdio.h>

int expo1(int x, int y);
int expo2(int x, int y);

int main(void)
{
	int x,y;
	scanf("%d %d", &x, &y);
	
	printf("%d\n", expo1(x,y));
	
	return 0;
}

int expo1(int x, int y)
{
	if( y == 0)
		return 1;
	else
		return x*expo1(x,y-1);
}

int expo2(int x, int y)
{
	int k;
	if( y>0)
	{
		if( (y%2) == 0){
			k = expo2(x, (y/2) );
			return k*k;
		}
		else{
			k = expo2(x, (y-1)/2 );
			return k*k*x;
		}
	}
	else
		return 1;
}
