//#include<stdio.h>
//#include<stdlib.h>
typedef struct queuecli         //�Ⱥ��油�ͻ���Ϣ
{
	int flinum;                 //�����
    char name[20];            //�ͻ�����
    char id[20];              //�ͻ�ID
	int  demand;               //��������
	int  level;                //��λ�ȼ�
}QueuecliType;


struct queuecli wait[100];

typedef struct
{
	struct queuecli list[200];
	int size;
}SeqList;


struct fliinfo          //������Ϣ
{
	int city;					//Ŀ�ĵ�
	int flinum;					//�����
    char planenum[10];         //�ɻ��ͺ�
    char week[10];               //���ڼ�����
    int  maxnum;               //��Ա����
    int  overplus;             //��Ʊ��
    int  levelone;             //һ�Ȳ���λ����
    int  opone;                //һ�Ȳ���Ʊ��
    int  leveltwo;             //���Ȳ���λ����
    int  optwo;                //���Ȳ���Ʊ��
    int  levelthree;           //���Ȳ���λ����
    int  opthree;              //���Ȳ���Ʊ��
   char  starttime[7];			//���ʱ��
   char  endtime[7];			//����ʱ��

}fliinfo[26]={
{1,1,"737","MONDAY",120,120,10,10,20,20,90,90,"09:50","12:15"},
{1,2,"K320","WEDNESDAY",120,120,10,10,20,20,90,90,"15:00","17:30"},
{1,3,"737","FRIDAY",120,120,10,10,20,20,90,90,"13:25","15:55"},
{2,4,"757","TUESDAY",120,120,10,10,20,20,90,90,"10:15","11:45"},
{4,5,"737","SATURDAY",120,120,10,10,20,20,90,90,"14:45","16:00"},
{2,6,"K320","THURSDAY",120,120,10,10,20,20,90,90,"20:10","21:30"},
{3,7,"737","WEDNESDAY",120,120,10,10,20,20,90,90,"11:30","12:30"},
{3,8,"737","SUNDAY",120,120,10,10,20,20,90,90,"17:25","18:30"},
{4,9,"737","MONDAY",120,120,10,10,20,20,90,90,"10:50","12:15"},
{5,10,"K320","WEDNESDAY",120,120,10,10,20,20,90,90,"14:00","17:30"},
{6,11,"737","FRIDAY",120,120,10,10,20,20,90,90,"13:45","15:55"},
{7,12,"757","TUESDAY",120,120,10,10,20,20,90,90,"10:40","11:45"},
{8,13,"737","SATURDAY",120,120,10,10,20,20,90,90,"13:45","16:00"},
{9,14,"K320","THURSDAY",120,120,10,10,20,20,90,90,"20:00","21:30"},
{10,15,"737","WEDNESDAY",120,120,10,10,20,20,90,90,"11:30","12:50"},
{11,16,"737","FRIDAY",120,120,10,10,20,20,90,90,"13:25","15:20"},
{12,17,"757","TUESDAY",120,120,10,10,20,20,90,90,"9:15","11:45"},
{12,18,"737","SATURDAY",120,120,10,10,20,20,90,90,"13:45","16:00"},
{13,19,"K320","THURSDAY",120,120,10,10,20,20,90,90,"20:10","23:30"},
{14,20,"737","WEDNESDAY",120,120,10,10,20,20,90,90,"12:30","17:30"},
{15,21,"737","FRIDAY",120,120,10,10,20,20,90,90,"13:10","16:55"},
{16,22,"757","TUESDAY",120,120,10,10,20,20,90,90,"12:15","14:45"},
{17,23,"737","SATURDAY",120,120,10,10,20,20,90,90,"16:45","17:55"},
{18,24,"K320","THURSDAY",120,120,10,10,20,20,90,90,"22:10","24:00"},
{19,25,"737","WEDNESDAY",120,120,10,10,20,20,90,90,"11:30","12:30"},
{20,26,"737","WEDNESDAY",120,120,10,10,20,20,90,90,"14:30","16:30"},
};

typedef struct client              //��Ʊ�ͻ���Ϣ
{
	int  flinum;            //�����
    char name[20];         //�ͻ�����
	char  id[20];          //�ͻ�ID
    int  tickets;         //��Ʊ����
    int  level;            //��λ�ȼ�
}client;
struct client  cli[200];

int readcli(struct client cli[],int n)          /*���붩Ʊ*/
{
	int i;
	for (i=0;i<n;i++)
	{
		printf("Input one client\'s information\n");
		printf("flinum:  ");
	    scanf("%ld", &cli[i].flinum);
		printf("name: ");
		scanf("%s",&cli[i].name);	
		printf("id:  ");
		scanf("%s",&cli[i].id);
		printf("tickets: ");
		scanf("%d",&cli[i].tickets);	
		printf("level:  ");
		scanf("%d",&cli[i].level);
		break;
	}
	   	return i;                         /*����ʵ�ʶ���ļ�¼����*/
}

int readwait(struct queuecli wait[],int n)          /*�������Ʊ*/
{
	int i;
	for (i=0;i<n;i++)
	{
		printf("Input one client\'s information\n");
		printf("flinum:  ");
	    scanf("%ld", &wait[i].flinum);
		printf("name: ");
		scanf("%s",&wait[i].name);	
		printf("id:  ");
		scanf("%s",&wait[i].id);
		printf("tickets: ");
		scanf("%d",&wait[i].demand);	
		printf("level:  ");
		scanf("%d",&wait[i].level);
		break;
	}
	return i;                         /*����ʵ�ʶ���ļ�¼����*/
}


void ListInitiate(SeqList *L)
{
	L->size=0;
}

int ListLength(SeqList L)
{
	return L.size;
}

int ListInsert(SeqList *L,int i,struct queuecli x)
{
	int j;
	if(L->size>=200)
	{
		printf("˳��������޷����룡\n");
		return 0;
	}
	else if(i<0||i>L->size)
	{
		printf("����i���Ϸ���\n");
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


int ListDelete(SeqList *L,int i,struct queuecli *x)
{
	int j;
	if(L->size<=0)
	{
		printf("˳����������ݿ�ɾ��\n");
		return 0;

	}
	else if(i<0||i>L->size-1)
	{
		printf("����i���Ϸ���\n");
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





