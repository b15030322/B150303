
#include "train.h"
#include <stdlib.h>
#include <windows.h>
#include <stdio.h>
int read(train tra[])
{
	int i,n;
	printf("请输入此次要录入的车次数量：");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("请输入新增车次信息\n");
		printf("请输入车号:\n");
		scanf("%s",tra[i].number);
		printf("请输入出发小时时间:\n");
		scanf("%d",&tra[i].hour);
		printf("请输入出发分钟时间:\n");
		scanf("%d",&tra[i].minute);
		printf("请输入总车程\n");
		scanf("%d",&tra[i].time2);
		printf("请输入起始站\n");
		scanf("%s",&tra[i].start);
		printf("请输入终点站\n");
		scanf("%s",&tra[i].end);
		printf("请输入一等座票价\n");
		scanf("%f",&tra[i].type1.price);
		printf("请输入一等座票数\n");
		scanf("%d",&tra[i].type1.free);
		printf("请输入二等座票价\n");
		scanf("%f",&tra[i].type2.price);
		printf("请输入二等座票数\n");
		scanf("%d",&tra[i].type2.free);
	}
	return n;
}
//--------------录入函数-----------//
int add(train tra[],int n,train t)
{	int i,j;
	i=0;
	printf("请输入此次要录入的车次数量：");
	scanf("%d",&j);
	for(;i<j;i++)
	{
		printf("请输入新增车次信息\n");
		printf("请输入车号:\n");
		scanf("%s",t.number);
		printf("请输入出发小时时间:\n");
		scanf("%d",&t.hour);
		printf("请输入出发分钟时间:\n");
		scanf("%d",&t.minute);
		printf("请输入总车程\n");
		scanf("%d",&t.time2);
		printf("请输入起始站\n");
		scanf("%s",&t.start);
		printf("请输入终点站\n");
		scanf("%s",&t.end);
		printf("请输入一等座票价\n");
		scanf("%f",&t.type1.price);
		printf("请输入一等座票数\n");
		scanf("%d",&t.type1.free);
		printf("请输入二等座票价\n");
		scanf("%f",&t.type2.price);
		printf("请输入二等座票数\n");
		scanf("%d",&t.type2.free);
		tra[n]=t;
		n++;
		
	}
	saveFile(tra,n);
	return n;
}
//------------修改函数------//
void modify(train tra[],int n,train t)
{	
	int i,count;
	
	for(i=0;i<n;i++)
	{
		if(strcmp(t.number,tra[i].number)==0)
		{
		printf("请输入车号:\n");
		scanf("%s",tra[i].number);
		printf("请输入出发小时时间:\n");
		scanf("%d",&tra[i].hour);
		printf("请输入出发分钟时间:\n");
		scanf("%d",&tra[i].minute);
		printf("请输入总车程\n");
		scanf("%d",&tra[i].time2);
		printf("请输入起始站\n");
		scanf("%s",&tra[i].start);
		printf("请输入终点站\n");
		scanf("%s",&tra[i].end);
		printf("请输入一等座票价\n");
		scanf("%f",&tra[i].type1.price);
		printf("请输入一等座票数\n");
		scanf("%d",&tra[i].type1.free);
		printf("请输入二等座票价\n");
		scanf("%f",&tra[i].type2.price);
		printf("请输入二等座票数\n");
		scanf("%d",&tra[i].type2.free);
		}
		else count++;
	}
	if(count==n-1)
	{
		printf("查找不到该车次");
	}
	saveFile(tra,n);
}
//----------删除函数---------//
int del(train tra[],int n,train t)
{

	int i,j,count;
	for(i=0;i<n;i++)
	{
		if(strcmp(t.number,tra[i].number)==0)
		{
			break;
		}
		else
		{
			count++;
		}
	}
	if(count==n-1)
	{
		printf("查找不到该车次");
	}
	for(j=i;j<n-1;j++)
	{
		tra[j]=tra[j+1];
	}
	n--;
	saveFile(tra,n);
	return n;
}