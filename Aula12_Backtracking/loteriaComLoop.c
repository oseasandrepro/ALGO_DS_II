#include <stdio.h>

#define SIZE 10
void loteria1(int* V, int N);
void loteria2(int* V, int N);

int vetor1[SIZE] = {1, 3, 5, 4, 2, 0, 7, 10, 66, 78};
int vetor2[SIZE] = {0, 1, 2, 3, 4, 5, 7, 10, 66, 78};

int main(void)
{
	loteria1(vetor1, SIZE);
	//loteria2(vetor2, SIZE);
	return 0;
}

void loteria1(int* V, int N)
{
	//Assume N>=5
	for(int i = 0; i<N; i++)
	{
		for(int j = 0; j<N; j++)
		{
			if(V[i]<V[j])
			{
				for(int z = 0; z<N; z++)
				{
					if(V[j]<V[z])
					{
						for(int w = 0; w<N; w++)
						{
							if( V[z]<V[w])
							{
								for(int t = 0; t<N; t++)
								{
									if( V[w]<V[t])
									{
										printf("%d %d %d %d %d\n",V[i],V[j],V[z],V[w],V[t]);
									}
								}
							}
						}
					}
				}
			}
		}
	}

}

void loteria2(int* V, int N)
{
	//Assume N>=5 e V ordenado
	for(int i = 0; i<N; i++)
	{
		for(int j = i+1; j<N; j++)
		{
			for(int z = j+1; z<N; z++)
			{
				
				for(int w = z+1; w<N; w++)
				{
					for(int t = w+1; t<N; t++)
					{
						printf("%d %d %d %d %d\n",V[i],V[j],V[z],V[w],V[t]);
					}
				}
			}
				
		}
	}

}
