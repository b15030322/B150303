
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<conio.h>
#define MaxSize 200
#include "SeqList.h"           
SeqList queueList;
//ListInitiate(&queueList);

typedef struct queuecli         //�Ⱥ��油�ͻ���Ϣ
{
	int flinum;					//�����
    char name[20];				//�ͻ�����
    char id[20];				//�ͻ�ID
	int  demand;				//��������
	int  level;					//��λ�ȼ�
}QueuecliType;

typedef QueuecliType DataType;
       
int num1=0;						//��Ʊ�ͻ�����
int num2=0;						//�Ŷӿͻ�����   

struct client					//��Ʊ�ͻ���Ϣ
{
	int  flinum;				//�����
    char name[20];			    //�ͻ�����
	char  id[20];               //�ͻ�ID
    int  tickets;               //��Ʊ����
    int  level;                 //��λ�ȼ�
};
struct client  client[1000];

void menu();
void scline();
void order();
void tuipiao();
void sccli();
void scque();
void back();
void scline();
void changescline();
void askfortime();
void tuipiao();
void changepassword();

void menu()
{
    //int p;
	char c;
    printf("\n\n                              ���ն�Ʊϵͳ�˵�          \n");
	printf("\n  ������������������������������������\n");
	printf("\n     �� 1 ��ѯ����\n");
	printf("\n     �� 2 �޸ĺ���\n");
    printf("\n     �� 3 ��ѯ��Ʊ�ͻ�����\n");
	printf("\n     �� 4 ��ѯ�Ⱥ��油�ͻ�����\n");
	printf("\n     �� 5 ��Ʊ\n");
	printf("\n     �� 6 ��Ʊ\n");
	printf("\n     �� 7 �޸�����\n");
	printf("\n     �� 8 �˳�\n");
    printf("\n  ������������������������������������\n");
	printf("\n\n��ѡ����ѡ�1-8��:[  ]\b\b\b ");
		
	switch(c=getch())
	{
	case 49: scline();break;
    case 50: changescline();break;
    case 51: sccli();break;
    case 52: scque();break;
	case 53: order();break;
	case 54: tuipiao();break;
    case 55: changepassword();break;
	case 56: back();break;
	default:printf("\n\n*****�������*****\n");system("cls");back();
	}	
}
void scline()					//��ѯ������Ϣ
{  
	int i;
	int city;
	printf("\n\n                         ���ն�Ʊϵͳ->���߲�ѯ         \n");
	printf("\n  **********************************************************************\n");
shuru:	printf("\n��ѡ���յ�վ��1���� 2�Ϻ� 3�Ͼ���:[  ]\b\b\b");
    scanf("%d",&city);
	if(city>0&&city<4)
	{   
		printf("\n��ѯ�����\n");
		printf("\n�յ�վ��");
	    switch(city)
		{
           case 1: printf("����\n\n");break;
           case 2: printf("�Ϻ�\n\n");break;
           case 3: printf("�Ͼ�\n\n");break;
		}
        printf("�����   �ɻ���     �ɻ�����	���ʱ��   ����ʱ��   ��Ʊ��\n");
		for(i=0;i<8;i++)
		{
			if(fliinfo[i].city==city)
			printf("\n  %d	  %s %13s	%s      %s       %d\n",fliinfo[i].flinum,fliinfo[i].planenum,fliinfo[i].week,fliinfo[i].starttime,fliinfo[i].endtime,fliinfo[i].overplus);
		}
	}
	else
	{
        printf("\n*****�������������ѡ��*****\n");
	    goto shuru;
    }
    back();	
}  
void changescline()                        //�޸ĺ���
{   
	int choice,line_num;
	printf("							        \n");
	printf("*	  ɾ������-------0        *\n");
	printf("*	  ���Ӻ���-------1        *\n");
	printf("��ѡ��: ");
	choice =(char) getch();
	printf("%c",choice);
	if(choice=='0')
	{   	
		printf("                   \n");
		printf("��������Ҫɾ���ĺ����: \n");
		scanf("%s",&line_num);
		printf("ɾ���ɹ�!\n");
	}
	else if(choice=='1')
	{		
		int plane_num,end_place,total;
		printf("                   \n");	
		printf("��������Ҫ���ӵĺ����: ");
		scanf("%s",&line_num);
		printf("������ɻ���: ");
		scanf("%s",&plane_num);
		printf("������Ŀ�ĵ�: ");
	    scanf("%s",&end_place);
		printf("��������λ����: ");
		scanf("%d",&total);
		printf("���ӳɹ�!\n");
	}
}

