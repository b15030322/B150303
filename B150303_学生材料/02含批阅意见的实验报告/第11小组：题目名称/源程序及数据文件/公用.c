
#include "train.h"
#include <stdlib.h>
#include <windows.h>
#include <stdio.h>
//-----------�ո����----------//
void space()
{	int j;
	for(j=1;j<15;j++)
	    printf("\n");
}
//---------����Ա��������----------//
int check()
{
	
	char password[6];
	int i,n,flag;
	char m[6]={'L','S','J','2','3','3'};
	system("cls");//����
	printf("���������Ա���룺");
	for(i=0;i<6;i++)
	{	n=i;
		password[i]=getch();
		if(password[i]=='\b')
		{	
			i=i-2;
		    printf("\b");
			printf(" ");
		}
		if(n==i)
		{
			printf("*");
		}
		else 
		{
			printf("\b");
		}
	}
	printf("\n");
	for(flag=1,n=0;flag!=0&&n<7;n++)
		if(password[n]!=m[n])
			flag=0;
		else
			n++;
    if(flag)
		printf("correct!");
	else
		printf("error!");
return flag;
}
//--------------һ�����˵�---------------//
int runmenu(train tra[],int choice,int n)
{
    int j;
	system("cls");//����
	for(j=1;j<10;j++)
	    printf("\n");//���ƿո�
	switch(choice)
	{
	case 1:
			n=managermenu(tra,n);
				break;
	case 2:
			searchmenu(tra,n);
				break;
	case 3:
			operatemenu(tra,n);
				break;
    case 0:break;
	}
	return n;
}
//----------------------������ʾ---------------//
void cover()
{   int i,j;
    for(i=1;i<40;i++)
		printf("---");//��ͷҳ������
	for(j=1;j<12;j++)
	    printf("\n");//���ƿո�
	//�𳵼�����ͼƬ
	printf("\t\t\t\t\t-----------------------------------------------------------------------------\n");
	printf("\t\t\t\t       /\n");
    printf("\t\t\t\t      /     ������    ������    ������    ������   ������   ������    \n");
	printf("\t\t\t\t     /      ��  ��    ��  ��    ��  ��    ��  ��   ��  ��   ��  ��\n");
	printf("\t\t\t\t    /       ������    ������    ������    ������   ������   ������\n");
	printf("\t\t\t\t   /    (*^__^*)��˾����\n");
	printf("\t\t\t\t   ---------------------------------------------------------------------------------\n");
	Sleep(2000);//��ʱ
    system("cls");//����
}
//------------------��������Ա�˵�------------//
int managermenu(train tra[],int n)
{	
	int choice;
	train t;
	if(check())
	{
		do
	{			
		smenuone();
		scanf("%d",&choice);
		if(choice<=3&&choice>=0)
		{	
				switch (choice)
			{
				case 1: system("cls");//����				
						n=add(tra,n,t);
						break;
				case 2: system("cls");//����	
						printf("�����Ҫ�޸ĵĳ���\n");
						scanf("%s",t.number);
						system("cls");//����
						modify(tra,n,t);
						break;
				case 3: system("cls");//����			
						printf("�����Ҫɾ���ĳ���\n");
						scanf("%s",t.number);
						system("cls");//����
						n=del(tra,n,t);												
				case 0: break;
			}
		}      		
		else 
			printf("\t\t\t\t\t�����������һ�����룡\n");	
	}while (choice);
	}
	else
	{
	  printf("�������󣬽�������һ���˵�");
	  Sleep(2000);//��ʱ
	}
	return n;
}
//------------------������ѯ�˵�--------------//
void searchmenu(train tra[],int n)
{   
	int choice;
	do
	{
		smenutwo();
		scanf("%d",&choice);
		if(choice<=3&&choice>=0)
		switch (choice)
		{
		case 1: 
				system("cls");//����
				put(tra,n);
			break;
		case 2:	system("cls");//���� 
				calcurank(tra,n);
			break;
		case 3:
			system("cls");//����
			find_train(tra,n);
			break;
		case 0: break;
		}
        
	else 
		printf("\t\t\t\t\t�����������һ�����룡\n");
	
	}while (choice);
}
//--------------�����ͻ��˵�---------------//
void operatemenu(train tra[],int n)
{
	int choice;
	do
	{
    smenuthree();
	scanf("%d",&choice);
	if(choice<=3&&choice>=0)
	switch (choice)
	{
	case 1: system("cls");//����
			UserReg();
			break;
    case 2: system("cls");//����
			if(Login())
			{
				book(tra,n);
			}
			else
					printf("�������󣬽�������һ���˵�");
				    Sleep(2000);//��ʱ
			break;
	case 3: system("cls");//����
			if(Login())
			{
				cancle(tra,n);
			}
			else
					printf("�������󣬽�������һ���˵�");
				    Sleep(2000);//��ʱcancle(tra);
			break;
	case 0: break;
	}
        
	else 
		printf("\t\t\t\t\t�����������һ�����룡\n");
	
	}while (choice);
}

