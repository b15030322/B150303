
#include "train.h"
#include <stdlib.h>
#include <windows.h>
#include <stdio.h>
//------------�ͻ���Ʊ����----------//
void book(train tra[],int n)
{
	int i,count,choice;
	char num[10];
	count=0;
	system("cls");
	printf("������Ҫ��Ʊ���г���");
	scanf("%s",num);
	printf("��ѡ��Ҫ����Ʊ���ͣ�1��һ������2��������");
	scanf("%d",&choice);
		switch(choice)
	{
		case 1:
			for(i=0;i<=n;i++)
		{
			if(strcmp(num,tra[i].number)==0)
			{
				tra[i].type1.free--;
				printf("�ɹ���Ʊ\n");
				break;			
			}
			else
				count++;
		
		}
		if(count==n)
			printf("��ѯ�޴˳�����Ϣ");
		break;
		case 2:
			for(i=0;i<=n;i++)
		{
			if(strcmp(num,tra[i].number)==0)
			{
				tra[i].type2.free--;
				printf("�ɹ���Ʊ\n");
				break;			
			}
			else
				count++;
		
		}
		if(count==n)
			printf("��ѯ�޴˳�����Ϣ");
		break;
		default:
			break;
	}
		saveFile(tra,n);
}
//-------------��Ʊ����-----//
void cancle(train tra[],int n)
{
	int i,count,choice;
	char s[10];
	count=0;
	printf("������Ҫ��Ʊ�İ��:");
	scanf("%s",s);
	printf("��ѡ��Ҫ��Ʊ���ͣ�1��һ������2��������");
	scanf("%d",&choice);
		switch(choice)
	{
		case 1:
			for(i=0;i<=n;i++)
		{
			if(strcmp(s,tra[i].number)==0)
			{
				tra[i].type1.free++;
				printf("�ɹ���Ʊ\n");
				break;			
			}
			else
				count++;
		
		}
		if(count==n)
			printf("��ѯ�޴˳�����Ϣ");
		break;
		case 2:
			for(i=0;i<=n;i++)
		{
			if(strcmp(s,tra[i].number)==0)
			{
				tra[i].type2.free++;
				printf("�ɹ���Ʊ\n");
				break;			
			}
			else
				count++;
		
		}
		if(count==n)
			printf("��ѯ�޴˳�����Ϣ");
		break;
		default:
			break;
	}
	saveFile(tra,n);
}
//-----------------ע�ắ��-------------//
void UserReg()
{
	FILE *fp;
	char Linedata[50]={0},User[20],Pass[20];
	fp = fopen("D:\\�����ϻ�\\C�����ļ�\\user.txt","a+");
	if(fp==0)
	{
		printf("file error\n");
		exit(1);
	}
	printf("Registered Account:\n");
	printf("�������û���:\n");
	fflush(stdin);
	gets(User);
	printf("����������:\n");
	fflush(stdin);
	gets(Pass);
	strcat(Pass,"\n");
	strcpy(Linedata,User);
	strcat(Linedata,",");
	strcat(Linedata,Pass);
	strcat(Linedata,"\n");
	fputs(Linedata,fp);
	fclose(fp);
	printf("Registered Success!\n");	
}
//---------------��¼����---------------//
int Login()
{
	FILE *fp;
	int find=0;
	char User[20],Pass[20],Userstrcat[50]={0};
	char Userdata[50]={0};
	fp = fopen("D:\\�����ϻ�\\C�����ļ�\\user.txt","r");
	if(fp==0)
	{
		printf("file error\n");
		exit(1);
	}
	printf("Login Account:\n");
	printf("�������û���:\n");
	fflush(stdin);
	gets(User);
	printf("����������:\n");
	fflush(stdin);
	gets(Pass);
	strcpy(Userstrcat,User);
	strcat(Userstrcat,",");
	strcat(Userstrcat,Pass);
	strcat(Userstrcat,"\n");
	while (!feof(fp))
	{
		fgets(Userdata,19,fp);
		if (strcmp(Userdata,Userstrcat)==0 )
		{
			printf("OK!Login Success!\n");
			printf("Welcome back,%s!\n",User);
			find=1;
			break;
		}
	}
	if (!find)
	{
		printf("Username or Password incorrect!\n");
	}
	fclose(fp);
	return find;
}