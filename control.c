#include"control.h"

void move(int a[N][N], char ch)
{
	switch (ch)
	{
	case '1':
		if (i - 2 >= 0 && j - 1 >= 0 && a[i - 1][j] == 0 && a[i - 2][j - 1] < 3)
		{
			a[i - 2][j - 1] = a[i][j];
			a[i][j] = 0;
			i = i - 2;
			j = j - 1;
		}
		break;
	case '2':
		if (i - 2 >= 0 && j + 1 <= N - 1 && a[i - 2][j + 1] < 3 && a[i - 1][j] == 0)
		{
			a[i - 2][j + 1] = a[i][j];
			a[i][j] = 0;
			i = i - 2;
			j = j + 1;
		}
		break;
	case '3':
		if (i - 1 >= 0 && j + 2 <= N - 1 && a[i - 1][j + 2] < 3 && a[i][j + 1] == 0)
		{
			a[i - 1][j + 2] = a[i][j];
			a[i][j] = 0;
			i = i - 1;
			j = j + 2;
		}
		break;
	case '4':
		if (i + 1 <= N - 1 && j + 2 <= N - 1 && a[i + 1][j + 2] < 3 && a[i][j + 1] == 0)
		{
			a[i + 1][j + 2] = a[i][j];
			a[i][j] = 0;
			i = i + 1;
			j = j + 2;
		}
		break;
	case '5':
		if (i + 2 <= N - 1 && j + 1 <= N - 1 && a[i + 2][j + 1] < 3 && a[i + 1][j] == 0)
		{
			a[i + 2][j + 1] = a[i][j];
			a[i][j] = 0;
			i = i + 2;
			j = j + 1;
		}
		break;
	case '6':
		if (i + 2 <= N - 1 && j - 1 >= 0 && a[i + 2][j - 1] < 3 && a[i + 1][j] == 0)
		{
			a[i + 2][j - 1] = a[i][j];
			a[i][j] = 0;
			i = i + 2;
			j = j - 1;
		}
		break;
	case '7':
		if (i + 1 <= N - 1 && j - 2 >= 0 && a[i + 1][j - 2] < 3 && a[i][j - 1] == 0)
		{
			a[i + 1][j - 2] = a[i][j];
			a[i][j] = 0;
			i = i + 1;
			j = j - 2;
		}
		break;
	case '8':
		if (i - 1 >= 0 && j - 2 >= 0 && a[i + 1][j - 2] < 3 && a[i][j - 1] == 0)
		{
			a[i - 1][j - 2] = a[i][j];
			a[i][j] = 0;
			i = i - 1;
			j = j - 2;
		}
		break;
	}
}



void moveche(int a[N][N],char ch)
{
	switch (ch)
	{
	
	case 'w':
	{
		int m = i-1;
		while (m  >= 0 && a[m][j] == 0)
			m--;
		if (m<0)
		{
			a[i][j] = 0;	//不用a[0][j]=a[i][j],防止i=0出现错误
			a[0][j] = 1;			
			i = 0;
		}
		else
		{			
			a[i][j] = 0; 
			a[m][j] = 1;			
			i = m;
		}
	}
		break;

	case 's':
	{
		int m = i +1;
		while (m  < N && a[m][j] == 0)
			m++;
		if (m>=N)
		{
			
			a[i][j] = 0; 
			a[N-1][j] =1;			
			i = N-1;
		}
		else
		{
			a[i][j] = 0;
			a[m][j] = 1;			
			i = m;
		}
	}
		break;

	case 'a':
	{
		int m = j - 1;
		while (m >= 0 && a[i][m] == 0)
			m--;
		if (m<0)
		{			
			a[i][j] = 0;
			a[i][0] = 1;
			j = 0;
		}
		else
		{			
			a[i][j] = 0;
			a[i][m] = 1;
			j = m;
		}
	}


		break;

	case 'd':
	{
		int m = j + 1;
		while (m < N && a[i][m] == 0)
			m++;
		if (m>=N)
		{
			
			a[i][j] = 0; 
			a[i][N-1] = 1;			
			j = N-1;
		}
		else
		{
			a[i][j] = 0;
			a[i][m] = 1;
			j = m;
		}



	}
		break;

	default:
		break;
	}
}