#include"AI.h"
#include"control.h"


int canout = 0;
void findway(int a[N][N], int i, int j)
{
	b[i][j] = 3;
	if (i==N-1&&j==N-1)
	{
		canout = 1;
		printf("找到了！\n");
	}
	else
	{		
		if (i - 1 >= 0 && j + 2 <= N - 1 && b[i - 1][j + 2]  < 3 && a[i][j + 1] == 0 && canout == 0)
		{
			findway(a, i - 1, j + 2);	//3
		}
		if (i + 1 <= N - 1 && j + 2 <= N - 1 && b[i + 1][j + 2]  < 3 && a[i][j + 1] == 0 && canout == 0)
		{
			findway(a, i + 1, j + 2);	//4
		}
		if (i + 2 <= N - 1 && j + 1 <= N - 1 && b[i + 2][j + 1]  < 3 && a[i + 1][j] == 0 && canout == 0)
		{
			findway(a, i + 2, j + 1);	//5
		}
		if (i + 2 <= N - 1 && j - 1 >= 0 && b[i + 2][j + 1]  < 3 && a[i + 1][j] == 0 && canout == 0)
		{
			findway(a, i + 2, j - 1);	//6
		}
		if (i + 1 <= N - 1 && j - 2 >= 0 && b[i + 1][j - 2]  < 3 && a[i][j - 1] == 0 && canout == 0)
		{
			findway(a, i + 1, j - 2);	//7
		}
		if (i - 1 >= 0 && j - 2 >= 0 && b[i + 1][j - 2]  < 3 && a[i][j - 1] == 0 && canout == 0)
		{
			findway(a, i - 1, j - 2);	//8
		}
		if (i - 2 >= 0 && j - 1 >= 0 && a[i - 1][j] == 0 && b[i - 2][j - 1] < 3 && canout == 0)
		{
			findway(a, i - 2, j - 1);		//1	
		}
		if (i - 2 >= 0 && j + 1 <= N - 1 && b[i - 2][j + 1]  < 3 && a[i - 1][j] == 0 && canout == 0)
		{
			findway(a, i - 2, j + 1);	//2
		}
		if (canout == 0)b[i][j] = 0;
	}
}


void goout( )
{
	b[0][0] = 1;
	while (!(i==N-1&&j==N-1))
	{
		if (i - 1 >= 0 && j + 2 <= N - 1 && b[i - 1][j + 2]  == 3 && a[i][j + 1] == 0 )
		{
			b[i - 1][j + 2] = 0;
				move(a,'3');//3
		}
		if (i + 1 <= N - 1 && j + 2 <= N - 1 && b[i + 1][j + 2]  == 3 && a[i][j + 1] == 0 )
		{
			b[i + 1][j + 2] = 0;
			move(a, '4');//4
		}
		if (i + 2 <= N - 1 && j + 1 <= N - 1 && b[i + 2][j + 1]  == 3 && a[i + 1][j] == 0 )
		{
			b[i + 2][j + 1] = 0;
			move(a, '5');
			//5
		}
		if (i + 2 <= N - 1 && j - 1 >= 0 && b[i + 2][j - 1]  == 3 && a[i + 1][j] == 0 )
		{
			b[i + 2][j - 1] = 0;
			move(a, '6');//6
		}
		if (i + 1 <= N - 1 && j - 2 >= 0 && b[i + 1][j - 2]  == 3 && a[i][j - 1] == 0 )
		{
			b[i + 1][j - 2] = 0;
			move(a, '7');//7
		}
		if (i - 1 >= 0 && j - 2 >= 0 && b[i + 1][j - 2]  == 3 && a[i][j - 1] == 0 )
		{
			b[i + 1][j - 2] = 0;
			move(a, '8');//8
		}
		if (i - 2 >= 0 && j - 1 >= 0 && a[i - 1][j] == 0 && b[i - 2][j - 1] == 3 )
		{
			b[i - 2][j - 1] = 0;
			move(a, '1');//1	
		}
		if (i - 2 >= 0 && j + 1 <= N - 1 && b[i - 2][j + 1]  == 3 && a[i - 1][j] == 0 )
		{
			b[i - 2][j + 1] = 0;
			move(a, '2');//2
		}
	}
	printf("\nAI移动结束\n");
}