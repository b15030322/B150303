#include "train.h"
#include <stdlib.h>
#include <windows.h>
#include <stdio.h>
int main()
{	
	train tra[K];
	int i,j,choice,n;
	system("color 3e");
	cover();	
	for(i=1;i<40;i++)
		printf("***");
	printf("\n");
	for(i=1;i<40;i++)
		printf("---");	//ҳü���
	for(j=1;j<10;j++)
	    printf("\n");
	n=readFile(tra);//��ȡ�ļ��еĳ�����Ϣ����
	if(!n)
	{
		n=createFile(tra);//�����ļ����
	}
	do
	{
		fmenu();
		scanf("%d",&choice);
		if(choice<=3&&choice>=0)
			n=runmenu(tra,choice,n);
		else 
			printf("\t\t\t\t\t�����������һ�����룡\n");
		system("cls");//����
		for(j=1;j<8;j++)
		{
			printf("\n");//�ո����
		}	
	}while(choice);
	saveFile(tra,n);//�����ļ�
	return 0;
}