#include <stdio.h>

#define Hevogal(a) ( ((a)=='a'||(a)=='A') || ((a)=='e'||(a)=='E') || ((a)=='i'||(a)=='I') || ((a)=='o'||(a)=='O') || ((a)=='u'||(a)=='U') )
#define Heconsoante(a) ( ((a)=='b'||(a)=='B') || ((a)=='c'||(a)=='C') || ((a)=='d'||(a)=='D') || ((a)=='f'||(a)=='F') || ((a)=='g'||(a)=='G') || ((a)=='h'||(a)=='H') || ((a)=='j'||(a)=='J') || ((a)=='k'||(a)=='K') || ((a)=='l'||(a)=='L') || ((a)=='m'||(a)=='M') || ((a)=='n'||(a)=='N') || ((a)=='p'||(a)=='P') || ((a)=='q'||(a)=='Q') || ((a)=='r'||(a)=='R') || ((a)=='s'||(a)=='S') || ((a)=='t'||(a)=='T') || ((a)=='v'||(a)=='V') || ((a)=='w'||(a)=='W') || ((a)=='x'||(a)=='X') || ((a)=='z'||(a)=='Z') )

#define SIZE		1001
#define MAX_LENGTH	6
#define MIN_LENGTH	4
#define SIZE_C		52

char caracteres[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

char R[SIZE];
void senhas(int d,char* R);

int main(void)
{
	senhas(0, R);
	return 0;
}

void senhas(int d,char* R)
{
	if( d>=MIN_LENGTH && d<=MAX_LENGTH )
	{
		for( int i = 1; i<=d; i++)
		{
			printf("%c", R[i]);
		}
		printf("\n");
	}
	else
	{
		
		for( int i = 0; i<SIZE_C; i++)
		{
			if( (Heconsoante(R[d]) && !Heconsoante(caracteres[i])) || (Hevogal(R[d]) && !Hevogal(caracteres[i])) || d==0  )
			{
				R[d+1] = caracteres[i];
				senhas(d+1, R);
			}
		}
	}
}
