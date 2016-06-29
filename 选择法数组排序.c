#include<stdio.h>
#include<stdlib.h>
#include<time.h>



void sort(int N,int a[N])//递归法选择排序 
{
	if(N==1)
	{
		return;
	}
	else
	{
		int j,i=0,kmax=0;
		for( j=i+1;j<N;j++)
		a[j]>a[kmax]?kmax=j:1;
		if(kmax!=i)
		{
			a[kmax]=a[kmax]^a[i];   
			a[i]=a[kmax]^a[i];
			a[kmax]=a[kmax]^a[i];
		}
		sort(N-1,a+1);
	for(i=0;i<N;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	}
}



void main()
{
	int N=10;
	srand(time(NULL));
	int a[N],i,j;
	for( i=0;i<N;i++)
	{
		a[i]=rand()%200;
	}
	
	for(i=0;i<N;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	
	
	
//	int kmax=0;     //for循环选择排序 
//	for(i=0;i<N-1;i++)
//	{
//		kmax=i;
//		for( j=i+1;j<N;j++)
//		{
//			a[j]>a[kmax]?kmax=j:1;
////			if(a[j]>a[kmax])
////			kmax=j;
//		}
//		if(kmax!=i)
//		{
//			int temp=a[kmax];
//			a[kmax]=a[i];
//			a[i]=temp; 
//		}
//	}
	
//	
//	int kmax=0;        //while 循环选择排序 
//	i=0;
//	while(i<N-1)
//	{
//		kmax=i;
//		int j=i+1;
//		while(j<N)
//		{
//			a[j]>a[kmax]?kmax=j:1;	
//			j++;
//		}
//		if(kmax!=i)
//		{
//			a[kmax]=a[kmax]^a[i];
//			a[i]=a[kmax]^a[i];
//			a[kmax]=a[kmax]^a[i];
//		}
//		i++;
//	}
	
	sort(N,a);
	
	
	for(i=0;i<N;i++)
	{
		printf("%d ",a[i]);
	}
	
}
