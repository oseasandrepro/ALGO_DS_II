#include <stdio.h>

#define SIZE	9

char vetor[3] = {' ', 'X', 'O'};

void gerarsolucao(int d, char *R);
int Evalido(char *R);

int main(void)
{
	char R[SIZE];
	gerarsolucao(-1, R); 
	
	return 0;
}

void gerarsolucao(int d, char R[SIZE])
{
	if( d == 8)
	{
		int flag = Evalido(R);
		//printf("%d\n", flag);
		//if( flag )
		//{
			printf("  %c | %c | %c   \n", R[0], R[1], R[2]);
			printf("----|---|----\n");
			printf("  %c | %c | %c    \n",  R[3], R[4], R[5]);
			printf("----|---|----\n");
			printf("  %c | %c | %c\n", R[6], R[7], R[8]);
			printf("\n");
		//}
	}
	else
	{
		for( int i = 0; i<3; i++)
		{
			R[d+1] = vetor[i];
			gerarsolucao(d+1, R);
		}
	}
}

int Evalido(char *R)
{
	int contx, conto;
	char vencedor;
	contx = conto = 0;
	vencedor = '*';
	for( int i = 0; i<SIZE; i++)
	{
		if( R[i]== 'X')
			contx++;
		else if(R[i] == 'O');
			conto++;
	}
		
	if( (R[0]==R[1]) && (R[1]==R[2]) && R[0]!=' ' )
		vencedor = R[0];
	else if( (R[3]==R[4]) && (R[4]==R[5]) && R[3]!=' ' )
		vencedor = R[4];
	else if( (R[6]==R[7]) && (R[7]==R[8]) && R[6]!=' ')
		vencedor = R[6];
	else if( (R[0]==R[3]) && (R[3]==R[6]) && R[0]!=' ' )
		vencedor = R[0];
	else if( (R[1]==R[4]) && (R[4]==R[8]) && R[1]!=' ')
		vencedor = R[1];
	else if( (R[2]==R[5]) && (R[5]==R[8]) && R[2]!=' ')
		vencedor = R[2];
	else if( (R[0]==R[4]) && (R[4]==R[8]) && R[0]!=' ')
		vencedor = R[0];
	else if( (R[2]==R[4]) && (R[4]==R[6]) && R[2]!=' ')
		vencedor = R[2];
		
	if (vencedor=='*' && (contx==conto+1) )
		return 1;
	else if( vencedor=='x' && (contx==conto+1) )
		return 1;
	else if( vencedor == 'O' && contx==conto)
		return 1;
	else return 0;
	
}
