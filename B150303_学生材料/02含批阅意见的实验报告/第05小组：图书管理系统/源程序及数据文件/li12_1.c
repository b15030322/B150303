

#include<stdio.h>
#include<stdlib.h>
#include"file.h"
#include"book.h"
void printHead()       /*��ӡͼ����Ϣ��ͷ*/
{ 
	printf("%10s%10s%10s%10s%10s%10s%10s%10s%15s%10s\n","���","����","����","�۸�","һ","��","��","��","�ܽ�����","����");
}
void triangle()    /*����*/
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
void menu()         /*����˵�����*/
{
		printf("    -------------------------------------------------------------     \n");    
		printf("                          ͼ �� �� �� ϵ ͳ \n");
		printf("                        1. �� ʾ ͼ �� �� Ϣ \n");
		printf("                        2. �� �� �� Ϣ �� �� \n");
		printf("                        3. �� �� �� �� �� \n");
		printf("                        4. �� �� �� ͳ �� \n");
		printf("                        5. �� �� �� �� �� ѯ \n");
		printf("                        0. �� ��         \n");
		printf("    -------------------------------------------------------------     \n");
}
void menuBase()   /*ͼ����Ϣ����˵�����*/
{
		printf("                        1. �� �� ͼ �� �� ¼ \n");
		printf("                        2. ɾ �� ͼ �� �� ¼ \n");
		printf("                        3. �� �� ͼ �� �� ¼ \n");
		printf("                        0. �� �� �� �� �� �� \n");
}
void menuScore()   /*����������˵�����*/
{
		printf("                        1. �� �� ͼ �� �� �� �� �� \n");
		printf("                        2. �� �� �� �� �� �� �� \n");
		printf("                        0. �� �� �� �� �� �� \n");
}
void menuCount()   /*������ͳ�Ʋ˵�����*/
{
		printf("                        1. �� �� �� �� �� �� �� \n");
		printf("                        2. �� �� �� �� �� �� �� \n");
		printf("                        3. �� �� ƽ �� �� �� �� \n");
		printf("                        0. �� �� �� �� �� �� \n");
}
void menuSearch()    /*����������ѯ�˵�����*/
{
		printf("                        1. �� �� �� �� ѯ \n");
		printf("                        2. �� �� �� �� ѯ \n");
		printf("                        0. �� �� �� �� �� �� \n");
}
int baseManage(Book boo[],int n)    	     /*�ú������ͼ����Ϣ����*/
/*����Ž��в���ɾ���޸ģ���Ų����ظ�*/
{  
	int choice,t,find[NUM];
	Book b;
	do
	{   
		menuBase( );                  /*��ʾ��Ӧ�Ķ����˵�*/
		printf("choose one operation you want to do:\n");
		scanf("%d",&choice);
		if(choice<=3&&choice>=0) /*����ѡ��*/
		switch(choice)
		{
			 case 1:	 readBoo(&b,1);       /*����һ���������ͼ����Ϣ*/
					 n=insertBoo(boo,n,b);   /*���ú�������ͼ����Ϣ*/
					 break;
			 case 2:  printf("Input the number deleted\n");
					 scanf("%ld",&b.num);  /*����һ����ɾ����ͼ����*/
					 n=deleteBoo(boo,n,b);   /*���ú���ɾ��ָ����ŵ�ͼ����Ϣ*/
					 break;
			 case 3:  printf("Input the number modified\n");
					 scanf("%ld",&b.num);  /*����һ�����޸ĵ�ͼ����*/
				      t=searchBoo(boo,n,b,1,find) ; /*���ú�������ָ����ŵ�ͼ���¼*/
					  if (t)                 /*����ñ�ŵļ�¼����*/
			  		 {
						  readBoo(&b,1);   /*����һ��������ͼ����Ϣ*/
					      boo[find[0]]=b;    /*���ն���ļ�¼��ֵ����Ҫ�޸ĵ������¼*/ 					 
					  }					 
					 else                 /*����ñ�ŵļ�¼������*/ 
		             printf("this book is not in,can not be modified.\n"); /*�����ʾ��Ϣ*/
					 break;
			         case 0: 
						 break;
		   }
		 else 
			 printf("\t\t\t\t\t�����������һ�����룡\n");
	}while(choice);
	 return n;
 }
