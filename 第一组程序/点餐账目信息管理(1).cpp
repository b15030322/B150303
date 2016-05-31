#include <stdio.h>
#include <string.h>
#include <process.h>
#include <cstdlib>
#define jiaozigeshu 4//饺子有多少种
void dayincaidan(void);//打印菜单
void dayinzhangdan(int n,int x);//打印账单
void diancan(int i);//点餐函数
void cost(int n,int x);//计算消费额
void jiezhang(void);//结账
void genggai(void);//更改订单
void shanchudingdan(int n,int x);//删除订单
void tongji(int h);//统计
void chaxun(int h);//查询
void paixu(int h);//排序
void tiancai(int n,int x);//添菜
void huancai(int n,int x);//换菜
void shancai(int n,int x);//删菜
void zengjian(int n,int x);//增减菜
struct joz//该结构体用于储存原始信息以下程序只引用不更改
{
	char zhonglei;
	char mingzi[10];
	int jiage;
	int num;//剩余数量即库存数量
}jz[jiaozigeshu];
struct jiaozi//该结构体用于储存饺子信息即菜单可以更改
{
	char zhonglei;
	char mingzi[10];
	int jiage;
	int num;//剩余数量即库存数量
}jiao[jiaozigeshu];
struct DC//该结构体用于储存每一桌的点餐信息
{
	int bianhao;//订单编号，便于后面统计
	struct date//结构体定义时间
	{	
		int hour;
		int minute;
	}shijian;
	int zhuohao;
	int gukeshuliang;
    struct dd//结构体定义订单信息
	{
		char zhonglei;
		int shuliang;
	}dc[jiaozigeshu];
	int caileishu;//共点了几道菜
	int cost;
	char zhuangtai[20];
}dcxx[50];
int main()
{
	int n,h=1,m=0;//h为系统给的编号，点一次餐则加一次
	FILE*fp;FILE*fd;//打印菜单
	FILE *fp1,*fp2;
	jiaozi stu[2] = {{'a','b',1,1,},{'b','a',2,2}};
	if((fp=fopen("G:\\作业\\xinxi.txt","a+"))==NULL)//为方便更改，饺子的种类信息等由另一程序编写入文件，此处直接调用
	{
		printf("系统出错，无法导入菜单\n");
		exit(0);
	}
   for(int i=0;i<jiaozigeshu;i++)//使用if显示卖完
	{
	fscanf(fp,"%s%s%d%d", &jiao[i].zhonglei, &jiao[i].mingzi,&jiao[i].jiage,&jiao[i].num);  // 循环读取
	} 
	fclose(fp);  //关闭文件
    while(1)
	{
        system("color F1");
		printf("-------------------------\n");  /*做成一个选择的功能，可以点餐，结账，查询，订单更改,统计，排序*/
		printf("   欢迎进入选择系统      \n");
		printf("     1.点餐              \n");
		printf("     2.结账(显示账单)    \n");  //先点餐后结账，所以我把点餐和结账分开
		printf("     3.订单更改(包括删除)\n");
		printf("     4.统计              \n");
		printf("     5.查询              \n");
		printf("     6.排序              \n");
		printf("     7.关机              \n");
		printf(" 请输入对应序号选择功能  \n");
		printf("-------------------------\n");
		do//这里加do while 防止输入错误
		{
			scanf("%d",&n);	fflush(stdin);
			switch(n)
			{
				case 1: diancan(h++);break;
				case 2: jiezhang();break;
				case 3: genggai();break;
				case 4: tongji(h-1);break;
				case 5: chaxun(h-1);break;
				case 6: paixu(h-1);break;
				case 7: printf("系统关机\n");break;
				default:printf("输入不正确·请重新输入\n");
			}
		}while(n!=1&&n!=2&&n!=3&&n!=4&&n!=5&&n!=6&&n!=7);
		if(n==7) 
			break;    //跳出循环，系统结束
	}
	if((fd=fopen("G:\\作业\\xiaoshou.txt","w+"))==NULL)//建立一文件储存的今天的全部销售信息
	{
		printf("文件建立error\n");
		exit(0); 
	}
	fclose(fd);
}
void dayincaidan(void)
{
	int i;
	printf("┌───────────---------──┐\n");
    printf("│    欢迎        菜单       光临    │\n");
	printf("│饺子种类 饺子名称 饺子价格 剩余数量│\n");     
	printf("└──────────————-───┘\n");
	printf("**********************************************\n");
	for(i=0;i<jiaozigeshu;i++)//使用if显示卖完
	{
		printf("    %c      %-10s     %d\t",jiao[i].zhonglei,jiao[i].mingzi,jiao[i].jiage);
		if(jiao[i].num>0)
			printf("%d\n",jiao[i].num);
		else
			printf("   已售完\n");
	}//菜单打完，若卖完有显示
}
void dayinzhangdan(int n,int x)
{
	int i;
	printf("订单号%d   ",n);printf("桌号：%d   ",dcxx[n].zhuohao);printf("点餐时间：%2d:%2d\n",dcxx[n].shijian.hour,dcxx[n].shijian.minute);
	printf("┌───────────---------──┐\n");
    printf("│    谢谢        账单       惠顾    │\n");
	printf("│饺子名称                   所点数量│\n");     
	printf("└──────────————-───┘\n");
	for(i=0;i<x;i++)
			printf("%4c%30d\n",dcxx[n].dc[i].zhonglei,dcxx[n].dc[i].shuliang);
		printf("*******************************************\n");
	cost(n,x);
	printf("总计 %d yuan\n",dcxx[n].cost);
}
void diancan(int i)
{
		int j=0,t=0,r=0,m=0;
		dayincaidan();
		printf("编号：%d\n",dcxx[i].bianhao=i);/*bianhao(编号)和数组对应*/
		printf("请·输入时间(例: 12 15 (不加\" ：\")): ");scanf("%d %d",&dcxx[i].shijian.hour,&dcxx[i].shijian.minute);fflush(stdin);
		printf("请·输入桌号: ");scanf("%d",&dcxx[i].zhuohao);printf("\n");fflush(stdin);
		printf("请·输入顾客数量: ");scanf("%d",&dcxx[i].gukeshuliang);printf("\n");fflush(stdin);
		printf("\n输入#字键结束点餐,按任意键开始点餐\n");getchar();fflush(stdin);
		do
		{
			printf("\n输入水饺种类(输入字母例:a,b)：");scanf("%c",&dcxx[i].dc[j].zhonglei);fflush(stdin);
			printf("输入水饺盘数：");scanf("%d",&dcxx[i].dc[j].shuliang);printf("\n");fflush(stdin);
			for(m=0;m<jiaozigeshu;m++)
				if(jiao[m].zhonglei==dcxx[i].dc[j].zhonglei)
					jiao[m].num=jiao[m].num-dcxx[i].dc[j].shuliang;
			j++;
		}while(getchar()!='#');
		dcxx[i].caileishu=j;
        cost(i,j);	
		printf("应付金额：%d\n",dcxx[i].cost);
		strcpy(dcxx[i].zhuangtai,"未支付");
		fflush(stdin);

}
void jiezhang(void)
{
	int n,ch;
	printf("请·输入编号\n");scanf("%d",&n);fflush(stdin);
    dayinzhangdan(n,dcxx[n].caileishu);
	printf("是否现在付款：y or n\n");
	ch=getchar(); fflush(stdin);
	if(ch=='y')
	{
		printf("付款成功\n");
		strcpy(dcxx[n].zhuangtai,"已支付");
	}
	else
		return ;
}
void genggai(void)
{
	int n,x;
	printf("请·输入需要更改的编号\n"); scanf("%d",&n); fflush(stdin);
	printf("请·输入更改项\n");
	printf("1.添菜  2.换菜  3.删菜  4.增减数量 5.删除订单\n"); 
	scanf("%d",&x);fflush(stdin);
	switch(x)
	{
	case 1: tiancai(n,dcxx[n].caileishu);break;
	case 2: huancai(n,dcxx[n].caileishu);break;
	case 3: shancai(n,dcxx[n].caileishu);break;
	case 4: zengjian(n,dcxx[n].caileishu);break;
	case 5: shanchudingdan(n,dcxx[n].caileishu);break;
	default: printf("输入错误返回到主屏幕\n");
	}
}
void tongji(int h)
{
	int sum=0,guke=0,i;
	for(i=1;i<=h;i++)
	{
		sum+=dcxx[i].cost;
		guke+=dcxx[i].gukeshuliang;
	}
	printf("总销售额为%d\n总顾客数量为%d\n",sum,guke);
}
void chaxun(int h) 
{
	char ch,dh;
	int i,count=1;
	printf("1.查询饺子库存输入d  2.查询未支付订单输入s\n");
	dh=getchar();fflush(stdin);
	switch(dh)
	{
	case 'd':
		{
			printf("┌─────────┐\n");
			printf("│饺子种类 饺子名称 │\n");     
			printf("└────────--┘\n");
			printf("*********************\n");
			for(i=0;i<jiaozigeshu;i++)//使用if显示卖完
				printf("     %c    %s \n",jiao[i].zhonglei,jiao[i].mingzi);//饺子代号
			printf("请·输入饺子种类：");
			ch=getchar();fflush(stdin); 
			for(i=0;i<jiaozigeshu;i++)
			{
				if(ch==jiao[i].zhonglei)
					printf("剩余数量为%d\n",jiao[i].num);
			}
			printf("查询完成\n");
		}
			break;
	case 's':
		{
			for(i=1;i<=h;i++)
			if(strcmp(dcxx[i].zhuangtai,"未支付")==0)
			{
				printf("未支付的订单号：%d\n",dcxx[i].bianhao);
				printf("应付金额：%d\n",dcxx[i].cost);
				count++;
			}
			if(count==h)
				printf("无未支付订单\n");
		}
			break;
	default:printf("输入错误，返回主界面\n");return ;
	}
}
void paixu(int h)
{

	int i,j,k,h1,hh,m1,mm,q,f1,f2,t;
    int a[jiaozigeshu]={0};int b[4]={0,1,2,3};
	printf("输入对应功能序号:1.按销售金额排序  2.按时间段排序\n");
    fflush(stdin);scanf("%d",&q);fflush(stdin);
	switch(q)
	{
	case 1:
			printf("总销量从低到高排序（按金额）：\n");
			for(i=0;i<jiaozigeshu;i++)
				a[i]=(jz[i].num-jiao[i].num)*jiao[i].jiage;/*饺子卖出的金额*/
			for(i=0;i<jiaozigeshu;i++)
			{
				k=i;
				for(j=i;j<=jiaozigeshu-1;j++)
				{
					if(a[j]>=a[k])
						k=j;
					if(a[k]!=a[j])
					{
						t=a[j];
						a[j]=a[k];
						a[k]=t;
						t=b[j];
						b[j]=b[k];
						b[k]=t;
					}	
				}
			}
			for(i=0;i<jiaozigeshu;i++)
				printf("%c %s %2d元\n",jiao[b[i]].zhonglei,jiao[b[i]].mingzi,a[i]);
			break;
	case 2:
			printf("请·输入查询的时间段\n");
			printf("请输入起始时间(例:12时15分即输入12 15(不加\" ：\"))：");scanf("%d %d",&h1,&m1);printf("\n");fflush(stdin);
			printf("请输入终止时间(例:12时15分即输入12 15(不加\" ：\"))：");scanf("%d %d",&hh,&mm);printf("\n");fflush(stdin);	
			for(i=1;i<=h;i++)
				if((dcxx[i].shijian.hour*60+dcxx[i].shijian.minute)>=(h1*60+m1))
				{
					printf("起始编号为%d",f1=i);
					break;
				}
			for(j=i-1;i<=h;i++)
				if((dcxx[i].shijian.hour*60+dcxx[i].shijian.minute)>=(hh*60+mm))
				{
					printf(" 终止编号为%d\n",f2=i);
					break;
				}
			for(i=f1;i<=f2;i++)
				for(j=0;j<dcxx[i].caileishu;j++)
					switch(dcxx[i].dc[j].zhonglei)
					{
						case 'a': a[0]+=dcxx[i].dc[j].shuliang;break;
						case 'b': a[1]+=dcxx[i].dc[j].shuliang;break;
						case 'c': a[2]+=dcxx[i].dc[j].shuliang;break;
						case 'd': a[3]+=dcxx[i].dc[j].shuliang;break;
					};	
			printf("排序从低到高为：\n");
			for(i=0;i<jiaozigeshu;i++)
			{
				k=i;
				for(j=i;j<=jiaozigeshu-1;j++)
				{
					if(a[j]>=a[k])
						k=j;
					if(a[k]!=a[j])
					{
						t=a[j];
						a[j]=a[k];
						a[k]=t;
						t=b[j];
						b[j]=b[k];
						b[k]=t;
					}	
				}
			}
			for(i=0;i<jiaozigeshu;i++)
				printf("%c %s %2d个\n",jiao[b[i]].zhonglei,jiao[b[i]].mingzi,a[i]);
			break;
	default:printf("输入错误，回到主界面\n");return ;
	}
}

