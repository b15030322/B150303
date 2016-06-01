

#include<stdio.h>
#include<stdlib.h>
#include"file.h"
#include"book.h"
void printHead()       /*打印图书信息表头*/
{ 
	printf("%10s%10s%10s%10s%10s%10s%10s%10s%15s%10s\n","编号","书名","作者","价格","一","二","三","四","总借阅量","排名");
}
void triangle()    /*花样*/
{
	int i,j;
	for(i=1;i<=5;i++)
	{
		for(j=1;j<=35-i;j++)
		{
			printf(" ");
		}
		for(j=1;j<=2*i-1;j++)
		{
			printf("*");
		}
		printf("\n");
	}
}
void menu()         /*顶层菜单函数*/
{
		printf("    -------------------------------------------------------------     \n");    
		printf("                          图 书 管 理 系 统 \n");
		printf("                        1. 显 示 图 书 信 息 \n");
		printf("                        2. 基 本 信 息 管 理 \n");
		printf("                        3. 借 阅 量 管 理 \n");
		printf("                        4. 借 阅 量 统 计 \n");
		printf("                        5. 根 据 条 件 查 询 \n");
		printf("                        0. 退 出         \n");
		printf("    -------------------------------------------------------------     \n");
}
void menuBase()   /*图书信息管理菜单函数*/
{
		printf("                        1. 插 入 图 书 记 录 \n");
		printf("                        2. 删 除 图 书 记 录 \n");
		printf("                        3. 修 改 图 书 记 录 \n");
		printf("                        0. 返 回 上 层 菜 单 \n");
}
void menuScore()   /*借阅量管理菜单函数*/
{
		printf("                        1. 计 算 图 书 总 借 阅 量 \n");
		printf("                        2. 按 总 借 阅 量 排 名 \n");
		printf("                        0. 返 回 上 层 菜 单 \n");
}
void menuCount()   /*借阅量统计菜单函数*/
{
		printf("                        1. 季 度 最 高 借 阅 量 \n");
		printf("                        2. 季 度 最 低 借 阅 量 \n");
		printf("                        3. 季 度 平 均 借 阅 量 \n");
		printf("                        0. 返 回 上 层 菜 单 \n");
}
void menuSearch()    /*根据条件查询菜单函数*/
{
		printf("                        1. 按 编 号 查 询 \n");
		printf("                        2. 按 书 名 查 询 \n");
		printf("                        0. 返 回 上 层 菜 单 \n");
}
int baseManage(Book boo[],int n)    	     /*该函数完成图书信息管理*/
/*按编号进行插入删除修改，编号不能重复*/
{  
	int choice,t,find[NUM];
	Book b;
	do
	{   
		menuBase( );                  /*显示对应的二级菜单*/
		printf("choose one operation you want to do:\n");
		scanf("%d",&choice);
		if(choice<=3&&choice>=0) /*读入选项*/
		switch(choice)
		{
			 case 1:	 readBoo(&b,1);       /*读入一条待插入的图书信息*/
					 n=insertBoo(boo,n,b);   /*调用函数插入图书信息*/
					 break;
			 case 2:  printf("Input the number deleted\n");
					 scanf("%ld",&b.num);  /*读入一个待删除的图书编号*/
					 n=deleteBoo(boo,n,b);   /*调用函数删除指定编号的图书信息*/
					 break;
			 case 3:  printf("Input the number modified\n");
					 scanf("%ld",&b.num);  /*读入一个待修改的图书编号*/
				      t=searchBoo(boo,n,b,1,find) ; /*调用函数查找指定编号的图书记录*/
					  if (t)                 /*如果该编号的记录存在*/
			  		 {
						  readBoo(&b,1);   /*读入一条完整的图书信息*/
					      boo[find[0]]=b;    /*将刚读入的记录赋值给需要修改的数组记录*/ 					 
					  }					 
					 else                 /*如果该编号的记录不存在*/ 
		             printf("this book is not in,can not be modified.\n"); /*输出提示信息*/
					 break;
			         case 0: 
						 break;
		   }
		 else 
			 printf("\t\t\t\t\t错误，请检查后再一次输入！\n");
	}while(choice);
	 return n;
 }
