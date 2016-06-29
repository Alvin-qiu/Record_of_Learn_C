#include<stdio.h>
#include<stdlib.h>
#define N 1024 

void find(int a[N],int num)
{
	//	printf("%d",num);
	int tou=0;
	int wei=N-1;
	int zhong;
	int flag=-1;
	int ci=0;
	while(tou<=wei)
	{	ci++;
		printf("\ntou=%4d,wei=%4d,zhong=%4d,次数为%4d",tou,wei,zhong,ci);
		zhong=(tou+wei)/2;
		//拉格朗日二分查找法
		//zhong=tou+(wei-tou)*1.0*(num-a[tou])/(a[wei]-a[tou]) ;
		if(num==a[zhong])
		{
			flag=1;
			printf("\n第%d次找到了%d=a[%d]",ci,num,zhong);
			break;
		}
		else if(num<a[zhong])
		{
			wei=zhong-1;
		}
		else
		tou=zhong+1;
	}
	if(flag==-1)
	printf("没有找到！");
}


int main()
{
	int a[N];
	int i;
	for(i=0;i<N;i++)
	{
		a[i]=i;
		printf("%4d",a[i]);
	}
 	int num;
 	scanf("%d",&num);
 	//printf("%d",num);
 	find(a,num); 		
}
