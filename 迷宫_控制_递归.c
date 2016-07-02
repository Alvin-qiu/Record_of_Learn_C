#include<stdio.h>
#include<stdlib.h>


show(int a[10][10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}
}


void move(int a[10][10], int i, int j)
{
	char ch = getchar();
	getchar();
	switch (ch)
	{
	case 'w':
		if (i - 1 >= 0&&a[i-1][j]<2)
		{
			int temp = a[i - 1][j];
			a[i - 1][j] = a[i][j];
			a[i][j] = temp;
			i--;
		}
		break;
	case 'a':
		if (j - 1 >= 0 && a[i][j - 1] < 2)
		{
			int temp = a[i][j - 1];
			a[i][j - 1] = a[i][j];
			a[i][j] = temp;
			j--;
		}
		break;
	case 's':
		if (i + 1 <= 9&&a[i+1][j]<2)
		{
			int temp = a[i + 1][j];
			a[i + 1][j] = a[i][j];
			a[i][j] = temp;
			i++;
		}
		break;
	case 'd':
		if (j+1<=9&&a[i][j+1]<2)
		{
			int temp = a[i][j + 1];
			a[i][j + 1] = a[i][j];
			a[i][j] = temp;
			j++;
		}
		break;
	}
	show(a);
	move(a, i, j);
}



int main()
{
	int a[10][10] = {
		{ 1,0,0,0,0,0,0,0,0,0 },
		{ 0,0,2,0,0,0,0,0,2,0 },
		{ 0,0,2,0,0,0,0,0,0,0 },
		{ 0,0,0,2,0,0,2,0,0,0 },
		{ 0,0,2,0,0,0,0,0,0,0 },
		{ 0,0,0,2,0,2,0,0,0,0 },
		{ 0,0,2,0,0,0,2,0,2,0 },
		{ 0,0,0,2,0,0,0,0,0,0 },
		{ 0,0,0,2,0,0,0,2,0,2 },
		{ 0,0,0,0,0,0,0,2,0,0 },
	};
	int i = 0, j = 0;
	show(a);
	move(a, i, j);



}