void fmenu()
{		
		printf("\t\t �q�T�T�T�T�T�T�T�T�T���������T�T�T�r\n");  
        printf("\t\t��         ��˾���𳵹���ϵͳ       ��\n");  
        printf("\t\t�t�T�T�T���������T�T�T�T�T�T�T�T�T�T�s\n");  
        printf("\t\t   ����������������������������-��\n");  
        printf("\t\t   �� 1. ����Ա����ϵͳ         ��\n");  
        printf("\t\t   ��                           ��\n");  
        printf("\t\t   �� 2. ��Ʊ����ϵͳ           ��\n");  
        printf("\t\t   ��                           ��\n");  
        printf("\t\t   �� 3. �ͻ�ϵͳ               ��\n");  
        printf("\t\t   ��                           ��\n");  
        printf("\t\t   �� 0. �˳�����               ��\n");  
        printf("\t\t   ����������������������������-��\n");  

 //�˵�ѡ��
	printf("\t\t\t\t\t���ڴ˴�ѡ��˵�:");
}
void smenuone()
{	
		space();
		printf("\t\t   ����������������������������-��\n");    
		printf("\t\t   ��   �ﻶӭ�������ϵͳ      ��\n");
		printf("\t\t   ��   ����ѡ�������        ��\n");
		printf("\t\t   ��1.��ӳ�����Ϣ             ��\n");
		printf("\t\t   ��2.�޸ĳ�����Ϣ             ��\n");
		printf("\t\t   ��3.ɾ��������Ϣ             ��\n");
		printf("\t\t   ��0.������һ���˵�           ��\n");
		printf("\t\t   ����������������������������-��\n");  

 //�˵�ѡ��
	printf("\t\t\t\t\t���ڴ˴�ѡ��˵�:");
}
void smenutwo()
{	
		space();
		printf("\t\t   ��������������������������������\n");    
		printf("\t\t   ��   �ﻶӭ���복Ʊϵͳ       ��\n");
		printf("\t\t   ��   ����ѡ�������         ��\n");
		printf("\t\t   ��1.��ʾ���г�����Ϣ          ��\n");
 		printf("\t\t   ��2.Ʊ��/����������Ϣ         ��\n");
		printf("\t\t   ��3.��ѯ������Ϣ              ��\n");
		printf("\t\t   ��0.������һ���˵�            ��\n");
		printf("\t\t   ��������������������������������\n");  

	printf("\t\t\t\t\t���ڴ˴�ѡ��˵�:");
}
void smenuthree()
{	
		space();
		printf("\t\t   ����������������������������-��\n");    
		printf("\t\t   ��   �ﻶӭ���붩��ϵͳ      ��\n");
		printf("\t\t   ��   ����ѡ�������        ��\n");
		printf("\t\t   ��1.�ͻ�ע��                 ��\n");		
		printf("\t\t   ��2.�ͻ���Ʊ����             ��\n");
		printf("\t\t   ��3.�ͻ���Ʊ����             ��\n");
		printf("\t\t   ��0.������һ���˵�           ��\n");
		printf("\t\t   ����������������������������-��\n");  

	//�˵�ѡ��
	printf("\t\t\t\t\t���ڴ˴�ѡ��˵�:");
}
