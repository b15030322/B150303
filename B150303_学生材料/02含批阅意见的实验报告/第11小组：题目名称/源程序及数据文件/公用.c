
#include "train.h"
#include <stdlib.h>
#include <windows.h>
#include <stdio.h>
//-----------空格控制----------//
void space()
{	int j;
	for(j=1;j<15;j++)
	    printf("\n");
}
//---------管理员密码输入----------//
int check()
{
	
	char password[6];
	int i,n,flag;
	char m[6]={'L','S','J','2','3','3'};
	system("cls");//清屏
	printf("请输入管理员密码：");
	for(i=0;i<6;i++)
	{	n=i;
		password[i]=getch();
		if(password[i]=='\b')
		{	
			i=i-2;
		    printf("\b");
			printf(" ");
		}
		if(n==i)
		{
			printf("*");
		}
		else 
		{
			printf("\b");
		}
	}
	printf("\n");
	for(flag=1,n=0;flag!=0&&n<7;n++)
		if(password[n]!=m[n])
			flag=0;
		else
			n++;
    if(flag)
		printf("correct!");
	else
		printf("error!");
return flag;
}
//--------------一级主菜单---------------//
int runmenu(train tra[],int choice,int n)
{
    int j;
	system("cls");//清屏
	for(j=1;j<10;j++)
	    printf("\n");//控制空格
	switch(choice)
	{
	case 1:
			n=managermenu(tra,n);
				break;
	case 2:
			searchmenu(tra,n);
				break;
	case 3:
			operatemenu(tra,n);
				break;
    case 0:break;
	}
	return n;
}
//----------------------封面显示---------------//
void cover()
{   int i,j;
    for(i=1;i<40;i++)
		printf("---");//排头页面设置
	for(j=1;j<12;j++)
	    printf("\n");//控制空格
	//火车吉祥物图片
	printf("\t\t\t\t\t-----------------------------------------------------------------------------\n");
	printf("\t\t\t\t       /\n");
    printf("\t\t\t\t      /     ┏━┓    ┏━┓    ┏━┓    ┏━┓   ┏━┓   ┏━┓    \n");
	printf("\t\t\t\t     /      ┃  ┃    ┃  ┃    ┃  ┃    ┃  ┃   ┃  ┃   ┃  ┃\n");
	printf("\t\t\t\t    /       ┗━┛    ┗━┛    ┗━┛    ┗━┛   ┗━┛   ┗━┛\n");
	printf("\t\t\t\t   /    (*^__^*)老司机号\n");
	printf("\t\t\t\t   ---------------------------------------------------------------------------------\n");
	Sleep(2000);//延时
    system("cls");//清屏
}
//------------------二级管理员菜单------------//
int managermenu(train tra[],int n)
{	
	int choice;
	train t;
	if(check())
	{
		do
	{			
		smenuone();
		scanf("%d",&choice);
		if(choice<=3&&choice>=0)
		{	
				switch (choice)
			{
				case 1: system("cls");//清屏				
						n=add(tra,n,t);
						break;
				case 2: system("cls");//清屏	
						printf("请出入要修改的车号\n");
						scanf("%s",t.number);
						system("cls");//清屏
						modify(tra,n,t);
						break;
				case 3: system("cls");//清屏			
						printf("请出入要删除的车号\n");
						scanf("%s",t.number);
						system("cls");//清屏
						n=del(tra,n,t);												
				case 0: break;
			}
		}      		
		else 
			printf("\t\t\t\t\t错误，请检查后再一次输入！\n");	
	}while (choice);
	}
	else
	{
	  printf("密码有误，将返回上一级菜单");
	  Sleep(2000);//延时
	}
	return n;
}
//------------------二级查询菜单--------------//
void searchmenu(train tra[],int n)
{   
	int choice;
	do
	{
		smenutwo();
		scanf("%d",&choice);
		if(choice<=3&&choice>=0)
		switch (choice)
		{
		case 1: 
				system("cls");//清屏
				put(tra,n);
			break;
		case 2:	system("cls");//清屏 
				calcurank(tra,n);
			break;
		case 3:
			system("cls");//清屏
			find_train(tra,n);
			break;
		case 0: break;
		}
        
	else 
		printf("\t\t\t\t\t错误，请检查后再一次输入！\n");
	
	}while (choice);
}
//--------------二级客户菜单---------------//
void operatemenu(train tra[],int n)
{
	int choice;
	do
	{
    smenuthree();
	scanf("%d",&choice);
	if(choice<=3&&choice>=0)
	switch (choice)
	{
	case 1: system("cls");//清屏
			UserReg();
			break;
    case 2: system("cls");//清屏
			if(Login())
			{
				book(tra,n);
			}
			else
					printf("密码有误，将返回上一级菜单");
				    Sleep(2000);//延时
			break;
	case 3: system("cls");//清屏
			if(Login())
			{
				cancle(tra,n);
			}
			else
					printf("密码有误，将返回上一级菜单");
				    Sleep(2000);//延时cancle(tra);
			break;
	case 0: break;
	}
        
	else 
		printf("\t\t\t\t\t错误，请检查后再一次输入！\n");
	
	}while (choice);
}

