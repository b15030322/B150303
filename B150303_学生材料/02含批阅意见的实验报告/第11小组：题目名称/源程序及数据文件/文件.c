#include "train.h"
#include <stdlib.h>
#include <windows.h>
#include <stdio.h>
int createFile(train tra[])
{
	FILE *fp;
	int n;
	if((fp=fopen("D:\\�����ϻ�\\C�����ļ�\\train.dat","wb"))==NULL)
	{
		printf("can not open file!\n");
		exit(0);
	}
	n=read(tra);
	fwrite(tra,sizeof(train),n,fp);
	fclose(fp);
	return n;
}

//-----------��ȡ�ļ�------------//
int readFile(train tra[ ])                     /*���ļ��е����ݶ������ڽṹ������tra��*/
{
   	FILE *fp;
	int i=0;
	if((fp=fopen("D:\\�����ϻ�\\C�����ļ�\\train.dat", "rb")) == NULL)  /*�Զ��ķ�ʽ��ָ���ļ�*/
	{
	    printf("�ļ��򲻿�\n");  /*�����ʧ�������ʾ��Ϣ*/
	    return 0;                              /*Ȼ�󷵻�0*/
	}
    fread(&tra[i],sizeof(train),1,fp);                   /*������һ����¼*/
   	while(!feof(fp))                            /*�ļ�δ����ʱѭ��*/
	{
		i++;
	    fread(&tra[i],sizeof(train),1,fp);              /*�ٶ�����һ����¼*/
     }
	fclose(fp);                                /*�ر��ļ�*/
	return i;                                  /*���ؼ�¼����*/
}
//--------------�����ļ�-------------//
void saveFile(train tra[],int n)                  /*���ṹ�����������д���ļ�*/
{	
  	FILE *fp;
   	if((fp=fopen("D:\\�����ϻ�\\C�����ļ�\\train.dat", "wb")) == NULL) /*��д�ķ�ʽ��ָ���ļ�*/
	{
		printf("can not open file !\n");           /*�����ʧ�ܣ������ʾ��Ϣ*/
		exit(0);									 /*Ȼ���˳�*/
	}

	fwrite(tra,sizeof(train),n,fp);
	fclose(fp);                              /*�ر��ļ�*/
}
