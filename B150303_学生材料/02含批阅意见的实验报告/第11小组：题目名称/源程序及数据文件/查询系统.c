


#include "train.h"
#include <stdlib.h>
#include <windows.h>
#include <stdio.h>
//-----------��ʾ���г�����Ϣ--------//
void put(train tra[],int n)
{	
	
	int i;

	printf("����  |����ʱ�� | �ܳ���|��ʼվ|�յ�վ| һ����Ʊ��| һ����Ʊ��|������Ʊ��| ������Ʊ��");
	printf("\n");
	for(i=0;i<n;i++)
	{  	
		printf("%4s | %d : %d | %5d | %4s | %4s | %9.2f |%10d |%9.2f | %10d\n",tra[i].number,tra[i].hour,tra[i].minute,tra[i].time2,tra[i].start,tra[i].end,tra[i].type1.price,tra[i].type1.free,tra[i].type2.price,tra[i].type2.free);
	}
	
}
//-------------����������---------//
void calcurank(train tra[],int n)
{
	int i,j,temp,choice;
	train t;
	printf("��ѡ��Ҫ�������Ϣ��1��һ����Ʊ�ۣ�2���ܳ��̣�");
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
//----------���Һ���------//
void find_train(train tra[],int n)
{
	int i;	
	char s1[10],s2[20];

	printf("1. �����Ų�ѯ\n");
    printf("2. ���յ�վ��ѯ\n");
	scanf("%d",&i);
	switch(i)
	{
	case 1:
			printf("�����복�ţ�");
			scanf("%s",s1);
			for(i=0;i<=n;i++)
			{
			if(strcmp(s1,tra[i].number)==0)
			{
				printf("����  |����ʱ�� | �ܳ���|��ʼվ|�յ�վ| һ����Ʊ��| һ����Ʊ��|������Ʊ��| ������Ʊ��\n");
				printf("%4s | %d : %d | %5d | %4s | %4s | %9.2f |%10d |%9.2f | %10d\n",tra[i].number,tra[i].hour,tra[i].minute,
					tra[i].time2,tra[i].start,
					tra[i].end,tra[i].type1.price,tra[i].type2.price);
			}
			}
			break;
	case 2:
			printf("�������յ�վ��");
			scanf("%s",s2);
				for(i=0;i<=n;i++)
			{
			if(strcmp(s2,tra[i].end)==0)
			{
				printf("����  |����ʱ�� | �ܳ���|��ʼվ|�յ�վ| һ����Ʊ��| һ����Ʊ��|������Ʊ��| ������Ʊ��\n");
				printf("%4s | %d : %d | %5d | %4s | %4s | %9.2f |%10d |%9.2f | %10d\n",tra[i].number,tra[i].hour,tra[i].minute,
					tra[i].time2,tra[i].start,
					tra[i].end,tra[i].type1.price,tra[i].type2.price);
			}
			}
			break;
	default:
			printf("�������!\n");
			break;
	}
}