
#include "train.h"
#include <stdlib.h>
#include <windows.h>
#include <stdio.h>
int read(train tra[])
{
	int i,n;
	printf("������˴�Ҫ¼��ĳ���������");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("����������������Ϣ\n");
		printf("�����복��:\n");
		scanf("%s",tra[i].number);
		printf("���������Сʱʱ��:\n");
		scanf("%d",&tra[i].hour);
		printf("�������������ʱ��:\n");
		scanf("%d",&tra[i].minute);
		printf("�������ܳ���\n");
		scanf("%d",&tra[i].time2);
		printf("��������ʼվ\n");
		scanf("%s",&tra[i].start);
		printf("�������յ�վ\n");
		scanf("%s",&tra[i].end);
		printf("������һ����Ʊ��\n");
		scanf("%f",&tra[i].type1.price);
		printf("������һ����Ʊ��\n");
		scanf("%d",&tra[i].type1.free);
		printf("�����������Ʊ��\n");
		scanf("%f",&tra[i].type2.price);
		printf("�����������Ʊ��\n");
		scanf("%d",&tra[i].type2.free);
	}
	return n;
}
//--------------¼�뺯��-----------//
int add(train tra[],int n,train t)
{	int i,j;
	i=0;
	printf("������˴�Ҫ¼��ĳ���������");
	scanf("%d",&j);
	for(;i<j;i++)
	{
		printf("����������������Ϣ\n");
		printf("�����복��:\n");
		scanf("%s",t.number);
		printf("���������Сʱʱ��:\n");
		scanf("%d",&t.hour);
		printf("�������������ʱ��:\n");
		scanf("%d",&t.minute);
		printf("�������ܳ���\n");
		scanf("%d",&t.time2);
		printf("��������ʼվ\n");
		scanf("%s",&t.start);
		printf("�������յ�վ\n");
		scanf("%s",&t.end);
		printf("������һ����Ʊ��\n");
		scanf("%f",&t.type1.price);
		printf("������һ����Ʊ��\n");
		scanf("%d",&t.type1.free);
		printf("�����������Ʊ��\n");
		scanf("%f",&t.type2.price);
		printf("�����������Ʊ��\n");
		scanf("%d",&t.type2.free);
		tra[n]=t;
		n++;
		
	}
	saveFile(tra,n);
	return n;
}
//------------�޸ĺ���------//
void modify(train tra[],int n,train t)
{	
	int i,count;
	
	for(i=0;i<n;i++)
	{
		if(strcmp(t.number,tra[i].number)==0)
		{
		printf("�����복��:\n");
		scanf("%s",tra[i].number);
		printf("���������Сʱʱ��:\n");
		scanf("%d",&tra[i].hour);
		printf("�������������ʱ��:\n");
		scanf("%d",&tra[i].minute);
		printf("�������ܳ���\n");
		scanf("%d",&tra[i].time2);
		printf("��������ʼվ\n");
		scanf("%s",&tra[i].start);
		printf("�������յ�վ\n");
		scanf("%s",&tra[i].end);
		printf("������һ����Ʊ��\n");
		scanf("%f",&tra[i].type1.price);
		printf("������һ����Ʊ��\n");
		scanf("%d",&tra[i].type1.free);
		printf("�����������Ʊ��\n");
		scanf("%f",&tra[i].type2.price);
		printf("�����������Ʊ��\n");
		scanf("%d",&tra[i].type2.free);
		}
		else count++;
	}
	if(count==n-1)
	{
		printf("���Ҳ����ó���");
	}
	saveFile(tra,n);
}
//----------ɾ������---------//
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
		printf("���Ҳ����ó���");
	}
	for(j=i;j<n-1;j++)
	{
		tra[j]=tra[j+1];
	}
	n--;
	saveFile(tra,n);
	return n;
}