#include<stdio.h> 
#include<stdlib.h>




void charudg(int i,int *a)  //插入排序递归算法 
{
	if(i==0)
	{
		return;
	}
	else
	{
		charudg(i-1,a);
		
		int j=i;
		int temp=a[i];
		while(j>0&&a[j-1]>temp)
		{
			 a[j]=a[j-1];
			 j--;	
		}	
		a[j]=temp;	
		
	int i;
	for(i=0;i<10;i++)
	{
		printf("%2d  ",a[i]);
	}	
	printf("\n");	
	}
}

void main()
{
	int a[10]={14,2,12,5,6,4,8,6,10,4};
	
	int i;
	for(i=0;i<10;i++)
	{
		printf("%2d  ",a[i]);
	}
		printf("\n");
//	for(i=1;i<10;i++)//for 循环插入排序 
//	{
//		int j=i;
//		int temp=a[i];
//		while(j>0&&a[j-1]>temp)
//		{
//			 a[j]=a[j-1];
//			 j--;	
//		}	
//		a[j]=temp;		
//	}
	
//	i=1;
//	while(i<10) 
//	{
//		int j=i;
//		int temp=a[i];
//		for(;j>0&&a[j-1]>temp;j--)
//		{
//			a[j]=a[j-1];
//		}
//		a[j]=temp;	
//		i++	;
//	}
	
	charudg(9, a);

	printf("\n");
	for(i=0;i<10;i++)
	{
		printf("%2d  ",a[i]);
	}	
}
