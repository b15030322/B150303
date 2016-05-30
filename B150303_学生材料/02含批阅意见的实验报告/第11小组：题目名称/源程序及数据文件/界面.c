
#include <stdlib.h>
#include <windows.h>
#include <stdio.h>
int runmenu(int choice);
void managermenu();
void searchmenu();
void operatemenu();
void fmenu();
void smenuone();
void smenutwo();
void smenuthree();
void cover();
int main()
{
	int i,j,choice;
	cover();	
	for(i=1;i<40;i++)
		printf("***");
	printf("\n");
	for(i=1;i<40;i++)
		printf("---");	//页眉设计
	for(j=1;j<10;j++)
	    printf("\n");
do
{
	fmenu();
	scanf("%d",&choice);
	if(choice<=5&&choice>=0)
        runmenu(choice);
	else 
		printf("\t\t\t\t\t错误，请检查后再一次输入！\n");
    system("cls");//清屏
	for(j=1;j<8;j++)
	    printf("\n");//空格控制
}while(choice);
	return 0;
}
int runmenu(int choice)
{
    int j;
	system("cls");//清屏
	for(j=1;j<10;j++)
	    printf("\n");//控制空格
	switch(choice)
	{
	case 1:managermenu();
		   break;
	case 2:searchmenu();
		   break;
	case 3:operatemenu();
		   break;
    case 0:break;
	}
	return 0;
}
void cover()
{   int i,j;
    for(i=1;i<40;i++)
		printf("---");//排头页面设置
	for(j=1;j<6;j++)
	    printf("\n");//控制空格
	//火车吉祥物图片
	printf("\t\t\t\t\t-----------------------------------------------------------------------------\n");
	printf("\t\t\t\t       /\n");
    printf("\t\t\t\t      /     ┏━┓    ┏━┓    ┏━┓    ┏━┓   ┏━┓   ┏━┓    \n");
	printf("\t\t\t\t     /      ┃  ┃    ┃  ┃    ┃  ┃    ┃  ┃   ┃  ┃   ┃  ┃\n");
	printf("\t\t\t\t    /       ┗━┛    ┗━┛    ┗━┛    ┗━┛   ┗━┛   ┗━┛\n");
	printf("\t\t\t\t   /    (*^__^*)老司机号\n");
	printf("\t\t\t\t   ---------------------------------------------------------------------------------\n");
	for(j=1;j<5;j++)
	    printf("\n");//官方吐槽
	printf("\t\t\t\t︿(￣︶￣)︽(￣︶￣)︿飞.飞.\n");
	printf("\t\t\t\t昨晚github下载好难啊╭(﹊∩∩﹊#)\n");
	printf("\t\t\t\t<(︶︿︶)_╭∩╮╭∩╮(*+﹏+*)~ 受不了！\n");
	printf("\t\t\t\t车票系统好难啊！~>_<~(┬＿┬)\n");
	printf("\t\t\t\t(￣︶￣)↗有度娘！<<(￣▽￣)>>\n");
	for(j=1;j<6;j++)
	    printf("\n");//空格控制
    printf("\t\t\t\t\t\t欢迎来到老司机车票管理系统\n");
	for(i=1;i<40;i++)
		printf("---");
	Sleep(2000);//延时
    system("cls");//清屏
}
void managermenu()
{
	int choice;
	do
	{
    smenuone();
	scanf("%d",&choice);
	if(choice<=3&&choice>=0)
	switch (choice)
	{
	case 1: //add()
		break;
    case 2: //modify()
		break;
	case 3: //del()
		break;
	case 0: break;
	}
        
	else 
		printf("\t\t\t\t\t错误，请检查后再一次输入！\n");
	
	}while (choice);
}
void searchmenu()
{   
	int choice;
	do
	{
    smenutwo();
	scanf("%d",&choice);
	if(choice<=3&&choice>=0)
	switch (choice)
	{
	case 1: //remain()
		break;
    case 2: //price()
		break;
	case 3: //opentime()
		break;
	case 0: break;
	}
        
	else 
		printf("\t\t\t\t\t错误，请检查后再一次输入！\n");
	
	}while (choice);
}
void operatemenu()
{
	int choice;
	do
	{
    smenuthree();
	scanf("%d",&choice);
	if(choice<=3&&choice>=0)
	switch (choice)
	{
	case 1: //client()
		break;
    case 2: //cancleorbook()
		break;
	case 3: //time()
		break;
	case 0: break;
	}
        
	else 
		printf("\t\t\t\t\t错误，请检查后再一次输入！\n");
	
	}while (choice);
}

void fmenu()
{	
	printf("\t\t\t\t\t****************************************************\n");
    printf("\t\t\t\t\t*************1.管理员管理系统      *****************\n");
    printf("\t\t\t\t\t*************2.车票管理系统        *****************\n");
    printf("\t\t\t\t\t*************3.客户退订票管理系统  *****************\n");
	printf("\t\t\t\t\t*************0.退出                *****************\n");
    printf("\t\t\t\t\t****************************************************\n");
 //菜单选择
	printf("\t\t\t\t\t请在此处选择菜单:");
}
void smenuone()
{
    printf("\t\t\t\t\t****************************************************\n");
    printf("\t\t\t\t\t*************1.添加车次信息        *****************\n");
    printf("\t\t\t\t\t*************2.修改车次信息        *****************\n");
    printf("\t\t\t\t\t*************3.删除车次信息        *****************\n");
	printf("\t\t\t\t\t*************0.返回上一级菜单      *****************\n");
    printf("\t\t\t\t\t****************************************************\n");
 //菜单选择
	printf("\t\t\t\t\t请在此处选择菜单:");
}
void smenutwo()
{
	printf("\t\t\t\t\t****************************************************\n");
    printf("\t\t\t\t\t*************1.剩余票数信息        *****************\n");
    printf("\t\t\t\t\t*************2.车次票价信息        *****************\n");
    printf("\t\t\t\t\t*************3.出发时间车次信息    *****************\n");
	printf("\t\t\t\t\t*************0.返回上一级菜单      *****************\n");
    printf("\t\t\t\t\t****************************************************\n");
	//菜单选择
	printf("\t\t\t\t\t请在此处选择菜单:");
}
void smenuthree()
{
	printf("\t\t\t\t\t****************************************************\n");
    printf("\t\t\t\t\t*************1.客户信息确认        *****************\n");
    printf("\t\t\t\t\t*************2.客户退订票操作      *****************\n");
    printf("\t\t\t\t\t*************3.车程总时间查询      *****************\n");
	printf("\t\t\t\t\t*************0.返回上一级菜单      *****************\n");
    printf("\t\t\t\t\t****************************************************\n");
	//菜单选择
	printf("\t\t\t\t\t请在此处选择菜单:");
}