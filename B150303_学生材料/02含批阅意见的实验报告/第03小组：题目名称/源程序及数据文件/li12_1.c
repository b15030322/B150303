#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<conio.h>


#include "SeqList.h"
#include"file.h"
# define MaxSize 200


int PASS;           
SeqList queueList;
//ListInitiate(&queueList);

int num1=0;          //订票客户人数
int num2=0;          //排队客户人数   

void menu();
void scline();
void order();
void tuipiao();
void sccli();
void scque();
void back();
void passde();

createFile(struct client cli[]);
createFilewait( struct queuecli wait[ ]);


void menu()
{
    char c;
    printf("\n\n                              航空订票系统菜单          \n");
	printf("\n  ☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
	printf("\n     ◇ 1 查询航线\n");
    printf("\n     ◇ 2 查询订票客户名单\n");
	printf("\n     ◇ 3 查询等候替补客户名单\n");
	printf("\n     ◇ 4 订票\n");
	printf("\n     ◇ 5 退票\n");
	printf("\n     ◇ 6 退出\n");
    printf("\n  ☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
	printf("\n\n请选择功能选项（1-20）:[  ]\b\b\b ");
		
	switch(c=getch())
	{
	case 49: scline();break;
    case 50: sccli();break;
    case 51: scque();break;
	case 52: order();break;
	case 53: tuipiao();break;
	case 54: exit(0);break;
	default:printf("\n\n*****输入错误！*****\n");system("cls");back();
	}	
}

void scline()        //查询航线信息
{   int i;
	int city;
	printf("\n\n                         航空订票系统->航线查询         \n");
	printf("\n  **********************************************************************\n");

shuru:	printf("\n请选择终点站:[  ]\b\b\b\n");
	readtxt1();
    scanf("%d",&city);
	if(city>0&&city<21)
	{   
		printf("\n查询结果：\n");
		printf("\n终点站：\n");
	    switch(city)

		{
          	case 1: printf("北京\n\n");break;
        case 2: printf("上海\n\n");break;
        case 3: printf("南京\n\n");break;
		case 4: printf("长沙\n\n");break;
        case 5: printf("拉萨\n\n");break;
        case 6: printf("广州\n\n");break;
		case 7: printf("深圳\n\n");break;
        case 8: printf("武汉\n\n");break;
        case 9: printf("苏州\n\n");break;
		case 10: printf("成都\n\n");break;
        case 11: printf("重庆\n\n");break;
        case 12: printf("厦门\n\n");break;
		case 13: printf("合肥\n\n");break;
        case 14: printf("南昌\n\n");break;
        case 15: printf("天津\n\n");break;
		case 16: printf("西安\n\n");break;
        case 17: printf("兰州\n\n");break;
        case 18: printf("昆明\n\n");break;
        case 19: printf("大理\n\n");break;
        case 20: printf("香港\n\n");break;
		}
        printf("航班号   飞机号     飞机周日	起飞时间   到达时间   余票量\n");
		for(i=0;i<26;i++)
		{
			if(fliinfo[i].city==city)
				printf("\n  %d	  %s %13s	%s      %s       %d\n",fliinfo[i].flinum,fliinfo[i].planenum,fliinfo[i].week,fliinfo[i].starttime,fliinfo[i].endtime,fliinfo[i].overplus);
		}


	}
	else
	{
        printf("\n*****输入错误！请重新选择！*****\n");
	    goto shuru;
    }
    back();
	
}



void order()                    //订票函数
{   QueuecliType s;                         
	int m,n,level,op,levelmax,p,i;
    printf("\n\n                            航空订票系统->订票          \n");
	printf("\n  **********************************************************************\n");

shuru:	printf("请输入航班号（1-26）:[  ]\b\b\b");
	scanf("%d",&m);
	if(m>0&&m<27)
	{
	printf("\n请输入您要订票的数量:[  ]\b\b\b");
	scanf("%d",&n);
	printf("\n请输入您订票的舱位等级（1-3）:[  ]\b\b\b");
	scanf("%d",&level);
	switch(level)
	{
	case 1:{levelmax=fliinfo[m-1].levelone;op=fliinfo[m-1].opone;}break;
    case 2:{levelmax=fliinfo[m-1].leveltwo;op=fliinfo[m-1].optwo;}break;
    case 3:{levelmax=fliinfo[m-1].levelthree;op=fliinfo[m-1].opthree;}break;
	}
     
	if(n<=op)
	{   cli[num1].flinum=m;            //登记订票客户信息                                 //登记订票客户信息
	    cli[num1].tickets=n;
	    cli[num1].level=level;
		printf("\n请输入您的姓名： ");
		scanf("%s",&cli[num1].name);
		printf("\n请输入您的身份证号码： ");
		scanf("%s",&cli[num1].id);
	    num1=num1+1;
		saveFileCli(cli,1);
		printf("\n\n订票成功！\n\n");
		printf("您的预订票舱位等级：%d\n",level);
		printf("\n您的座位号： ");
		for(i=1;i<=n;i++)
			printf("%d   ",(levelmax-op)+i);
		switch(level)
		{
		case  1: fliinfo[m-1].opone=fliinfo[m-1].opone-n;break;
        case  2: fliinfo[m-1].optwo=fliinfo[m-1].optwo-n;break;
        case  3: fliinfo[m-1].opthree=fliinfo[m-1].opthree-n;break;
		}
		fliinfo[m-1].overplus=fliinfo[m-1].opone+fliinfo[m-1].optwo+fliinfo[m-1].opthree;

	}
	else
	{
		printf("\n*****对不起！余票量少于您的订票额！*****\n\n");
		printf("是否登记排队候补（1 是  2 否 ）:[  ]\b\b\b");
		scanf("%d",&p);

		if(p==1)
		{
			s.flinum=m;                    //登记排队客户信息
            s.demand=n;
			s.level=level;
            printf("\n请输入您的姓名： ");
		    scanf("%s",&s.name);
		    printf("\n请输入您的身份证号码： ");
		    scanf("%s",&s.id);
			ListInsert(&queueList,num2,s);//在顺序表queueList中插入一条记录
			printf("\n请再次确认信息！请输入--\n");
			readwait(wait,1);
			saveFileWait(wait,1);
		    printf("\n\n★★★★★排队登记成功！★★★★★\n\n");
			num2++;          
		}
		
	}
	back();
	
	}
	else
	{
        printf("\n*****输入错误！请重新选择！*****\n");
	    goto shuru;
	}  

}




void tuipiao()                        //退票函数
{   
	char a[20],b[20];
    int c,i,j,p,opl;
	int t;
	int flag=0;              //查看是否有退票人记录的标志
	int flag2=0;             //查看是否有等候替补客户预定已退票的标志
	QueuecliType k;
	printf("\n                            航空订票系统->退票          \n");
	printf("\n  **********************************************************************\n");

	printf("\n请输入您的姓名： ");
	scanf("%s",&a);
	printf("\n\n请输入您的身份证号码： ");
	scanf("%s",&b);
    printf("\n\n请输入您要退票的航班号（1-8）:[  ]\b\b\b");
	scanf("%d",&c);
    printf("\n\n您的订票信息：\n");
	printf("\n航班号	订票量	舱位等级\n");
    for(t=0;t<num1;t++)
	if(c==cli[t].flinum&&strcmp(b,cli[t].id)==0)
	{printf("%d	%d	%d\n",c,cli[t].tickets,cli[t].level);
	 flag=1;
	}
	if(flag==0)
	{
		printf("\n\n没有您的订票记录！\n"); 
	        back();                       
	}
	 else printf("\n\n您确定要退票？（1是 2否）:[  ]\b\b\b");
          scanf("%d",&p);
	if(p==1)
	{

	
   	for(i=0;i<num1;i++)
	{
		if(c==cli[i].flinum&&strcmp(b,cli[i].id)==0)
		{
			switch(cli[i].level)
			{
			case 1: {fliinfo[c-1].opone=fliinfo[c-1].opone+cli[i].tickets;
				     fliinfo[c-1].overplus=fliinfo[c-1].overplus+cli[i].tickets;
					 opl=fliinfo[c-1].opone;
					}break;
			case 2: {fliinfo[c-1].optwo=fliinfo[c-1].optwo+cli[i].tickets;
				     fliinfo[c-1].overplus=fliinfo[c-1].overplus+cli[i].tickets;
					 opl=fliinfo[c-1].optwo;
					}break;
			case 3: {fliinfo[c-1].opthree=fliinfo[c-1].opthree+cli[i].tickets;
				     fliinfo[c-1].overplus=fliinfo[c-1].overplus+cli[i].tickets;
					 opl=fliinfo[c-1].opthree;
					}break;
			}
			cli[i].flinum=-1;    //退票客户航班号置-1，表示已删除  
		}

  loop:			for(j=0;j<num2;j++)
			{
				if(c==queueList.list[j].flinum&&opl>=queueList.list[j].demand&&cli[i].level==queueList.list[j].level)
				{
				    cli[num1].flinum=queueList.list[j].flinum;
                    strcpy(cli[num1].id,queueList.list[j].id);
                    cli[num1].level=queueList.list[j].level;
                    strcpy(cli[num1].name,queueList.list[j].name);
                    cli[num1].tickets=queueList.list[j].demand;
					num1++;
                    ListDelete(&queueList,j,&k);
					 num2--;
					 flag2=1;  //退的票被排队客户预定标志位置1
					 
					 goto loop;

				}
			}


	}
	if(flag2==0)
	{
		printf("\n\n★★★★★退票成功！★★★★★\n\n");
		printf("\n★★★★★没有等候替补客户预定！★★★★★\n\n");
		back();
	}
	else 
	{
		printf("\n\n★★★★★退票成功！★★★★★\n\n");
		printf("\n★★★★★您的退票已被等候替补客户预定！★★★★★\n\n");
        back();

	}

	}
	else  back();
    


}



void sccli()                                                   //查询订票客户名单
{      int p,i,j;
       int flag=0;
	   printf("\n\n\n                     航空订票系统->查询订票客户名单          \n");
	   printf("\n  **********************************************************************\n");
	   printf("\n查询本次操作订票客户请输入1，查询以前的订票客户名单请输入2\n");
		  scanf("%d",&j);

		if(j==1)
		{
            printf("\n请输入要查询的航班号（1-26）:[  ]\b\b\b");
        scanf("%d",&p);
		if(p>0&&p<27)
		{
	    printf("\n\n航班号：%d\n\n",p);
	    printf("订票客户名单：\n");
		printf("\n姓名		订票量		舱位等级\n");
		for(i=0;i<num1;i++)
			if(p==cli[i].flinum)
			{
				printf("%s		%d		%d\n",cli[i].name,cli[i].tickets,cli[i].level);
				flag=1;
			}
			if(flag==0)
				printf("\n*****无记录！*****\n");
		}
		else printf("\n\n*****输入航班号错误！*****\n\n");
		back();
		}
		else readtxt2();		
		back();
	
}



	

void scque()                                    //查询排队客户名单
{
		int p,i,j;
		int flag=0;
		printf("\n\n\n                      航空订票系统->查询排队客户名单          \n");
  	    printf("\n  **********************************************************************\n");
		printf("\n查询本次操作排队客户请输入1,查询以前的排队客户名单请输入2\n");
		  scanf("%d",&j);
		printf("\n\n请输入要查询的航班号（1-26）:[  ]\b\b\b");
        scanf("%d",&p);
		if(j==1)
		{
		if(p>0&&p<27)
		{
	    printf("\n\n航班号：%d\n\n",p);
	    printf("等候替补客户名单：\n");
		printf("\n姓名		需求量		舱位等级\n");
		for(i=0;i<num2;i++)
		
			if(p==queueList.list[i].flinum)
			{
				printf("%s		%d		%d\n",queueList.list[i].name,queueList.list[i].demand,queueList.list[i].level);
				flag=1;
			}
			if(flag==0)
				printf("\n*****无记录！*****\n");
		} 
		else printf("\n\n*****输入航班号错误！*****\n\n");
		back();
		}
		else readtxt3();
		back();

} 



void back()
{
	printf("\n\n《《《《《《任意键返回菜单页！》》》》》》\n");
    getch();
	system("cls");
	menu();
}
void passde()
{
	int ture;
	printf("请输入密码！\n");
	scanf("%d",&PASS);
	ture=123456;
	if(PASS==ture)
	{
		printf("登入成功！\n");
	}
	else
	{
		printf("密码错误！\n");
		exit(0);
	}
}


void main()
{
	system("Color f0");
	printf("\n                            欢迎进入航空订票系统！ \n");
	passde();
    menu();
}
