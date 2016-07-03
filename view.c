#include"view.h"

void show(int a[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}
}