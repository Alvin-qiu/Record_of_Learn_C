#include<stdio.h>
#include<stdlib.h>

void maopao(int j,int* a) 
{
	if(j==1)
	{
		return;
	}
	else
	{	
		int i=0;
		while(i<j)
		{
			if(a[i]>a[i+1])
			{
				int temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
			}			
			i++;
		}
		
		for(i=0;i<10;i++)	
		printf("%2d ",a[i]);	
		printf("\n");
		
		maopao(j-1,a);		
	}
}

 void main()
 {
 	#define N 10
 	int a[N]={12,3,5,6,8,9,11,23,45,0};
	
	
//	int i,j;	
//	for(j=0;j<N-1;j++)				//for循环排序 
//	{			 	
//		 for(i=0;i<N-1-j;i++)
//		 {
//		 	if(a[i]>a[i+1])
//		 	{
//			 	int temp=a[i];
//			 	a[i]=a[i+1];
//			 	a[i+1]=temp;
//			}		
//		 }
//		 
//	}



//	int i,j=0;
//	while(j<N-1)				//while 循环 
//	{
//		i=0;
//		while(i<N-1-j)
//		{
//			if(a[i]>a[i+1])
//			{
//				int temp=a[i];
//				a[i]=a[i+1];
//				a[i+1]=temp;
//			}			
//			i++;
//		}
//		
//		for(i=0;i<N;i++)	
//		printf("%d ",a[i]);	
//		printf("\n");
//		
//		j++;
//	}
//	
//	

	
	maopao(10,a);//，冒泡排序递归算法 
		 
	int i;		
	for(i=0;i<N;i++)	
	printf("%3d ",a[i]);	
	printf("\n");
		
	
 }
