//#include<stdio.h>
//#include<stdlib.h>
struct fliinfo						//航班信息
{
	int city;
	int flinum;        
    char planenum[10];			//飞机型号
    char week[10];              	//星期几飞行
    int  maxnum;					//成员定额
    int  overplus;					//余票量
    int  levelone;					//一等舱座位数量
    int  opone;					//一等舱余票量
    int  leveltwo;					//二等舱座位数量
    int  optwo;					//二等舱余票量
    int  levelthree;				//三等舱座位数量
    int  opthree;					//三等舱余票量
    char  starttime[7];         	//起飞时间
    char  endtime[7];				//到达时间

}fliinfo[8]={{1,1,"737","MONDAY",120,120,10,10,20,20,90,90,"09:50","12:15"},{1,2,"K320","WEDNESDAY",120,120,10,10,20,20,90,90,"15:00","17:30"},{1,3,"737","FRIDAY",120,120,10,10,20,20,90,90,"13:25","15:55"},{2,4,"757","TUESDAY",120,120,10,10,20,20,90,90,"10:15","11:45"},{2,5,"737","SATURDAY",120,120,10,10,20,20,90,90,"14:45","16:00"},{2,6,"K320","THURSDAY",120,120,10,10,20,20,90,90,"20:10","21:30"},{3,7,"737","WEDNESDAY",120,120,10,10,20,20,90,90,"11:30","12:30"},{3,8,"737","SUNDAY",120,120,10,10,20,20,90,90,"17:25","18:30"}};

struct wait
{
	char name[10];
	int demand[20];
	int level[5];
	int flinum; 
};
typedef struct
{
	struct wait list[MaxSize];
	int size;
}SeqList;
void ListInitiate(SeqList *L)
{
	L->size=0;
}

int ListLength(SeqList L)
{
	return L.size;
}
int ListInsert(SeqList *L,int i,struct wait x)
{
	int j;
	if(L->size>=MaxSize)
	{
		printf("顺序表已满无法插入！\n");
		return 0;
	}
	else if(i<0||i>L->size)
	{
		printf("参数i不合法！\n");
	    return 0;
	}
	else
	{
		for(j=L->size;j>i;j--)L->list[j]=L->list[j-1];
        L->list[i]=x;
        L->size++;
		return 1;
	}
}
int ListDelete(SeqList *L,int i,struct wait *x)
{
	int j;
	if(L->size<=0)
	{
		printf("顺序表已无数据可删！\n");
		return 0;
	}
	else if(i<0||i>L->size-1)
	{
		printf("参数i不合法！\n");
		return 0;
	}
	else 
	{
		*x=L->list[i];
		for(j=i+1;j<=L->size-1;j++)L->list[j-1]=L->list[j];
        L->size--;
		return 1;
	}
}
