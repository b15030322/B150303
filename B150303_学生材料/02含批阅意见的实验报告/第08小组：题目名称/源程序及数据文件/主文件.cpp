#include<stdio.h>
#include<stdlib.h>
#include"file.h"
#include"criminal.h"
/*�˴���Ӧ�����������ļ����ֶ�#include"file.h"��#include"content.h"*/

void printHead1( )      /*��ӡ������Ա��Ϣ�ı�ͷ*/
{
printf("%2s%16s%16s%20s%22s\n","����","����","�Ա�","����ʱ��","�ܳ��ڴ���");
}
void printHead2( )      /*��ӡ������Ա��ϸ��������ı�ͷ*/
{
printf("%2s%16s%16s%20s%20s\n","����","����","�Ա�","����ʱ��","��������");
}
void menu( )         /*����˵�����*/
{
printf("&&&&&&&&&&&&&&&&&&&&&&&&&&#############################&&&&&&&&&&&&&&&&&&&&&&&");
printf("\n\n");
printf("\n\n\t\t------------��ӭ����������Ա������Ϣ����ϵͳ-----------\n\n");
printf("\t\t\t 1. ��ʾ������Ա������Ϣ \n\n");
printf("\t\t\t 2. ������Ա������Ϣ���� \n\n");
printf("\t\t\t 3.������Ա��ϸ���������ѯ  \n\n");
printf("\t\t\t 4. ������Ա������Ϣ��ѯ \n\n");
printf("\t\t\t 5. ������Ա�ܳ��ڴ������� \n\n");
printf("\t\t\t 0. �˳�ϵͳ \n\n");
printf("\n\n");
printf("\n\n&&&&&&&&&&&&&&&&&&&&&&&&############################&&&&&&&&&&&&&&&&&&&&&&&&&&\n\n");
}

void menuBase( )     /*2��������Ϣ����˵�����*/
{
printf("&&&&&&&&&&&&&&&&&&&&&&&&############################&&&&&&&&&&&&&&&&&&&&&&&&&&\n\n");
	printf("\n\n\n");
	printf("\n\n");
		printf("%%%%%%%% 1. ���������Ա��Ϣ��¼\t2. ɾ��������Ա��Ϣ��¼ %%%%%%%%\n\n");
		printf("\n");
		printf("%%%%%%%% 3. �޸ķ�����Ա��Ϣ��¼\t0. �����ϲ�˵� %%%%%%%%\n\n");
		printf("\n\n");
			printf("\n\n\n");
				printf("\n\n&&&&&&&&&&&&&&&&&&&&&&&&############################&&&&&&&&&&&&&&&&&&&&&&&&&&\n\n");
}

void menuManage( )     /*3��������Ա��ϸ�����������˵�����*/
{
	printf("&&&&&&&&&&&&&&&&&&&&&&&&############################&&&&&&&&&&&&&&&&&&&&&&&&&&\n\n");
	printf("\n\n\n");
	printf("\n\n");
	printf("\n\n");
			printf("@@@@@@@@ 1.ѡ������ @@@@@@@@\n\n");
		printf("@@@@@@@@ 2.��ѯ������Ա��ϸ������� @@@@@@@@\n\n");
		printf("@@@@@@@@ 0. �����ϲ�˵� @@@@@@@@\n\n");
				printf("\n\n\n");
				printf("\n");
				printf("\n\n&&&&&&&&&&&&&&&&&&&&&&&&############################&&&&&&&&&&&&&&&&&&&&&&&&&&\n\n");
}
 
void menuCount( )    /*5��������Ա�ܳ��ڴ�������˵�����*/
{
	printf("&&&&&&&&&&&&&&&&&&&&&&&&############################&&&&&&&&&&&&&&&&&&&&&&&&&&\n\n");
	printf("\n\n");
	printf("\n\n");
		printf("&&&&&&&& 1. ������߸������&&&&&&&&\n\n");
		printf("&&&&&&&& 2. ������͸������ &&&&&&&&\n\n");
		printf("&&&&&&&& 3. ���ڸ���ƽ������ &&&&&&&&\n\n");
		printf("&&&&&&&& 0. �����ϲ�˵� &&&&&&&&\n\n");
				printf("\n\n\n");
				printf("\n");
				printf("\n\n&&&&&&&&&&&&&&&&&&&&&&&&############################&&&&&&&&&&&&&&&&&&&&&&&&&&\n\n");
}