void fmenu()
{		
		printf("\t\t ╭═════════■□■□═══╮\n");  
        printf("\t\t│         老司机火车管理系统       │\n");  
        printf("\t\t╰═══■□■□══════════╯\n");  
        printf("\t\t   ┌─────────────-┐\n");  
        printf("\t\t   │ 1. 管理员管理系统         │\n");  
        printf("\t\t   │                           │\n");  
        printf("\t\t   │ 2. 车票管理系统           │\n");  
        printf("\t\t   │                           │\n");  
        printf("\t\t   │ 3. 客户系统               │\n");  
        printf("\t\t   │                           │\n");  
        printf("\t\t   │ 0. 退出程序               │\n");  
        printf("\t\t   └─────────────-┘\n");  

 //菜单选择
	printf("\t\t\t\t\t请在此处选择菜单:");
}
void smenuone()
{	
		space();
		printf("\t\t   ┌─────────────-┐\n");    
		printf("\t\t   │   ★欢迎进入管理系统      │\n");
		printf("\t\t   │   ★请选择管理功能        │\n");
		printf("\t\t   │1.添加车次信息             │\n");
		printf("\t\t   │2.修改车次信息             │\n");
		printf("\t\t   │3.删除车次信息             │\n");
		printf("\t\t   │0.返回上一级菜单           │\n");
		printf("\t\t   └─────────────-┘\n");  

 //菜单选择
	printf("\t\t\t\t\t请在此处选择菜单:");
}
void smenutwo()
{	
		space();
		printf("\t\t   ┌──────────────┐\n");    
		printf("\t\t   │   ★欢迎进入车票系统       │\n");
		printf("\t\t   │   ★请选择管理功能         │\n");
		printf("\t\t   │1.显示所有车次信息          │\n");
 		printf("\t\t   │2.票价/车程排序信息         │\n");
		printf("\t\t   │3.查询车次信息              │\n");
		printf("\t\t   │0.返回上一级菜单            │\n");
		printf("\t\t   └──────────────┘\n");  

	printf("\t\t\t\t\t请在此处选择菜单:");
}
void smenuthree()
{	
		space();
		printf("\t\t   ┌─────────────-┐\n");    
		printf("\t\t   │   ★欢迎进入订退系统      │\n");
		printf("\t\t   │   ★请选择管理功能        │\n");
		printf("\t\t   │1.客户注册                 │\n");		
		printf("\t\t   │2.客户订票操作             │\n");
		printf("\t\t   │3.客户退票操作             │\n");
		printf("\t\t   │0.返回上一级菜单           │\n");
		printf("\t\t   └─────────────-┘\n");  

	//菜单选择
	printf("\t\t\t\t\t请在此处选择菜单:");
}
