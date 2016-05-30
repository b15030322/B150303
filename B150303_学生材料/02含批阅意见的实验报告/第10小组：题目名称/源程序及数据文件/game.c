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
	printf("%4s%10s%6s%20s%10s%6s%6s%6s%6s%6s\n","���","����","��λ","����","���","����","Ӣ�۳���","Ӣ��ʤ��","����ɱ��","��������");
}

void menu( )
{
	printf("\t\t***** 1.Ӣ������     ******\n"); 
	printf("\t\t***** 2.Ӣ����Ϣ���� ******\n");
	printf("\t\t***** 3.Ӣ����Ϣ��ѯ ******\n");
	printf("\t\t***** 4.����ͳ��     ******\n");
	printf("\t\t***** 0.�˳�ϵͳ     ******\n");
}

void menuBase( )
{
	printf("\t\t##### 1.����Ӣ�ۼ�¼ ######\n");
	printf("\t\t##### 2.ɾ��Ӣ�ۼ�¼ ######\n");
	printf("\t\t##### 3.�޸�Ӣ�ۼ�¼ ######\n");
	printf("\t\t##### 0.������һ��   ######\n");
}

void menuSearch( )
{
	printf("\t\t&&&&& 1.��Ӣ�۱�Ų�ѯ &&&&&&\n");
	printf("\t\t&&&&& 2.��Ӣ�����Ʋ�ѯ   &&&&&&\n");
	printf("\t\t&&&&& 0.������һ��       &&&&&&\n");
}

void menuStatistics( )
{
	printf("\t\t@@@@@ 1.ͳ��Ӣ��ʤ������ @@@@@@\n");
	printf("\t\t@@@@@ 0.������һ��       @@@@@@\n");
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
		case 1:printf("����Ӣ�۱�Ų�ѯ��\n");
			scanf("%s",&h.num);
			break;
		case 2:printf("����Ӣ�����Ʋ�ѯ��\n");
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
				printf("Ӣ�۲�ѯ����\n");
		}
	}while (choice);
}

void statisticsManage(Hero hero[],int n)
{
	int choice;
	do
	{
		menuStatistics( );
		printf("��ѡ����Ҫͳ�Ƶ�������Ϣ��\n");
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