/*②criminal.c文件的完整内容*/
#include "criminal.h"
#include <stdio.h>

int readCri(Criminal  *cri , int n)          /*读入服刑人员记录值，狱号为0或读满规定条数记录时停止*/
{
	int i;
	for (i=0;i<n;i++)
	{
		printf("Input one criminal\'s information\n");
		printf("num:  ");
	     scanf("%ld", &cri[i].num);
		if (cri[i].num==0) break;
		printf("name: ");
		scanf("%s",cri[i].name);	
		printf("sex:  ");
		scanf("%s",cri[i].sex);
    	     cri[i].total=0;                /*总出勤次数需要计算求得，初值置为0*/
		printf("Input year of the criminal:");
		    scanf("%d",&cri[i].year);
					printf("Input month of the criminal:");
	scanf("%d",&cri[i].month);
						printf("Input day of the criminal:");
	scanf("%d",&cri[i].day);
	/*cri[i].rank=0;                 此处为总出勤次数计算初值置为0*/
	}
	return i;                         /*返回实际读入的记录条数*/
}

void printCri (Criminal  *cri, int n)       /*输出所有服刑人员记录的值*/
{
    int i;
	for (i=0;i<n;i++)
	{
		printf("%2ld  ", cri[i].num);
		printf("%15s", cri[i].name);
		printf("%15s", cri[i].sex);
		printf("%18d/%2d/%2d",cri[i].year,cri[i].month,cri[i].day);
	    printf("%20d\n",cri[i].total);
	    /*printf("%5d\n",cri[i].rank);*/
	}
}

int equal(Criminal s1,Criminal s2,int condition)  /*如何判断两个Criminal记录相等*/
{
	if (condition==1)                    /*如果参数condition的值为1，则比较学号*/
		return s1.num==s2.num;
	else if (condition==2)                /*如果参数condition的值为2，则比较姓名*/
     {
	     if (strcmp(s1.name,s2.name)==0) 	return 1;
		else return 0;
     }
 /*else if (condition==3)                如果参数condition的值为3，则比较总出勤次数
	     return s1.rank==s2.rank;*/
 else if (condition==4)                /*如果参数condition的值为4，则比较总分*/
		return s1.total==s2.total;
	else return 1;                       /*其余情况返回1*/
} 

int larger(Criminal s1,Criminal s2,int condition)  /*根据condition条件比较两个Criminal记录的大小*/
{
	if (condition==1)                    /*如果参数condition的值为1，则比较狱号*/
		return s1.num>s2.num;
	if (condition==2)                    /*如果参数condition的值为2，则比较总分*/
		return s1.total>s2.total;	
	else return 1; /*其余情况返回1*/
}

void reverse(Criminal cri[],int n)             /*数组元素逆置*/
{
	int i;
	Criminal temp;
	for (i=0;i<n/2;i++)                   /*循环次数为元素数量的一半*/
	{
		temp=cri[i];
		cri[i]=cri[n-1-i];
		cri[n-1-i]=temp;
	}
}

/*void calcuTotal(Criminal cri[],int n)         计算所有服刑人员的总出勤次数
{
	int i,j;
	for (i=0;i<n;i++)                    外层循环控制所有学生记录
	{
		cri[i].total =0;
		for (j=0;j<3;j++)               内层循环控制每次出勤内容
			cri[i].total +=stu[i].score[j];
	}	
}*/

/*void calcuMark(double m[3][3],Criminal cri[],int n) 求三门课的最高、最低、平均分
其中形式参数二维数组m的第一维代表三门课，第二维代表最高、最低、平均分
{
	int i,j;
	for (i=0;i<3;i++)                 求三门课的最高分		
	{ 
		m[i][0]=stu[0].score[i];     
		for (j=1;j<n;j++)
			if (m[i][0]<stu[j].score[i])
				m[i][0]=stu[j].score[i];
	}
	for (i=0;i<3;i++)                  /*求三门课的最低分
	{ 
		m[i][1]=stu[0].score[i];      
		for (j=1;j<n;j++)
			if (m[i][1]>stu[j].score[i])
				m[i][1]=stu[j].score[i];
	}
	for (i=0;i<3;i++)                 /*求三门课的平均分
	{ 
		m[i][2]=stu[0].score[i];     
		for (j=1;j<n;j++)
			m[i][2]+=stu[j].score[i];
		m[i][2]/=n;
	}
}*/

void sortCri(Criminal cri[],int n,int condition)  /*选择法排序，按condition条件由小到大排序*/
{
	int i,j,minpos;                      /*minpos用来存储本趟最小元素所在的下标*/
	Criminal t;
	for (i=0;i<n-1;i++)                  /*控制循环的n-1趟*/
	{
		minpos=i;
		for (j=i+1;j<n;j++)             /*寻找本趟最小元素所在的下标*/
			if (larger(cri[minpos],cri[j],condition))
				minpos=j;
		if (i!=minpos)                 /*保证本趟最小元素到达下标为i的位置*/
		{
			t=cri[i];
			cri[i]=cri[minpos];
			cri[minpos]=t;
		}
	}
}

int searchCri(Criminal cri[],int n,Criminal s,int condition,int f[ ])  /*在cri数组中依condition条件查找*/
/*与s相同的元素，由于不止一条记录符合条件，因此将这些元素的下标置于 f数组中*/
{
	int i,j=0,find=0;
	for (i=0;i<n;i++)                                 /*待查找的元素*/
		if (equal(cri[i],s,condition))  
		{
			f[j++]=i;                          /*找到了相等的元素，将其下标放到f数组中*/
			find++;	                        /*统计找到的元素个数*/                              
		}
	 return find;                                /*返回find，其值为0则表示没找到*/ 
}

int insertCri(Criminal cri[],int n,Criminal s)              /*向cri数组中依学号递增插入一个元素s*/
{
	int i;
	sortCri(cri,n,1);                              /*先按狱号排序*/
	for (i=0;i<n;i++)
	{
		if (equal(cri[i],s,1))                      /*狱号相同不允许插入，保证狱号的唯一性*/
		{
		    printf("this record exist,can not insert again!\n");
		    return n;
		}
	}
	for (i=n-1;i>=0;i--)                          /*按狱号从小到大有序*/
	{
		if (!larger(cri[i],s,1))                    /*如果s大于当前元素cri[i]，则退出循环*/
		break;
	cri[i+1]=cri[i];                         /*否则元素cri[i]后移一个位置*/
	}
	cri[i+1]=s;                                /*在下标i+1处插入元素s*/                                   
	n++;                                     /*元素个数增加1*/
	return n;                                  /*返回现有元素个数*/
}

int deleteCri(Criminal cri[],int n,Criminal s)            /*从数组中删除指定狱号的一个元素*/
{
	int i,j;
	for (i=0;i<n;i++)                           /*寻找待删除的元素*/
		if (equal(cri[i],s,1))   break;            /*如果找到相等元素则退出循环*/
	if (i==n)                                 /*如果找不到待删除的元素*/
	{
		printf("This record does not exist!\n");    /*给出提示信息然后返回*/
		return n;
	}
	for (j=i; j<n-1; j++)                        /*此处隐含条件为i<n且equal(cri[i],s,1)成立*/ 
		cri[j]=cri[j+1];                       /*通过移动覆盖删除下标为i的元素*/
                                                                            
	n--;                                      /*元素个数减少加1*/
	return n;                                  /*返回现有个数*/
}