void order()						//��Ʊ����
{   
	int m,n,level,op,levelmax,p,i; //,queueList
    printf("\n\n                            ���ն�Ʊϵͳ->��Ʊ          \n");
	printf("\n  **********************************************************************\n");
shuru:	printf("�����뺽��ţ�1-8��:[  ]\b\b\b");
	scanf("%d",&m);
	if(m>0&&m<9)
	{
		printf("\n��������Ҫ��Ʊ������:[  ]\b\b\b");
	    scanf("%d",&n);
		printf("\n����������Ʊ�Ĳ�λ�ȼ���1-3��:[  ]\b\b\b");
		scanf("%d",&level);
		switch(level)
		{
		case 1:{levelmax=fliinfo[m-1].levelone;op=fliinfo[m-1].opone;}break;
        case 2:{levelmax=fliinfo[m-1].leveltwo;op=fliinfo[m-1].optwo;}break;
        case 3:{levelmax=fliinfo[m-1].levelthree;op=fliinfo[m-1].opthree;}break;  
		}
     if(n<=op)
	{   
		client[num1].flinum=m;                  //�ǼǶ�Ʊ�ͻ���Ϣ
	    client[num1].tickets=n;
	    client[num1].level=level;
		printf("\n���������������� ");
		scanf("%s",&client[num1].name);
		printf("\n�������������֤���룺 ");
		scanf("%s",&client[num1].id);
	    num1=num1+1;
		printf("\n\n��Ʊ�ɹ���\n\n");
		printf("����Ԥ��Ʊ��λ�ȼ���%d\n",level);
		printf("\n������λ�ţ� ");
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
		printf("\n*****�Բ�����Ʊ���������Ķ�Ʊ�*****\n\n");
		printf("�Ƿ�Ǽ��ŶӺ򲹣�1 ��  2 �� ��:[  ]\b\b\b");
		scanf("%d",&p);
	}
	back();
	}
	else
	{
        printf("\n*****�������������ѡ��*****\n");
	    goto shuru;
	}  
}
void tuipiao()                        	//��Ʊ����
{   
    char a[20],b[20];
    int c,p,t; //opl,i,j,
	int flag=0;              			//�鿴�Ƿ�����Ʊ�˼�¼�ı�־
	int flag2=0;             			//�鿴�Ƿ��еȺ��油�ͻ�Ԥ������Ʊ�ı�־
	//QueuecliType k;
	printf("\n                            ���ն�Ʊϵͳ->��Ʊ          \n");
	printf("\n  **********************************************************************\n");
	printf("\n���������������� ");
	scanf("%s",&a);
	printf("\n\n�������������֤���룺 ");
	scanf("%s",&b);
    printf("\n\n��������Ҫ��Ʊ�ĺ���ţ�1-8��:[  ]\b\b\b");
	scanf("%d",&c);
    printf("\n\n���Ķ�Ʊ��Ϣ��\n");
	printf("\n�����	��Ʊ��	��λ�ȼ�\n");
    for(t=0;t<num1;t++)
		if(c==client[t].flinum&&strcmp(b,client[t].id)==0)
		{
			printf("%d	%d	%d\n",c,client[t].tickets,client[t].level);
	    	flag=1;
		}
	    if(flag==0)
		{
		    printf("\n\nû�����Ķ�Ʊ��¼��\n"); 
	        back();                       
		}
		else printf("\n\n��ȷ��Ҫ��Ʊ����1�� 2��:[  ]\b\b\b");
		scanf("%d",&p);
		if(p==1)
		{
			printf("\n\n��������Ʊ�ɹ���������\n\n");
		}
		if(p==2)
		{
			printf("��ȡ����Ʊ\n");
			back();
		}
}
void changepassword()                   //�޸�����
{ 
	int re_pass_1,re_pass_2;
	char pass;                
	printf("ע��:���벻�ܳ���8λ!\n");
	printf("�����������룺");
	scanf("%s",&re_pass_1);
	printf("��������һ��: ");
	scanf("%s",&re_pass_2);
	if(re_pass_1==re_pass_2)
	{
    	pass=re_pass_1;
		printf("�����޸ĳɹ�!���ס.\n");
	}
	else 
	{
		printf("��������������벻һ��!\n");
	}
}
void sccli()                            //��ѯ��Ʊ�ͻ�����
{      
	int p,i;
    int flag=0;
	printf("\n\n\n                     ���ն�Ʊϵͳ->��ѯ��Ʊ�ͻ�����          \n");
	printf("\n  **********************************************************************\n");
    printf("\n������Ҫ��ѯ�ĺ���ţ�1-8��:[  ]\b\b\b");
    scanf("%d",&p);
    if(p>0&&p<9)
	{
		printf("\n\n����ţ�%d\n\n",p);
	    printf("��Ʊ�ͻ�������\n");
		printf("\n����		��Ʊ��		��λ�ȼ�\n");
		for(i=0;i<num1;i++)
			if(p==client[i].flinum)
			{
				printf("%s		%d		%d\n",client[i].name,client[i].tickets,client[i].level);
	        	flag=1;
			}
			if(flag==0)
				printf("\n*****�޼�¼��*****\n");
	}
	else printf("\n\n*****���뺽��Ŵ���*****\n\n");
	back();     
}
void scque()                           //��ѯ�Ⱥ��油�ͻ�����
{
	int p,i;
	int flag=0;
	printf("\n\n\n                      ���ն�Ʊϵͳ->��ѯ�Ŷӿͻ�����          \n");
  	printf("\n  **********************************************************************\n");
	printf("\n\n������Ҫ��ѯ�ĺ���ţ�1-8��:[  ]\b\b\b");
    scanf("%d",&p);
    if(p>0&&p<9)
	{
		printf("\n\n����ţ�%d\n\n",p);
	    printf("�Ⱥ��油�ͻ�������\n");
		printf("\n����		������		��λ�ȼ�\n");
		for(i=0;i<num2;i++)
			if(p==queueList.list[i].flinum)
			{
				printf("%s		%d		%d\n",queueList.list[i].name,queueList.list[i].demand,queueList.list[i].level);
			    flag=1;
			}
			if(flag==0)
			printf("\n*****�޼�¼��*****\n");
	} 
	else printf("\n\n*****���뺽��Ŵ���*****\n\n");
	back();
}
void back()
{
	printf("\n\n��������������������ز˵�ҳ��������������\n");
    getch();
	system("cls");
	menu();
}
void main()
{
	printf("\n                            ��ӭ���뺽�ն�Ʊϵͳ�� \n");
    menu();
}
