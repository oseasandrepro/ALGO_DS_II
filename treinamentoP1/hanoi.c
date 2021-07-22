#include <stdio.h>

void hanoi(int n, char To, char Td, char Taux);

int main(void)
{
	int n;
	scanf("%d", &n);
	
	hanoi(n, 'A', 'B', 'C');
}

void hanoi(int n, char To, char Td, char Taux)
{
	if( n>=1 )
	{
		hanoi(n-1, To, Taux, Td);
		printf("%c ---> %c\n", To,Td);
		hanoi(n-1, Taux, Td, To);
		
	}
}
