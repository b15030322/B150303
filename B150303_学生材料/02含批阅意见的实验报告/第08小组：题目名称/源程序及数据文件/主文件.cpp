#include<stdio.h>
#include<stdlib.h>
#include"file.h"
#include"criminal.h"
/*此处还应包含两个打开文件的字段#include"file.h"和#include"content.h"*/

void printHead1( )      /*打印服刑人员信息的表头*/
{
printf("%2s%16s%16s%20s%22s\n","狱号","姓名","性别","入狱时间","总出勤次数");
}
void printHead2( )      /*打印服刑人员详细出勤情况的表头*/
{
printf("%2s%16s%16s%20s%20s\n","狱号","姓名","性别","出勤时间","出勤内容");
}
void menu( )         /*顶层菜单函数*/
{
printf("&&&&&&&&&&&&&&&&&&&&&&&&&&#############################&&&&&&&&&&&&&&&&&&&&&&&");
printf("\n\n");
printf("\n\n\t\t------------欢迎来到服刑人员出勤信息管理系统-----------\n\n");
printf("\t\t\t 1. 显示服刑人员基本信息 \n\n");
printf("\t\t\t 2. 服刑人员基本信息管理 \n\n");
printf("\t\t\t 3.服刑人员详细出勤情况查询  \n\n");
printf("\t\t\t 4. 服刑人员基本信息查询 \n\n");
printf("\t\t\t 5. 服刑人员总出勤次数排序 \n\n");
printf("\t\t\t 0. 退出系统 \n\n");
printf("\n\n");
printf("\n\n&&&&&&&&&&&&&&&&&&&&&&&&############################&&&&&&&&&&&&&&&&&&&&&&&&&&\n\n");
}

void menuBase( )     /*2、基本信息管理菜单函数*/
{
printf("&&&&&&&&&&&&&&&&&&&&&&&&############################&&&&&&&&&&&&&&&&&&&&&&&&&&\n\n");
	printf("\n\n\n");
	printf("\n\n");
		printf("%%%%%%%% 1. 插入服刑人员信息记录\t2. 删除服刑人员信息记录 %%%%%%%%\n\n");
		printf("\n");
		printf("%%%%%%%% 3. 修改服刑人员信息记录\t0. 返回上层菜单 %%%%%%%%\n\n");
		printf("\n\n");
			printf("\n\n\n");
				printf("\n\n&&&&&&&&&&&&&&&&&&&&&&&&############################&&&&&&&&&&&&&&&&&&&&&&&&&&\n\n");
}

void menuManage( )     /*3、服刑人员详细出勤情况管理菜单函数*/
{
	printf("&&&&&&&&&&&&&&&&&&&&&&&&############################&&&&&&&&&&&&&&&&&&&&&&&&&&\n\n");
	printf("\n\n\n");
	printf("\n\n");
	printf("\n\n");
			printf("@@@@@@@@ 1.选择年月 @@@@@@@@\n\n");
		printf("@@@@@@@@ 2.查询服刑人员详细出勤情况 @@@@@@@@\n\n");
		printf("@@@@@@@@ 0. 返回上层菜单 @@@@@@@@\n\n");
				printf("\n\n\n");
				printf("\n");
				printf("\n\n&&&&&&&&&&&&&&&&&&&&&&&&############################&&&&&&&&&&&&&&&&&&&&&&&&&&\n\n");
}
 
void menuCount( )    /*5、服刑人员总出勤次数排序菜单函数*/
{
	printf("&&&&&&&&&&&&&&&&&&&&&&&&############################&&&&&&&&&&&&&&&&&&&&&&&&&&\n\n");
	printf("\n\n");
	printf("\n\n");
		printf("&&&&&&&& 1. 出勤最高个体次数&&&&&&&&\n\n");
		printf("&&&&&&&& 2. 出勤最低个体次数 &&&&&&&&\n\n");
		printf("&&&&&&&& 3. 出勤个体平均次数 &&&&&&&&\n\n");
		printf("&&&&&&&& 0. 返回上层菜单 &&&&&&&&\n\n");
				printf("\n\n\n");
				printf("\n");
				printf("\n\n&&&&&&&&&&&&&&&&&&&&&&&&############################&&&&&&&&&&&&&&&&&&&&&&&&&&\n\n");
}