void shancai(int n,int x)
{
	int i=0,ch,h;
	dayinzhangdan(n,x);
	dayincaidan();
	printf("删哪种菜(输入菜的代号):");ch=getchar();fflush(stdin);	
	for(i=0;i<x;i++)
	{
		if(ch==dcxx[n].dc[i].zhonglei)
		{	
			for(h=0;h<=jiaozigeshu;h++)//恢复库存
				if(ch==jiao[h].zhonglei)	
					jiao[h].num+=dcxx[n].dc[i].shuliang;
			dcxx[n].dc[i].shuliang=0;

		}
	}
	printf("成功，返回\n");
	
}
void zengjian(int n,int x)
{
	char ch;int b;int h;int i;
	dayinzhangdan(n,x);
	dayincaidan();
	printf("增减哪种菜(输入菜的种类):");ch=getchar();fflush(stdin);
	printf("增输正数 减输负数\n"); scanf("%d",&b);fflush(stdin);
	for(i=0;i<x;i++)
	{
		if(ch==dcxx[n].dc[i].zhonglei)
		{	
			for(h=0;h<=jiaozigeshu;h++)//恢复库存
				if(ch==jiao[h].zhonglei)	
					jiao[h].num-=b;
			dcxx[n].dc[i].shuliang+=b;
		}
	}
	printf("成功，返回\n");
}
void tiancai(int n,int x)
{
	char ch;int b,h;
	dayinzhangdan(n,x);
	dayincaidan();
	printf("添哪种菜(输入菜的种类):");ch=getchar();fflush(stdin);
	printf("所点数量：");scanf("%d",&b);fflush(stdin);
	dcxx[n].dc[x].zhonglei=ch;dcxx[n].dc[x].shuliang=b;dcxx[n].caileishu+=1;
	for(h=0;h<=jiaozigeshu;h++)//改变库存
				if(ch==jiao[h].zhonglei)	
					jiao[h].num-=b;
	printf("成功，返回\n");
}
void huancai(int n,int x)
{
	dayinzhangdan(n,x);
	dayincaidan();
	printf("\n");
	printf("实现换菜功能（先删掉原来的菜再添加新菜）\n按任意键继续\n");
	getchar();
	shancai(n,x);
	tiancai(n,x);
	printf("成功，返回\n");
}
void cost(int n,int x)
{
	int i,j,sum=0;
	for(i=0;i<x;i++)
		for(j=0;j<jiaozigeshu;j++)
			if(dcxx[n].dc[i].zhonglei==jiao[j].zhonglei)
				sum+=((jiao[j].jiage)*(dcxx[n].dc[i].shuliang));
	dcxx[n].cost=sum;
}
void shanchudingdan(int n,int x)
{
	int i,j;
	char ch;
	dayinzhangdan(n,x);
	dayincaidan();
	printf("\n");
	printf("确认删除？\n输入y删除，输入任意键回到主界面: ");
	if((ch=getchar())=='y')
	{	
		fflush(stdin);
		strcpy(dcxx[n].zhuangtai,"订单删除");
		dcxx[n].cost=0;
		dcxx[n].gukeshuliang=0;
		for(i=0;i<x;i++)//删除后恢复库存
			for(j=0;j<jiaozigeshu;j++)
				if(dcxx[n].dc[i].zhonglei==jiao[j].zhonglei)
					jiao[j].num+=dcxx[n].dc[i].shuliang;
		for(i=0;i<x;i++)
			dcxx[n].dc[i].shuliang=0;
		printf("订单已删除\n");
	}
}



	


    





				


	
			

		




		 




	











