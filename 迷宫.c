#include<stdio.h>
#include<stdlib.h>

void show(int a[10][10])
{
	int i,j;
	printf("----------------------------------------\n");
	for(i=0;i<=9;i++)
	{
		for(j=0;j<=9;j++)
		{
			printf("%4d",a[i][j]);
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
		{ 0, 0, 0, 2, 0, 0, 2, 0, 0, 2},
		{ 0, 0, 0, 0, 0, 0, 0, 2, 0, 2},
		{ 0, 0, 0, 2, 0, 0, 0, 0, 0, 2},
	
	
	};
	int x=0,y=0;
	a[0][0]=1;
	
	
	//show(a);

	while(1)
	{	
		show(a);
		char ch=getchar();
		getchar();
		switch(ch)
		{
			case 'a':
				
					if(y-1>=0&&a[x][y-1]!=2)
					{
						int temp=a[x][y];
						a[x][y]=a[x][y-1];
						a[x][y-1]=temp;
						y=y-1;
					}					
				
				break; 
			case 'd':
					if(y+1<=9&&a[x][y+1]!=2)
					{
						int temp=a[x][y];
						a[x][y]=a[x][y+1];
						a[x][y+1]=temp;
						y=y+1;
					}	
							
				break; 
			case 'w':
					if(x-1>=0&&a[x-1][y]!=2)
					{
						int temp=a[x][y];
						a[x][y]=a[x-1][y];
						a[x-1][y]=temp;
						x-=1;
					}			
				break; 
			case 's':if(x+1<=9&&a[x+1][y]!=2)
					{
						int temp=a[x][y];
						a[x][y]=a[x+1][y];
						a[x+1][y]=temp;
						x+=1;
					}			
				break; 
			
		}
		printf("\nx=%d,y=%d",x,y);
		
	}
	
}
