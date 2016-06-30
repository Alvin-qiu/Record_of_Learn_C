#include<stdio.h>
#include<stdlib.h>
typedef struct
	{
		int x;
		int y;
	}MI;

int x=0;int y=0;int ci=0;int isgo=1;//设定全局开关，找到后退出递归 
void showb(MI b[10][10]);
void showby(MI b[10][10]);

void move( MI b[10][10],char ch)//控制层 
{
		switch(ch)
		{
			case 'a':
				
					if(y-1>=0&&b[x][y-1].x!=2)
					{
						int temp=b[x][y].x;
						b[x][y].x=b[x][y-1].x;
						b[x][y-1].x=temp;
						y=y-1;
					}					
				
				break; 
			case 'd':
					if(y+1<=9&&b[x][y+1].x!=2)
					{
						int temp=b[x][y].x;
						b[x][y].x=b[x][y+1].x;
						b[x][y+1].x=temp;
						y=y+1;
					}	
							
				break; 
			case 'w':
					if(x-1>=0&&b[x-1][y].x!=2)
					{
						int temp=b[x][y].x;
						b[x][y].x=b[x-1][y].x;
						b[x-1][y].x=temp;
						x-=1;
					}			
				break; 
			case 's':if(x+1<=9&&b[x+1][y].x!=2)
					{
						int temp=b[x][y].x;
						b[x][y].x=b[x+1][y].x;
						b[x+1][y].x=temp;
						x+=1;
					}			
				break; 
			
		}
		//printf("\nx=%d,y=%d",x,y);	
}





void AI(MI b[10][10],int i,int j)  //AI层 
{	if(isgo==0)return;
	showb(b);
	showby(b);
	b[i][j].y=3;
	++ci;
	if(i==9&&j==9)
	{
		isgo=0;
		printf("试探%d次后找到了",ci);
		return;
	}
	else
	{
		if(j+1<=9&&b[i][j+1].x<2&&b[i][j+1].y!=3)
		{
			
			move(b,'d');
			AI(b,i,j+1);
		}	
		if(i+1<=9&&b[i+1][j].x<2&&b[i+1][j].y!=3)
		{
		
			move(b,'s');
			AI(b,i+1,j);	
		}	
		if(j-1>=0&&b[i][j-1].x<2&&b[i][j-1].y!=3)
		{
			
			move(b,'a');
			AI(b,i,j-1);	
		}	
		
		if(i-1>=0&&b[i-1][j].x<2&&b[i-1][j].y!=3)
		{
			
			move(b,'w');
			AI(b,i-1,j);	
		}	
			
		
	} 
	
 
}

void showb(MI b[10][10])                                  //显示层
{
	int i,j;
	printf("----------------------------------------\n");
	for(i=0;i<=9;i++)
	{
		for(j=0;j<=9;j++)
		{
			printf("%4d",b[i][j].x);
		}
		printf("\n");
	}
}


void showby(MI b[10][10])
{
	int i,j;
	printf("----------------------------------------\n");
	for(i=0;i<=9;i++)
	{
		for(j=0;j<=9;j++)
		{
			printf("%4d",b[i][j].y);
		}
		printf("\n");
	}
}



void main()
{
	int a[10][10]={
		{ 0, 0, 0, 2, 0, 0, 0, 0, 0, 2},
		{ 0, 0, 0, 2, 0, 0, 0, 0, 0, 2},		
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
		{ 0, 0, 0, 2, 0, 0, 0, 0, 0, 2},
		{ 0, 2, 0, 2, 2, 0, 0, 2, 0, 2},
		{ 0, 0, 0, 0, 0, 2, 0, 0, 0, 2},
		{ 0, 0, 2, 2, 0, 2, 0, 0, 0, 2},
		{ 0, 0, 0, 2, 0, 0, 0, 0, 0, 2},
		{ 0, 0, 0, 0, 0, 0, 0, 2, 2, 2},
		{ 0, 0, 0, 2, 0, 0, 0, 0, 0, 0},
	};	
	a[0][0]=1;	
	
	MI b[10][10];
	int i,j;
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			b[i][j].x=a[i][j];
			b[i][j].y=0;
		}
	}
	
showb(b);
showby(b);
 AI(b,0,0);
 showb(b);
 showby(b);
 printf("累计试探%d次",ci);	
}