void menuSearch()    /*4��������Ա������Ϣ��ѯ�˵�����*/
{
		printf("&&&&&&&&&&&&&&&&&&&&&&&&############################&&&&&&&&&&&&&&&&&&&&&&&&&&\n\n");
	printf("\n\n\n");
	printf("\n\n");
		printf("######## 1. �����Ų�ѯ   ########\n\n");
		printf("######## 2. ��������ѯ   ########\n\n");
		printf("######## 0. �����ϲ�˵� ########\n\n");
				printf("\n\n\n");
				printf("\n");
				printf("\n\n&&&&&&&&&&&&&&&&&&&&&&&&############################&&&&&&&&&&&&&&&&&&&&&&&&&&\n\n");
}
int baseManage(Criminal cri[],int n)    	     /*�ú�����ɻ�����Ϣ����*/
/*�����Ž��в���ɾ���޸ģ����Ų����ظ�*/
{  
		int choice,t,find[NUM],j;
     Criminal s;
do
	    {  system("cls"); 
menuBase( );                  /*��ʾ��Ӧ�Ķ����˵�*/
printf("choose one operation you want to do:\n");
		     scanf("%d",&choice);	          /*����ѡ��*/
		     switch(choice)
		     {
			   case 1:	  readCri(&s,1);      /*����һ��������ķ�����Ա��¼*/
					 n=insertCri(cri,n,s);
					 printf("����ɹ���");
					 			printf("��0�˳��˽��棺");
			do {
				scanf("%d",&j);
			  printf("please input again!\n");
			}while(j);/*���ú������������Ա��¼*/
					 break;
			   case 2:  printf("Input the number deleted\n");
					 scanf("%ld",&s.num);  /*����һ����ɾ���ķ�����Ա����*/
					 n=deleteCri(cri,n,s);
					 					 printf("ɾ���ɹ���");
					 			printf("��0�˳��˽��棺");
			do {
				scanf("%d",&j);
			  printf("please input again!\n");
			}while(j);/*���ú���ɾ��ָ��������Ա�ļ�¼*/
					 break;
			   case 3:  printf("Input the number modified\n");
					 scanf("%ld",&s.num);  /*����һ�����޸ĵķ�����Ա����*/
				      t=searchCri(cri,n,s,1,find) ; /*���ú�������ָ�����ŵķ�����Ա��¼*/
				      if (t)                 /*��������ŵļ�¼����*/
					 {
						  readCri(&s,1);   /*����һ�������ķ�����Ա��¼��Ϣ*/
					      cri[find[0]]=s;
						  					 printf("�޸ĳɹ���");
					 			printf("��0�˳��˽��棺");
			do {
				scanf("%d",&j);
			  printf("please input again!\n");
			}while(j);break;
                    /*���ն���ļ�¼��ֵ����Ҫ�޸ĵ������¼*/ 					 
					  }					 
					 else                 /*��������ŵļ�¼������*/ 
 printf("this criminal is not in,can not be modified.\n");
			printf("��0�˳��˽��棺");
			do {
				scanf("%d",&j);
			  printf("please input again!\n");
			}while(j);                            /*�����ʾ��Ϣ*/
					 break;
			    case 0: break;
		    }
	}while(choice);
return n;                             /*���ص�ǰ�����������ʵ�ʼ�¼����*/
}
 /*void scoreManage(Content con[],int n);     /* 3. ������Ա��ϸ���������ѯ
{
      int i,choice,findnum,f[NUM],y,m;
Content s;
	   do
{
			menuManage( );                         /*��ʾ��Ӧ�Ķ����˵�
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printf("Input year and month to be searched:\n");
				      scanf("%d%d",&y&m);         /*�������ѯ������
					  break;
				case 2:   printf("������Ա��ϸ�����������:\n");
	                   /*������Ա��ϸ�������*	  
				      break;   
				case 0:   break;
			}
		 	if (choice>=1&&choice<=2)
			{ 
				findnum=searchCon(con,n,s,choice,f);    /*���ҵķ�������Ԫ�ص��±����f������
				if (findnum)				     /*������ҳɹ�
				{
			   		 printHead2( );                  /*��ӡ��ͷ2
					 for (i=0;i<findnum;i++)         /*ѭ������f������±�
	      	 printCon(&con[f[i]],1);      /*ÿ�����һ����¼
				}
		    		else
			    	    printf("this record does not exist!\n"); /*������Ҳ���Ԫ�أ��������ʾ��Ϣ
		     }		
	    }while (choice);
}
*/

