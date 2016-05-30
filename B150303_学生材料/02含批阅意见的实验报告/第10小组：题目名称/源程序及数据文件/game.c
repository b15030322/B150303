#include<stdio.h>
#include<stdlib.h>
#include"file.h"
#include"hero.h"
/*#define NUM 20
struct Hero
{
	char name [20];
	char skill [20];
	char character[20];
	char partner[20];
	char rival[20];
	int wins;
	int appearance;
	int rank;
	int kill;
	int death;
};
typedef struct Hero Hero;*/
void printHead()
{
	printf("%4s%10s%6s%20s%10s%6s%6s%6s%6s%6s\n","编号","名称","定位","技能","组合","克制","英雄出场","英雄胜场","场均杀敌","场均死亡");
}

void menu( )
{
	printf("\t\t***** 1.英雄总览     ******\n"); 
	printf("\t\t***** 2.英雄信息管理 ******\n");
	printf("\t\t***** 3.英雄信息查询 ******\n");
	printf("\t\t***** 4.赛季统计     ******\n");
	printf("\t\t***** 0.退出系统     ******\n");
}

void menuBase( )
{
	printf("\t\t##### 1.插入英雄记录 ######\n");
	printf("\t\t##### 2.删除英雄记录 ######\n");
	printf("\t\t##### 3.修改英雄记录 ######\n");
	printf("\t\t##### 0.返回上一级   ######\n");
}

void menuSearch( )
{
	printf("\t\t&&&&& 1.按英雄编号查询 &&&&&&\n");
	printf("\t\t&&&&& 2.按英雄名称查询   &&&&&&\n");
	printf("\t\t&&&&& 0.返回上一级       &&&&&&\n");
}

void menuStatistics( )
{
	printf("\t\t@@@@@ 1.统计英雄胜率排行 @@@@@@\n");
	printf("\t\t@@@@@ 0.返回上一级       @@@@@@\n");
}

int baseManage(Hero hero[],int n)
{
	int choice,t,find[NUM];
	Hero h;
		do
	{
		menuBase( );
		printf("choose one operation you want to do:\n");
		scanf("%d",&choice);
			switch(choice)
		{
		case 1:readHero(&h,1);
			n=insertHero(hero,n,h);
			break;
		case 2:printf("Input the name deleted\n");
			scanf("%s",&h.name);
			n=deleteHero(hero,n,h);
			break;
		case 3:printf("Input the name modified\n");
			scanf("%s",&h.name);
			t=searchHero(hero,n,h,1,find);
			if(t)
			{
				readHero(&h,1);
				hero[find[0]]=h;
			}
			else
				printf("this hero is not in,can not be modified.\n");
		case 0:break;
		}
	}while(choice);
	return n;
}

void searchManage(Hero hero[],int n)
{
	int choice, i,findnum,f[NUM];
	Hero h;
	do
	{
		menuSearch();
		printf("Choose one operation you want to do:\n");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:printf("输入英雄编号查询：\n");
			scanf("%s",&h.num);
			break;
		case 2:printf("输入英雄名称查询：\n");
			scanf("%s",h.name);
			break;
		case 0:break;
		}
		if (choice>=1&&choice<=2)
		{
			findnum=searchHero(hero,n,h,choice,f);
			if (findnum)
			{
				printHead();
				for (i=0;i<findnum;i++)
					printHero(&hero[f[i]],1);
			}
			else
				printf("英雄查询错误！\n");
		}
	}while (choice);
}

void statisticsManage(Hero hero[],int n)
{
	int choice;
	do
	{
		menuStatistics( );
		printf("请选择需要统计的赛季信息：\n");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:calcuRank(hero,n);
			break;
		case 0:break;
		}
	}while(choice);
}

int runMain(Hero hero[],int n,int choice)
{
switch(choice)
		{
			case 1:printHead();
				printHero(hero,n);
				break;
			case 2:n=baseManage(hero,n);
				break;
			case 3:searchManage(hero,n);
				break;
			case 4:menuStatistics(hero,n);
				break;
			case 0:	break;
		}
	return n;
}

int main()
{
	Hero hero[NUM];
	int choice,n;
	n=readFile(hero);
	if(!n)
	{
		n=createFile(hero);
	}
	do
	{
		menu();
		printf("Please input your choice: ");
		scanf("%d",&choice);
		if (choice>=0&&choice<=4)
			runMain(hero,n,choice);
		else
			printf("error input,please input your choice again!\n");
	} while (choice);
	saveFile(hero,n);
	return 0;
}