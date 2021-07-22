#include <stdio.h>


void hanoi(int n, char Torig, char Tdest, char Taux);
/* supões: n>=0
   Garante escrita de tuplas Torig -> Tdest
 */
 
int main(void)
{
	int n;
	scanf("%d", &n);
	printf("****\n");
	hanoi(n, 'A', 'B', 'C');
	
	return 0;
}

void hanoi(int n, char Torig, char Tdest, char Taux)
{
	if( n > 0)
	{
		hanoi(n-1, Torig, Taux, Tdest);
		printf("%c -> %c\n", Torig, Tdest);
		hanoi(n-1, Taux, Tdest, Torig);
	}
}