void scoreManage(Book boo[],int n)          /*�ú�����ɽ�����������*/
{  
	int choice;
	do
	{
		menuScore( );                        /*��ʾ��Ӧ�Ķ����˵�*/
		printf("choose one operation you want to do:\n");
		scanf("%d",&choice);
		if(choice<=2&&choice>=0)/*�������ѡ��*/
		switch(choice)
		{
			case 1:   calcuTotal(boo,n);    
					  break;
			case 2:   calcuRank(boo,n);        
				      break;		
			case 0:   break;
		}
		else 
			 printf("\t\t\t\t\t�����������һ�����룡\n");
	}while(choice);
}
void printMarkCourse(char *b,double m[4][4],int k)   /*��ӡ����ͨ�ú�������countManage ����*/
{                 /*��ʽ����k���������ͬ�����ݣ�0��1��2�ֱ��Ӧ��ߡ���͡�ƽ��*/
int i;
    printf(b);                                  /*�����s��������������������ʾ��Ϣ*/
    for (i=0;i<4;i++)                           /*i������һ����*/
		  printf("%10.2lf",m[i][k]);
	   printf("\n");
}
void countManage(Book boo[],int n)               /*�ú�����ɽ�����ͳ�ƹ���*/
{
		int choice;
		double mark[4][4];
		do
		{
			menuCount();                        /*��ʾ��Ӧ�Ķ����˵�*/
			calcuMark(mark,boo,n);
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printMarkCourse("�ļ��Ƚ���������߷ֱ���:\n",mark,0);  /*������*/
				      break;
				case 2:   printMarkCourse("�ļ��Ƚ���������ͷֱ���:\n",mark,1);  /*������*/
				      break;
				case 3:   printMarkCourse("�ļ��Ƚ�������ƽ���ֱ���:\n",mark,2);  /*���ƽ��*/
				      break;
				case 0:   break;
			}
		}while (choice);
}
void searchManage(Book boo[],int n)               /*�ú�����ɸ���������ѯ����*/
{
    int i,choice,findnum,f[NUM];
Book b;
	   do
{
			menuSearch( );                         /*��ʾ��Ӧ�Ķ����˵�*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printf("Input a book\'s num will be searched:\n");
				      scanf("%ld",&b.num);         /*�������ѯͼ��ı��*/
					  break;
				case 2:   printf("Input a book\'s title will be searched:\n");
				      scanf("%s",&b.title);	          /*�������ѯͼ�������*/		  
				      break;   
				case 0:   break;
			}
		 	if (choice>=1&&choice<=2)		
			{ 
				findnum=searchBoo(boo,n,b,choice,f);    /*���ҵķ�������Ԫ�ص��±����f������*/
				if (findnum)				     /*������ҳɹ�*/
				{
			   		 printHead();                  /*��ӡ��ͷ*/
					 for (i=0;i<findnum;i++)         /*ѭ������f������±�*/
	      	 printBoo(&boo[f[i]],1);      /*ÿ�����һ����¼*/
				}
		    		else
			    	    printf("this record does not exist!\n"); /*������Ҳ���Ԫ�أ��������ʾ��Ϣ*/
		     }		
	    }while (choice);
}

int runMain(Book boo[],int n,int choice)    /*����ģ�飬��Ӧ��һ���˵����¸�����ѡ��ִ��*/
{
		switch(choice)
		{
			case 1: printHead( );           /* 1. ��ʾ������Ϣ*/
				 sortBoo(boo,n,1);         /*�������С�����˳�������¼*/ 
          	 printBoo(boo,n);          /*�������С�����˳��������м�¼*/
					break;
			case 2: n=baseManage(boo,n);    /* 2. ������Ϣ����*/
			   	     break;
			case 3: scoreManage(boo,n);     /* 3. ����������*/
					break;
			case 4: countManage(boo,n);     /* 4. ������ͳ��*/
					break;
			case 5: searchManage(boo,n);     /* 5. ����������ѯ*/
				     break;
          case 0: break;
		}
		return n;
}

int main( )
{
		Book boo[NUM];                /*����ʵ��һά����洢ͼ���¼*/
      int choice,n;
	 n=readFile(boo);                  /*���ȶ�ȡ�ļ�����¼�������ظ�ֵ��n*/
	 if (!n)                          /*���ԭ�����ļ�Ϊ��*/
	     {
		    n=createFile(boo);              /*������Ҫ�����ļ����Ӽ����϶���һϵ�м�¼�����ļ�*/
}	 	 
	do
	     {
	         menu();                      /*��ʾ���˵�*/
	         printf("Please input your choice: ");
	         scanf("%d",&choice);
	         if (choice>=0&&choice<=5)
	              n=runMain(boo,n,choice);    /*ͨ�����ô˺�������һ���������ѡ��ִ��*/
	         else 
		          printf("error input,please input your choice again!\n");
	} while (choice);
	sortBoo(boo,n,1);                   /*�����ļ�ǰ��ѧ����С��������*/ 
	     saveFile(boo,n);                   /*����������ļ�*/
      return 0;
}