void scoreManage(Book boo[],int n)          /*该函数完成借阅量管理功能*/
{  
	int choice;
	do
	{
		menuScore( );                        /*显示对应的二级菜单*/
		printf("choose one operation you want to do:\n");
		scanf("%d",&choice);
		if(choice<=2&&choice>=0)/*读入二级选项*/
		switch(choice)
		{
			case 1:   calcuTotal(boo,n);    
					  break;
			case 2:   calcuRank(boo,n);        
				      break;		
			case 0:   break;
		}
		else 
			 printf("\t\t\t\t\t错误，请检查后再一次输入！\n");
	}while(choice);
}
void printMarkCourse(char *b,double m[4][4],int k)   /*打印分数通用函数，被countManage 调用*/
{                 /*形式参数k代表输出不同的内容，0、1、2分别对应最高、最低、平分*/
int i;
    printf(b);                                  /*这里的s传入的是输出借阅量的提示信息*/
    for (i=0;i<4;i++)                           /*i控制哪一本书*/
		  printf("%10.2lf",m[i][k]);
	   printf("\n");
}
void countManage(Book boo[],int n)               /*该函数完成借阅量统计功能*/
{
		int choice;
		double mark[4][4];
		do
		{
			menuCount();                        /*显示对应的二级菜单*/
			calcuMark(mark,boo,n);
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printMarkCourse("四季度借阅量的最高分别是:\n",mark,0);  /*输出最高*/
				      break;
				case 2:   printMarkCourse("四季度借阅量的最低分别是:\n",mark,1);  /*输出最低*/
				      break;
				case 3:   printMarkCourse("四季度借阅量的平均分别是:\n",mark,2);  /*输出平均*/
				      break;
				case 0:   break;
			}
		}while (choice);
}
void searchManage(Book boo[],int n)               /*该函数完成根据条件查询功能*/
{
    int i,choice,findnum,f[NUM];
Book b;
	   do
{
			menuSearch( );                         /*显示对应的二级菜单*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printf("Input a book\'s num will be searched:\n");
				      scanf("%ld",&b.num);         /*输入待查询图书的编号*/
					  break;
				case 2:   printf("Input a book\'s title will be searched:\n");
				      scanf("%s",&b.title);	          /*输入待查询图书的书名*/		  
				      break;   
				case 0:   break;
			}
		 	if (choice>=1&&choice<=2)		
			{ 
				findnum=searchBoo(boo,n,b,choice,f);    /*查找的符合条件元素的下标存于f数组中*/
				if (findnum)				     /*如果查找成功*/
				{
			   		 printHead();                  /*打印表头*/
					 for (i=0;i<findnum;i++)         /*循环控制f数组的下标*/
	      	 printBoo(&boo[f[i]],1);      /*每次输出一条记录*/
				}
		    		else
			    	    printf("this record does not exist!\n"); /*如果查找不到元素，则输出提示信息*/
		     }		
	    }while (choice);
}

int runMain(Book boo[],int n,int choice)    /*主控模块，对应于一级菜单其下各功能选择执行*/
{
		switch(choice)
		{
			case 1: printHead( );           /* 1. 显示基本信息*/
				 sortBoo(boo,n,1);         /*按编号由小到大的顺序排序记录*/ 
          	 printBoo(boo,n);          /*按编号由小到大的顺序输出所有记录*/
					break;
			case 2: n=baseManage(boo,n);    /* 2. 基本信息管理*/
			   	     break;
			case 3: scoreManage(boo,n);     /* 3. 借阅量管理*/
					break;
			case 4: countManage(boo,n);     /* 4. 借阅量统计*/
					break;
			case 5: searchManage(boo,n);     /* 5. 根据条件查询*/
				     break;
          case 0: break;
		}
		return n;
}

int main( )
{
		Book boo[NUM];                /*定义实参一维数组存储图书记录*/
      int choice,n;
	 n=readFile(boo);                  /*首先读取文件，记录条数返回赋值给n*/
	 if (!n)                          /*如果原来的文件为空*/
	     {
		    n=createFile(boo);              /*则首先要建立文件，从键盘上读入一系列记录存于文件*/
}	 	 
	do
	     {
	         menu();                      /*显示主菜单*/
	         printf("Please input your choice: ");
	         scanf("%d",&choice);
	         if (choice>=0&&choice<=5)
	              n=runMain(boo,n,choice);    /*通过调用此函数进行一级功能项的选择执行*/
	         else 
		          printf("error input,please input your choice again!\n");
	} while (choice);
	sortBoo(boo,n,1);                   /*存入文件前按学号由小到大排序*/ 
	     saveFile(boo,n);                   /*将结果存入文件*/
      return 0;
}
