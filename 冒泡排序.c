#include<stdio.h>
#include<stdlib.h>
 void main()
 {
 	#define N 10
 	int a[N]={12,3,5,6,8,9,11,23,45,0};
	
	
	int i,j;	
	for(j=0;j<N-1;j++)
	{			 	
		 for(i=0;i<N-1-j;i++)
		 {
		 	if(a[i]>a[i+1])
		 	{
			 	int temp=a[i];
			 	a[i]=a[i+1];
			 	a[i+1]=temp;
			}		
		 }	 
		 
		for(i=0;i<N;i++)	
		printf("%d ",a[i]);	
		printf("\n");
		
	}
	
	 
 }