void menuSearch()    /*4、服刑人员基本信息查询菜单函数*/
{
		printf("&&&&&&&&&&&&&&&&&&&&&&&&############################&&&&&&&&&&&&&&&&&&&&&&&&&&\n\n");
	printf("\n\n\n");
	printf("\n\n");
		printf("######## 1. 按狱号查询   ########\n\n");
		printf("######## 2. 按姓名查询   ########\n\n");
		printf("######## 0. 返回上层菜单 ########\n\n");
				printf("\n\n\n");
				printf("\n");
				printf("\n\n&&&&&&&&&&&&&&&&&&&&&&&&############################&&&&&&&&&&&&&&&&&&&&&&&&&&\n\n");
}
int baseManage(Criminal cri[],int n)    	     /*该函数完成基本信息管理*/
/*按狱号进行插入删除修改，狱号不能重复*/
{  
		int choice,t,find[NUM],j;
     Criminal s;
do
	    {  system("cls"); 
menuBase( );                  /*显示对应的二级菜单*/
printf("choose one operation you want to do:\n");
		     scanf("%d",&choice);	          /*读入选项*/
		     switch(choice)
		     {
			   case 1:	  readCri(&s,1);      /*读入一条待插入的服刑人员记录*/
					 n=insertCri(cri,n,s);
					 printf("插入成功！");
					 			printf("按0退出此界面：");
			do {
				scanf("%d",&j);
			  printf("please input again!\n");
			}while(j);/*调用函数插入服刑人员记录*/
					 break;
			   case 2:  printf("Input the number deleted\n");
					 scanf("%ld",&s.num);  /*读入一个待删除的服刑人员狱号*/
					 n=deleteCri(cri,n,s);
					 					 printf("删除成功！");
					 			printf("按0退出此界面：");
			do {
				scanf("%d",&j);
			  printf("please input again!\n");
			}while(j);/*调用函数删除指定服刑人员的记录*/
					 break;
			   case 3:  printf("Input the number modified\n");
					 scanf("%ld",&s.num);  /*读入一个待修改的服刑人员狱号*/
				      t=searchCri(cri,n,s,1,find) ; /*调用函数查找指定狱号的服刑人员记录*/
				      if (t)                 /*如果该狱号的记录存在*/
					 {
						  readCri(&s,1);   /*读入一条完整的服刑人员记录信息*/
					      cri[find[0]]=s;
						  					 printf("修改成功！");
					 			printf("按0退出此界面：");
			do {
				scanf("%d",&j);
			  printf("please input again!\n");
			}while(j);break;
                    /*将刚读入的记录赋值给需要修改的数组记录*/ 					 
					  }					 
					 else                 /*如果该狱号的记录不存在*/ 
 printf("this criminal is not in,can not be modified.\n");
			printf("按0退出此界面：");
			do {
				scanf("%d",&j);
			  printf("please input again!\n");
			}while(j);                            /*输出提示信息*/
					 break;
			    case 0: break;
		    }
	}while(choice);
return n;                             /*返回当前操作结束后的实际记录条数*/
}
 /*void scoreManage(Content con[],int n);     /* 3. 服刑人员详细出勤情况查询
{
      int i,choice,findnum,f[NUM],y,m;
Content s;
	   do
{
			menuManage( );                         /*显示对应的二级菜单
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printf("Input year and month to be searched:\n");
				      scanf("%d%d",&y&m);         /*输入待查询的年月
					  break;
				case 2:   printf("服刑人员详细出勤情况如下:\n");
	                   /*服刑人员详细出勤情况*	  
				      break;   
				case 0:   break;
			}
		 	if (choice>=1&&choice<=2)
			{ 
				findnum=searchCon(con,n,s,choice,f);    /*查找的符合条件元素的下标存于f数组中
				if (findnum)				     /*如果查找成功
				{
			   		 printHead2( );                  /*打印表头2
					 for (i=0;i<findnum;i++)         /*循环控制f数组的下标
	      	 printCon(&con[f[i]],1);      /*每次输出一条记录
				}
		    		else
			    	    printf("this record does not exist!\n"); /*如果查找不到元素，则输出提示信息
		     }		
	    }while (choice);
}
*/

