#include <stdio.h>
#include <stdlib.h>
int  createFile(struct client cli[])              /*������ʼ�������ļ�*/
{
	FILE *fp;
	int n;
   	if((fp=fopen("d:\\client.txt", "w")) == NULL) /*ָ�����ļ�������д�뷽ʽ��*/
	{
	    printf("can not open file !\n");         /*����ʧ�ܣ������ʾ��Ϣ*/
	    exit(0);                           /*Ȼ���˳�*/
    }
	printf("input clients\' information:\n");
	n=readcli(cli,26);                /*����SeqList.h�еĺ���������*/
	fwrite(cli,sizeof(cli),1000,fp);                  /*���ղŶ�������м�¼һ����д���ļ�*/
 	fclose(fp);                             /*�ر��ļ�*/
	return n;
}

int  createFilewait(struct queuecli DataType[ ])              /*������ʼ�������ļ�*/
{
	FILE *fp;
	int n;
   	if((fp=fopen("d:\\DataType.txt", "w")) == NULL) /*ָ�����ļ�������д�뷽ʽ��*/
	{
	    printf("can not open file !\n");         /*����ʧ�ܣ������ʾ��Ϣ*/
	    exit(0);                           /*Ȼ���˳�*/
    	}
	printf("input waitpassengers\' information:\n");
	n=readwait(wait,100);                /*����SeqList.h�еĺ���������*/
	fwrite(wait,sizeof(struct queuecli),100,fp);                  /*���ղŶ�������м�¼һ����д���ļ�*/
 	fclose(fp);                             /*�ر��ļ�*/
	return n;
}

void saveFileCli( struct client cli[],int n)                  /*���ṹ�����������д���ļ�*/
{   			
  	FILE *fp;	
   	if((fp=fopen("d:\\client.txt", "a+")) == NULL) /*��д�ķ�ʽ��ָ���ļ�*/
	{
		printf("can not open file !\n");           /*�����ʧ�ܣ������ʾ��Ϣ*/
		exit(0);                            /*Ȼ���˳�*/
	}
	fwrite(cli,sizeof(struct client),n,fp);        
	fclose(fp);                              /*�ر��ļ�*/
}

void changeFile(struct client cli[],int n)                  /*���ṹ�����������д���ļ�*/
{   			
  	FILE *fp;	
   	if((fp=fopen("d:\\client.txt", "a+")) == NULL) /*�Զ�д�ķ�ʽ��ָ���ļ�*/
	{
		printf("can not open file !\n");           /*�����ʧ�ܣ������ʾ��Ϣ*/
		exit(0);                            /*Ȼ���˳�*/
	}
	fwrite(cli,sizeof(struct client),n,fp);        
	fclose(fp);                              /*�ر��ļ�*/
}


void saveFileWait(struct queuecli wait[],int n)                  /*���ṹ�����������д���ļ�*/
{   			
  	FILE *fp;	
   	if((fp=fopen("d:\\DataType.txt", "a+")) == NULL) /*��д�ķ�ʽ��ָ���ļ�*/
	{
		printf("can not open file !\n");           /*�����ʧ�ܣ������ʾ��Ϣ*/
		exit(0);                            /*Ȼ���˳�*/
	}	
	fwrite(wait,sizeof(struct queuecli),n,fp);        
	fclose(fp);                              /*�ر��ļ�*/
}


void readtxt1()//����
{
	FILE *fp;
	char ch;
	fp=fopen("d:\\city.txt","r");
	if(fp==0)
	{
		printf("file error\n");
		exit(1);
	}
	while ((ch=fgetc(fp))!=EOF)
	{
		putchar(ch);
	}
	putchar('\n');
	fclose(fp);
}

void readtxt2()//����
{
	FILE *fp;
	char ch;
	fp=fopen("d:\\client.txt","r+");//�˿�
	if(fp==0)
	{
		printf("file error\n");
		exit(1);
	}
	while ((ch=fgetc(fp))!=EOF)
	{
		putchar(ch);
	}
	putchar('\n');
	fclose(fp);
}

void readtxt3()//����
{
	FILE *fp;
	char ch;
	fp=fopen("d:\\DataType.txt","r+");//��
	if(fp==0)
	{
		printf("file error\n");
		exit(1);
	}
	while ((ch=fgetc(fp))!=EOF)
	{
		putchar(ch);
	}
	putchar('\n');
	fclose(fp);
}