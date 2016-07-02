#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 32

void sort(int* a,int  n )
{
	if (n==1)
	{
		return;
	}
	else
	{
		sort(a, n - 1);
		int temp = a[n - 1];
		int i = n - 1;
		while (a[i-1]>temp)
		{
			a[i] = a[i - 1];
			i--;
		}
		a[i] = temp;
	}
}

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

int fget = -1;
int find(int a[N][N],int num, int fh, int lh, int fl, int ll)//递归查找法
{
	if (fh!=lh)
	{		
		if (lh - fh == 1)						//处理mid始终等于fh情况
		{
			 if (num < a[lh][0])
			{
				lh -= 1;				
			}
			else
			{
				fh += 1;				
			}
		}
		else
		{
			int mid = (fh + lh) / 2;
			if (num<a[mid][0])	lh = mid - 1;				
			else fh = mid;			
		}
		find(a, num, fh, lh, fl, ll);
	}
	else if (fget!=1&&fl<=ll)	
	{
		int mid = (fl + ll) / 2;
		if (num==a[fh][mid])
		{
			fget = 1;
			printf("\n找到了num=%d,位置在a[%d][%d]=%d", num, fh, mid, a[fh][mid]);
		}
		else
		{
			if (num<a[fh][mid])
			{
				ll = mid - 1;
			}
			else
			{
				fl = mid + 1;
			}
			find(a,num,fh,lh,fl,ll );
		}
	}
	return fget;
}


int find2(int a[N][N], int num, int fh, int lh, int fl, int ll)//循环查找法
{
	while (fl<=ll)
	{
		if (fh != lh)
		{	
			if (lh - fh == 1)
			{
				if (num==a[lh][0])
				{
					fget = 1;
					printf("\n找到了num=%d,位置在a[%d][%d]=%d", num, lh, 0, a[lh][0]);
					break;
				}
				else if(num < a[lh][0])
				{
					lh -= 1;
					continue;
				}
				else
				{
					fh += 1;
					continue;
				}
			}
			int mid = (fh + lh) / 2;
			if (num<a[mid][0])	 lh = mid - 1;	
			else  fh = mid;			
		}
		else
		{
			int mid = (fl + ll) / 2;
			if (num == a[fh][mid])
			{
				fget = 1;
				printf("\n找到了num=%d,位置在a[%d][%d]=%d", num, fh, mid, a[fh][mid]);
				break;
			}
			else
			{
				if (num<a[fh][mid])	ll = mid - 1;			
				else	fl = mid + 1;								
			}
		}
	}
	return fget;
}


int main()
{
	int a[N][N];
	srand((unsigned int)time(NULL));
	for (int  i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			a[i][j] = rand() % 1024;
		}
	}
	show(a);
	printf("排序后：\n");
	sort(a,N*N);
	show(a);
	
	int num;
	printf("\n输入你要找的数据 num：\n");
	scanf("%d", &num);
	
	if (find(a, num, 0, N-1, 0, N-1) == -1)printf("没有找到！");

	system("pause");

}

