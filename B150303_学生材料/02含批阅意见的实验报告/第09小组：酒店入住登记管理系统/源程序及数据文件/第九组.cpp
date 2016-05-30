#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include<windows.h>
void Checkin( );
void Delete();
void modify();
void Room();
void informationservices( );
void ReadInfo();
void WriteInfo();
struct Check
{
	char id[20];											
	char name[20];												
	char sex[10];											
	char room[5];												
	char style[20] ;                                      	
	char  price[3];                                         	
    char  num[20];
	char  time[20];
	char checkintime[20];                                
};
struct Check guests[600];
int nums=0;
int searchbyroom(char no[])
{
	int i,k=1;
	for(i=0;i<nums;i++)
	{
		if(strcmp(guests[i].room,no)==0)
		{
			return i;
			k=0;
		}
	}
	if(k)
	{
		return -1;
	}
}
int searchbyname(char Name[])
{
	int i,k=1;
	for(i=0;i<nums;i++)
	{
		if(strcmp(guests[i].name,Name)==0)
		{
			return i;
			k=0;
		}
	}
	if(k)
	{
		return -1;
	}
}
void display()
{	
	system("cls");
	int i;
	do
	{
		system("cls");
		printf("\n\n   房号        姓名        性别        身份证号        \n");
		printf("-----------------------------------------------------------\n");
		for(i=0;i<nums;i++)
		printf("%10s%10s%10s%20s\n\n",guests[i].room,guests[i].name,guests[i].sex,guests[i].id);
		printf("-----------------------------------------------------------\n\n");
		printf("              留在此界面请按N，返回主界面按其他任意键");
	}
	while (getchar()=='N'||getchar()=='n');

system("cls");
}
void displaysingle(int index)
{
	printf("\n\n   房号        姓名        性别        身份证号        \n");
	printf("-----------------------------------------------------------\n");
	printf("   %10s%10s%10s%20s\n\n",guests[index].room,guests[index].name,guests[index].sex,guests[index].id);
	printf("-----------------------------------------------------------\n\n");
}
void main( )
{
   ReadInfo();
   while(1)
  {
	int m,b,x,h;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
	printf("\n\n\t\t------------欢迎来到**酒店-----------\n\n"); 
	printf("\t\t\t 1. 增加客户记录\n\n");
	printf("\t\t\t 2. 修改客户记录\n\n");
	printf("\t\t\t 3. 删除客户记录\n\n");
	printf("\t\t\t 4. 客户房间查询 \n\n");
	printf("\t\t\t 5. 客户信息查询 \n\n");  
	printf("\t\t\t 6. 输出所有客户 \n\n");
	printf("\t\t\t 0. 退出管理系统 \n\n");

	printf("\n\n&&&&&&&&&&&&&&&&&&&&&&&&############################&&&&&&&&&&&&&&&&&&&&&&&&&&\n\n");
	printf("\t\t\t 请选择您所需的服务: ");
    scanf("%d",&m);
	system("cls");
	switch(m)
	{
	case 1:
		{
			system("cls");
			while(1)
			{
				printf("\t\t   \n");
				printf("      ********        编号        房号        价格        ********\n");
				printf("*************************************************************************\n");
				printf("*************************************************************************\n");
				printf("      ********         1         单人间      150/夜       ********\n");
				printf("      ********         2         双人间      200/夜       ********\n");
				printf("      ********         3         标准间      300/夜       ********\n");
				printf("      ********         4         总统套房    600/夜       ********\n");
				printf("*************************************************************************\n");
				printf("*************************************************************************\n");
				printf("\t\t   \n");
				printf("              请选择预订种类的编号 1--4:");
				scanf("%d",&b);
				if(b>0&&b<5)
					break;
				else
				{
					system("cls");
					printf("\n\n          您的输入有错请您重新输入！\n");
				}
			}
			getchar();
			switch(b)
			{
				case 1:
					printf("              请输入预订天数:");
					scanf("%d",&x);
					printf("\n");
					printf("              预交款为%d元\n",x*150);
					printf("              1.确定       2.返回");
					scanf("%d",&h);
					printf("\n");
					  switch(h)
					  {case 1:
					{
						   
					       printf("              您已成功预订！\n");
						   printf("\n");
						   printf("可选房间列表   101--120\n");
						     Checkin();
					   }
					      
					break;
					  case 2:break;}
					  system("cls");
					  break;
				case 2:
					printf("              请输入预订天数:");
					scanf("%d",&x);
					printf("\n");
					printf("              预交款为%d元\n",x*200);
					printf("              1.确定       2.返回");
					scanf("%d",&h);
					printf("\n");
					 switch(h)
					 {case 1:
						{
						   
					       printf("              您已成功预订！\n");
						   printf("\n");
						   printf("可选房间列表   201--220\n");
						     Checkin();
					   }
					      
					break;
					 case 2:break;}
					 system("cls");
					 break;
				case 3:
					printf("              请输入预订天数:");
					scanf("%d",&x);
					printf("\n");
					printf("              预交款为%d元\n",x*300);
					printf("              1.确定       2.返回");
					scanf("%d",&h);
					 switch(h)
					 {case 1:
						{
						  
					       printf("              您已成功预订！\n");
						   printf("\n");
						   printf("可选房间列表   301--320\n");
						     Checkin();
					   }
					      
					break;
					 case 2:break;}
					 system("cls");
					 break;
				case 4:
					printf("              请输入预订天数:");
					scanf("%d",&x);
					printf("\n");
					printf("              预交款为%d元\n",x*600);
					printf("              1.确定       2.返回");
					scanf("%d",&h);
					printf("\n");
				 switch(h)
				 {
				   case 1:
					   {
						   
					       printf("              您已成功预订！\n");
						   printf("\n");
						   printf("可选房间列表   401--420\n");
						     Checkin();
					   }
					       break;
				 case 2:break;}
				 system("cls");
				 break;
			}
			
		}break;
	case 2:modify();break;
	case 3:Delete();break;
	case 4:Room();break;
	case 5:informationservices( );break;
	case 6:display();break;
	case 0:exit(0);
	default:printf("           您输入有误，请重新输入");
		system("cls");}
	WriteInfo();}
	getchar();
}
void Checkin( )
{
 while(1)
 {
	printf("\n");
	printf("              请输入房号:");
	scanf("%s",guests[nums].room);
	getchar();
	printf("\n");
	printf("              请输入姓名:");
	scanf("%s",guests[nums].name);
	getchar();
	printf("\n");
	printf("              请输入性别:");
	scanf("%s",guests[nums].sex);
	getchar();
	printf("\n");
	printf("              请输入身份证号:");
	scanf("%s",guests[nums].id);
	while(strlen(guests[nums].id)!=18)
	{
		printf("              请输入18位身份证号:");
		scanf("%s",guests[nums].id);
	}
	getchar();
	nums++;
	printf("\n");
	printf("              是否继续？请输入y/n");
  if(getchar()=='n'||getchar()=='N')
	  break;
 }
 system("cls");
}
void modify()
{
	while(1)
	{
		char no[20];
		int index;
		printf("\n请输入要修改的客户的房号:");
		scanf("%s",no);
		getchar();
		index=searchbyroom(no);
		if(index==-1)
			printf("该客户不存在！\n");
		else
		{
			system("cls");
			printf("你要修改的客户信息为:\n");
			displaysingle(index);
			printf("--- 请输入新值 ---\n\n");
			printf("请输入房号:");
			scanf("%s",guests[index].room);
			getchar();
			printf("请输入姓名:");
			scanf("%s",guests[index].name);
			getchar();
			printf("      请输入性别:");
			scanf("%s",guests[nums].sex);
			getchar();
			printf("      请输入身份证号:");
			scanf("%s",guests[nums].id);
			if(strlen(guests[nums].id)!=18)
			{
				printf("      请输入18位身份证号:");
				scanf("%s",guests[nums].id);
			}
			getchar();
		}
		printf("    是否继续？请输入y/n\n");
		if(getchar()=='n'||getchar()=='N')
		break;
	}
	system("cls");
}
void Delete()
{
	int i;
	while(1)
	{
		char no[20];
		int index;
		printf("\n请输入要删除的客户的房号:");
		scanf("%s",no);
		getchar();
		index=searchbyroom(no);
		if(index==-1)
			printf("该房间无客户居住！\n");
		else
		{
			system("cls");
			printf("你要删除的客户信息为:\n");
			displaysingle(index);
			printf("--- 是否真的要删除 (y/n)---\n");
			if(getchar()=='y')
			{
				for(i=index;i<nums-1;i++)
					guests[i]=guests[i+1];
				nums--;
			}
			getchar();
		}
		printf("    是否继续？请输入y/n\n");

		if(getchar()=='Y'||getchar()=='y')
		break;
	}
	system("cls");
}
void Room()
{
	while(1)
	{
		char no[20];
		char index;
		char a;
		printf("请输入要查询的房间号码:\n ");
		scanf("%s",no);
		 getchar();
		index=searchbyroom(no);
		if(index==-1)
			printf("该房间为空！\n");
		else
		{
			system("cls");
			printf("\t\t你要查询的客户信息为：\n");
            displaysingle(index);
		}
		printf("是否继续？（y/n)");
		scanf("%s",&a);
		if(a=='n'||a=='N')
			break;
	}
	system("cls");
}
void informationservices( )
{
	while(1)
	{
		char Name[20];
		int  index;
		char a;
		printf("\t##########请输入您的姓名##########\n\n");
		scanf("%s",Name);
		getchar();
		index=searchbyname(Name);
		if(index==-1)
			printf("该用户不存在！\n");
		else
		{
			system("cls");
			printf("\t您要查询的客户信息为\n");
			displaysingle(index);
		}
		printf("是否继续？y/n\n");
		scanf("%s",&a);
		if(a=='n'||a=='N')
			break;
	}
	system("cls");
}

void ReadInfo()
{	FILE *fp;
	int i;
	if((fp=fopen("D://CXSJ.txt","rb"))==NULL)
	{
		printf("无文件信息!\n");
		return;
	}
	if(fread(&nums,sizeof(int),1,fp)!=1)
		nums=-1;
	else
		for(i=0;i<nums;i++)
			fread(&guests[i],sizeof(struct Check),1,fp);
		fclose(fp);
}
void WriteInfo()
{
	FILE *fp;
	int i;
	if((fp=fopen("D://CXSJ.txt","wb"))==NULL)
	{
		printf("无文件信息!\n");
		return;
	}
	if(fwrite(&nums,sizeof(int),1,fp)!=1)
		printf("写入文件错误!\n");
	for(i=0;i<nums;i++)
		if(fwrite(&guests[i],sizeof(struct Check),1,fp)!=1)
			printf("写入文件错误！\n");
	fclose(fp);
}
