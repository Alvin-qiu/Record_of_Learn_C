#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

char strpath[256]="	路径";
char savepath[256]={0};
void showlist(char str[256])
{	
	sprintf(savepath,"E:\\%s.txt",str);
	FILE *pf;//文件指针 
	pf=fopen(strpath,"r");//读取 
	FILE *pfw=fopen(savepath,"w");
	
	if(pf==NULL||pfw==NULL)
	{
		printf("文件打开失败！");
		 
	}
	else
	{			//feof(pf)到了文件末尾返回1，，否则返回0 
		while(!feof(pf))//没有到文件末尾就继续 
		{
			char readstr[1024]={0};
			fgets(readstr,1024,pf);//读取一行 			
			char *p=strstr(readstr,str);//字符串查找 
			//返回值为NULL没有找到
			
			if(p!=NULL)
			{
				 puts(readstr);//打印 
				 fputs(readstr,pfw);//写入 
			}
		}

	fclose(pf);
	fclose(pfw);
	}

	
}

int main()
{
	char str[256]="";
	scanf("%s",str);
	printf("你要查询的是%s \n",str);
	
	time_t start ,end;
	time(&start);	
	showlist(str);	
	time(&end);
	printf("花了%f秒\n",difftime(end,start));
	
	system(savepath);
}