void searchManage(Criminal cri[],int n)               /*该函数完成根据条件查询功能*/
{
    int i,choice,findnum,f[NUM],j;
Criminal s;
	   do
{	
	menuSearch( );                         /*显示对应的二级菜单*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printf("Input a criminal\'s num will be searched:\n");
				      scanf("%ld",&s.num);         /*输入待查询服刑人员的狱号*/
					  break;
				case 2:   printf("Input a criminal\'s name will be searched:\n");
				      scanf("%s",s.name);	          /*输入待查询服刑人员的姓名*/		  
				      break;   
				case 0:   break;
			}
		 	if (choice>=1&&choice<=2)
			{ 
				findnum=searchCri(cri,n,s,choice,f);    /*查找的符合条件元素的下标存于f数组中*/
				if (findnum)				     /*如果查找成功*/
				{system("cls");
			   		 printHead1( );                  /*打印表头*/
					 for (i=0;i<findnum;i++)         /*循环控制f数组的下标*/
	      	 printCri(&cri[f[i]],1);      /*每次输出一条记录*/
				printf("按0退出此界面：");
			do {
				scanf("%d",&j);
			  printf("please input again!\n");
			}while(j);
			system("cls");
			continue;
				}
				else {
					system("cls");
				printf("this record does not exist!\n");
						printf("按0退出此界面：");
			do {
				scanf("%d",&j);
			  printf("please input again!\n");
			}while(j);
					system("cls");
			continue;
				} /*如果查找不到元素，则输出提示信息*/
		     }
	    }while (choice);
}


/*此处的编程预设：
void countManage(Criminal cri[],int n)               /*该函数服刑人员总出勤次数排序功能
{
		int choice;
		double mark[3][3];
		do
		{
			menuCount( );                        /*显示对应的二级菜单
			calcuMark(mark,cri,n);                 /*调用此函数求三门课的最高、最低、平均值
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printMarkCourse("出勤次数最高的次数是:\n",mark,0);  /*输出最高的次数
				      break;
				case 2:   printMarkCourse("出勤次数最低的次数是:\n",mark,1);  /*输出最低的次数
				      break;
				case 3:   printMarkCourse("出勤次数的平均次数是:\n",mark,2);  /*输出平均次数
				      break;
				case 0:   break;
			}
		}while (choice);
}*/

int runMain(Criminal cri[],int n,int choice)    /*主控模块，对应于一级菜单其下各功能选择执行(应该还有Content con[])*/
{
	int s;
		switch(choice)
			{
		case 1:{ system("cls");
			printHead1( );      /* 1. 显示基本信息*/
			/*sortCri(cri,n,1);    按狱号由小到大的顺序排序记录*/
			printCri(cri,n);
			printf("按0退出此界面：");
			do {
				scanf("%d",&s);
			  printf("please input again!\n");
			}while(s);        /*按狱号由小到大的顺序输出所有记录*/
			system("cls");	break;}
		case 2: { 	n=baseManage(cri,n);    /* 2.服刑人员基本信息管理*/
			system("cls");
					break;}
		/*case 3:{ 
				 scoreManage(con,n);     3. 服刑人员详细出勤情况查询
					break;}*/
		case 4: { 	
		searchManage(cri,n);    /* 4.服刑人员基本信息查询*/
		system("cls");
					break;}
			case 5: system("cls");{ /*服刑人员总出勤次数排序*/
			/*countManage(cri,n);*/
				break;}
			case 0:break;
			}	
			return n;
	}
int main( )
{
		Criminal cri[NUM]; 
         /*定义实参一维数组存储学生记录(	Content con[NUM]; )*/
      int choice,n;
	 n=readFile(cri);
/*首先读取文件，记录条数返回赋值给n( m=readFile(con);)*/
	 if (!n)                          /*如果原来的文件为空*/
	     {
		    n=createFile(cri);              /*则首先要建立文件，从键盘上读入一系列记录存于文件*/
}	 
	 /* if (!m)                          如果原来的文件为空
	     {
		    m=createFile(con);  }            则首先要建立文件，从键盘上读入一系列记录存于文件*/
	 
	do
	     {
	         menu();                      /*显示主菜单*/
	         printf("Please input your choice: ");
	         scanf("%d",&choice);
	         if (choice>=0&&choice<=5)
	              n=runMain(cri,n,choice);    /*通过调用此函数进行一级功能项的选择执行(con)*/
	        else 
		          printf("error input,please input your choice again!\n");
	} while (choice);
	/*sortCri(cri,n,1);                   存入文件前按狱号由小到大排序*/ 
	     saveFile(cri,n);
		   /*  saveFile(con,m);                          将结果存入文件*/
      return 0;
}
