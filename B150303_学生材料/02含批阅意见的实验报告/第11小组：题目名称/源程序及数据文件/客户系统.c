
#include "train.h"
#include <stdlib.h>
#include <windows.h>
#include <stdio.h>
//------------客户订票函数----------//
void book(train tra[],int n)
{
	int i,count;
	char num[10];
	count=0;
	system("cls");
	printf("请输入要订票的列车号");
	scanf("%s",num);
	for(i=0;i<=n;i++)
	{
		if(strcmp(num,tra[i].number)==0)
		{
			tra[i].type1.free--;
			printf("成功订票");
			break;			
		}
		else
			count++;
		
	}
	if(count==n)
		printf("查询无此车次信息");
	saveFile(tra,n);
}
//-------------退票函数-----//
void cancle(train tra[],int n)
{
	int i,count;
	char s[10];
	count=0;
	printf("请输入要退票的班次:");
	scanf("%s",s);
	for(i=0;i<n;i++)
	{
		if(strcmp(s,tra[i].number)==0)
		{	
			tra[i].type1.free++;
			 printf("退票成功!\n");
			break;
		}
		else
		{	
			count++;	
		}
	}
	if(count==n)
		printf("查询无此车次信息");
	saveFile(tra,n);
}
//-----------------注册函数-------------//
void UserReg()
{
	FILE *fp;
	char Linedata[50]={0},User[20],Pass[20];
	fp = fopen("D:\\程序上机\\C语言文件\\user.txt","a+");
	if(fp==0)
	{
		printf("file error\n");
		exit(1);
	}
	printf("Registered Account:\n");
	printf("请输入用户名:\n");
	fflush(stdin);
	gets(User);
	printf("请输入密码:\n");
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
//---------------登录函数---------------//
int Login()
{
	FILE *fp;
	int find=0;
	char User[20],Pass[20],Userstrcat[50]={0};
	char Userdata[50]={0};
	fp = fopen("D:\\程序上机\\C语言文件\\user.txt","r");
	if(fp==0)
	{
		printf("file error\n");
		exit(1);
	}
	printf("Login Account:\n");
	printf("请输入用户名:\n");
	fflush(stdin);
	gets(User);
	printf("请输入密码:\n");
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