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
	case '1':
		if (i - 2 >= 0 && j - 1 >= 0 && a[i - 1][j] == 0 && a[i - 2][j - 1] == 0)
		{
			int temp = a[i - 2][j - 1];
			a[i - 2][j - 1] = a[i][j];
			a[i][j] = temp;
			i = i - 2;
			j = j - 1;
		}
		break;
	case '2':
		if (i - 2 >= 0 && j + 1 <= 9 && a[i - 2][j + 1] == 0 && a[i - 1][j] == 0)
		{
			int temp = a[i - 2][j + 1];
			a[i - 2][j + 1] = a[i][j];
			a[i][j] = temp;
			i = i - 2;
			j = j + 1;
		}
		break;
	case '3':
		if (i - 1 >= 0 && j + 2 <= 9 && a[i - 1][j + 2] == 0 && a[i][j + 1] == 0)
		{
			int temp = a[i - 1][j + 2];
			a[i - 1][j + 2] = a[i][j];
			a[i][j] = temp;
			i = i - 1;
			j = j + 2;
		}
		break;
	case '4':
		if (i + 1 <= 9 && j + 2 <= 9 && a[i + 1][j + 2] == 0 && a[i][j + 1] == 0)
		{
			int temp = a[i + 1][j + 2];
			a[i + 1][j + 2] = a[i][j];
			a[i][j] = temp;
			i = i + 1;
			j = j + 2;
		}
		break;
	case '5':
		if (i + 2 <= 9 && j + 1 <= 9 && a[i + 2][j + 1] == 0 && a[i + 1][j] == 0)
		{
			int temp = a[i + 2][j + 1];
			a[i + 2][j + 1] = a[i][j];
			a[i][j] = temp;
			i = i + 2;
			j = j + 1;
		}
		break;
	case '6':
		if (i + 2 <= 9 && j - 1 >= 0 && a[i + 2][j + 1] == 0 && a[i + 1][j] == 0)
		{
			int temp = a[i + 2][j - 1];
			a[i + 2][j - 1] = a[i][j];
			a[i][j] = temp;
			i = i + 2;
			j = j - 1;
		}
		break;
	case '7':
		if(i + 1 <= 9 && j - 2 >= 0 && a[i + 1][j - 2] == 0 && a[i][j - 1] == 0)
		{
			int temp = a[i + 1][j - 2];
			a[i + 1][j - 2] = a[i][j];
			a[i][j] = temp;
			i = i + 1;
			j = j - 2;
		}
		break;
	case '8':
		if (i - 1 >= 0 && j - 2 >= 0 && a[i + 1][j - 2] == 0 && a[i][j - 1] == 0)
		{
			int temp = a[i - 1][j - 2];
			a[i - 1][j - 2] = a[i][j];
			a[i][j] = temp;
			i = i - 1;
			j = j - 2;
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
	//printf("\n%4d", a[2][2]);
	move(a, i, j);

	system("pause");
}
