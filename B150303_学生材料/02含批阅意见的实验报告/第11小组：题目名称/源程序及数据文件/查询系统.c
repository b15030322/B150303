


#include "train.h"
#include <stdlib.h>
#include <windows.h>
#include <stdio.h>
//-----------显示所有车次信息--------//
void put(train tra[],int n)
{	
	
	int i;

	printf("车号  |出发时间 | 总车程|起始站|终点站| 一等座票价| 一等座票数|二等座票价| 二等座票数");
	printf("\n");
	for(i=0;i<n;i++)
	{  	
		printf("%4s | %d : %d | %5d | %4s | %4s | %9.2f |%10d |%9.2f | %10d\n",tra[i].number,tra[i].hour,tra[i].minute,tra[i].time2,tra[i].start,tra[i].end,tra[i].type1.price,tra[i].type1.free,tra[i].type2.price,tra[i].type2.free);
	}
	
}
//-------------车次排序函数---------//
void calcurank(train tra[],int n)
{
	int i,j,temp,choice;
	train t;
	printf("请选择要排序的信息：1、一等座票价；2、总车程；");
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:
		for(i=0;i<n-1;i++)
		{
			
			for(j=i+1;j<n;j++)
			{	temp=i;
				if(tra[temp].type1.price>tra[j].type1.price)
				{temp=j;}
				if(i!=temp)
				{
					t=tra[i];
					tra[i]=tra[temp];
					tra[temp]=t;
				}
			}
		}
		put(tra,n);
		break;
	case 2:
		for(i=0;i<n-1;i++)
		{
		
			for(j=i+1;j<n;j++)
			{	temp=i;
				if(tra[temp].time2>tra[j].time2)
				temp=j;		
			if(i!=temp)
			{
				t=tra[i];
				tra[i]=tra[temp];
				tra[temp]=t;
			}}
		}
		put(tra,n);
		break;
	default:
		break;
	}
}
//----------查找函数------//
void find_train(train tra[],int n)
{
	int i;	
	char s1[10],s2[20];

	printf("1. 按车号查询\n");
    printf("2. 按终点站查询\n");
	scanf("%d",&i);
	switch(i)
	{
	case 1:
			printf("请输入车号：");
			scanf("%s",s1);
			for(i=0;i<=n;i++)
			{
			if(strcmp(s1,tra[i].number)==0)
			{
				printf("车号  |出发时间 | 总车程|起始站|终点站| 一等座票价| 一等座票数|二等座票价| 二等座票数\n");
				printf("%4s | %d : %d | %5d | %4s | %4s | %9.2f |%10d |%9.2f | %10d\n",tra[i].number,tra[i].hour,tra[i].minute,
					tra[i].time2,tra[i].start,
					tra[i].end,tra[i].type1.price,tra[i].type2.price);
			}
			}
			break;
	case 2:
			printf("请输入终点站：");
			scanf("%s",s2);
				for(i=0;i<=n;i++)
			{
			if(strcmp(s2,tra[i].end)==0)
			{
				printf("车号  |出发时间 | 总车程|起始站|终点站| 一等座票价| 一等座票数|二等座票价| 二等座票数\n");
				printf("%4s | %d : %d | %5d | %4s | %4s | %9.2f |%10d |%9.2f | %10d\n",tra[i].number,tra[i].hour,tra[i].minute,
					tra[i].time2,tra[i].start,
					tra[i].end,tra[i].type1.price,tra[i].type2.price);
			}
			}
			break;
	default:
			printf("输入错误!\n");
			break;
	}
}