void searchManage(Criminal cri[],int n)               /*�ú�����ɸ���������ѯ����*/
{
    int i,choice,findnum,f[NUM],j;
Criminal s;
	   do
{	
	menuSearch( );                         /*��ʾ��Ӧ�Ķ����˵�*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printf("Input a criminal\'s num will be searched:\n");
				      scanf("%ld",&s.num);         /*�������ѯ������Ա������*/
					  break;
				case 2:   printf("Input a criminal\'s name will be searched:\n");
				      scanf("%s",s.name);	          /*�������ѯ������Ա������*/		  
				      break;   
				case 0:   break;
			}
		 	if (choice>=1&&choice<=2)
			{ 
				findnum=searchCri(cri,n,s,choice,f);    /*���ҵķ�������Ԫ�ص��±����f������*/
				if (findnum)				     /*������ҳɹ�*/
				{system("cls");
			   		 printHead1( );                  /*��ӡ��ͷ*/
					 for (i=0;i<findnum;i++)         /*ѭ������f������±�*/
	      	 printCri(&cri[f[i]],1);      /*ÿ�����һ����¼*/
				printf("��0�˳��˽��棺");
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
						printf("��0�˳��˽��棺");
			do {
				scanf("%d",&j);
			  printf("please input again!\n");
			}while(j);
					system("cls");
			continue;
				} /*������Ҳ���Ԫ�أ��������ʾ��Ϣ*/
		     }
	    }while (choice);
}


/*�˴��ı��Ԥ�裺
void countManage(Criminal cri[],int n)               /*�ú���������Ա�ܳ��ڴ���������
{
		int choice;
		double mark[3][3];
		do
		{
			menuCount( );                        /*��ʾ��Ӧ�Ķ����˵�
			calcuMark(mark,cri,n);                 /*���ô˺��������ſε���ߡ���͡�ƽ��ֵ
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printMarkCourse("���ڴ�����ߵĴ�����:\n",mark,0);  /*�����ߵĴ���
				      break;
				case 2:   printMarkCourse("���ڴ�����͵Ĵ�����:\n",mark,1);  /*�����͵Ĵ���
				      break;
				case 3:   printMarkCourse("���ڴ�����ƽ��������:\n",mark,2);  /*���ƽ������
				      break;
				case 0:   break;
			}
		}while (choice);
}*/

int runMain(Criminal cri[],int n,int choice)    /*����ģ�飬��Ӧ��һ���˵����¸�����ѡ��ִ��(Ӧ�û���Content con[])*/
{
	int s;
		switch(choice)
			{
		case 1:{ system("cls");
			printHead1( );      /* 1. ��ʾ������Ϣ*/
			/*sortCri(cri,n,1);    ��������С�����˳�������¼*/
			printCri(cri,n);
			printf("��0�˳��˽��棺");
			do {
				scanf("%d",&s);
			  printf("please input again!\n");
			}while(s);        /*��������С�����˳��������м�¼*/
			system("cls");	break;}
		case 2: { 	n=baseManage(cri,n);    /* 2.������Ա������Ϣ����*/
			system("cls");
					break;}
		/*case 3:{ 
				 scoreManage(con,n);     3. ������Ա��ϸ���������ѯ
					break;}*/
		case 4: { 	
		searchManage(cri,n);    /* 4.������Ա������Ϣ��ѯ*/
		system("cls");
					break;}
			case 5: system("cls");{ /*������Ա�ܳ��ڴ�������*/
			/*countManage(cri,n);*/
				break;}
			case 0:break;
			}	
			return n;
	}
int main( )
{
		Criminal cri[NUM]; 
         /*����ʵ��һά����洢ѧ����¼(	Content con[NUM]; )*/
      int choice,n;
	 n=readFile(cri);
/*���ȶ�ȡ�ļ�����¼�������ظ�ֵ��n( m=readFile(con);)*/
	 if (!n)                          /*���ԭ�����ļ�Ϊ��*/
	     {
		    n=createFile(cri);              /*������Ҫ�����ļ����Ӽ����϶���һϵ�м�¼�����ļ�*/
}	 
	 /* if (!m)                          ���ԭ�����ļ�Ϊ��
	     {
		    m=createFile(con);  }            ������Ҫ�����ļ����Ӽ����϶���һϵ�м�¼�����ļ�*/
	 
	do
	     {
	         menu();                      /*��ʾ���˵�*/
	         printf("Please input your choice: ");
	         scanf("%d",&choice);
	         if (choice>=0&&choice<=5)
	              n=runMain(cri,n,choice);    /*ͨ�����ô˺�������һ���������ѡ��ִ��(con)*/
	        else 
		          printf("error input,please input your choice again!\n");
	} while (choice);
	/*sortCri(cri,n,1);                   �����ļ�ǰ��������С��������*/ 
	     saveFile(cri,n);
		   /*  saveFile(con,m);                          ����������ļ�*/
      return 0;
}
