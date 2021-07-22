#include <stdio.h>

#define SIZE 4
void escreverPermutacoes(int* V);

int vetor[] = {1, 3, 5, 4};

int main(void)
{
	escreverPermutacoes(vetor);
	return 0;
}

void escreverPermutacoes(int* V)
{
	for(int i = 0; i<SIZE; i++)
	{
		for(int j = 0; j<SIZE; j++)
		{
			if(j!=i)
			{
				for(int z = 0; z<SIZE; z++)
				{
					if(z!=j && z!=i)
					{
						for(int w = 0; w<SIZE; w++)
						{
							if( w!=z && w!=j && w!=i)
							{
								printf("%d %d %d %d\n",V[i],V[j],V[z],V[w]);
							}
						}
					}
				}
			}
		}
	}

}
