#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void hang(int a[3][4],int i,int j ,int* hangmax)
{
	if (j == 1)
	{
		hangmax[0] = a[0][0];
		hangmax[1] = a[1][0];
		hangmax[2] = a[2][0];
	}
	else
	{
		hang(a, i, j - 1, hangmax);
		hangmax[0] = hangmax[0] > a[0][j - 1] ? hangmax[0] : a[0][j - 1];
		hangmax[1] = hangmax[1] > a[1][j - 1] ? hangmax[1] : a[1][j - 1];
		hangmax[2] = hangmax[2] > a[2][j - 1] ? hangmax[2] : a[2][j - 1];
	}
}

void lie(int a[3][4], int i, int j, int *liemax)
{
	if (i == 1)
	{
		liemax[0] = a[0][0];
		liemax[1] = a[0][1];
		liemax[2] = a[0][2];
		liemax[3] = a[0][3];
	}
	else
	{
		lie(a, i - 1, j, liemax);
		liemax[0] = liemax[0] > a[i - 1][0] ? liemax[0] : a[i - 1][0];
		liemax[1] = liemax[1] > a[i - 1][1] ? liemax[1] : a[i - 1][1];
		liemax[2] = liemax[2] > a[i - 1][2] ? liemax[2] : a[i - 1][2];
		liemax[3] = liemax[3] > a[i - 1][3] ? liemax[3] : a[i - 1][3];
	}
}






int main()
{
	int	a[3][4];
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 12; i++)
	{
		a[i/4][i%4] = rand() % 100;
	}
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%3d", a[i][j]);
		}
		printf("\n");
	}

	int hangmax[3];
	hang(a, 3, 4, hangmax);
	printf("max1=%d\nmax2=%d\nmax3=%d\n", hangmax[0], hangmax[1], hangmax[2]);

	int liemax[4];
	lie(a, 3, 4, liemax);
	printf("lie1=%d\nlie2=%d\nlie3=%d\nlie4=%d\n", liemax[0], liemax[1], liemax[2], liemax[3]);

	system("pause");
}
