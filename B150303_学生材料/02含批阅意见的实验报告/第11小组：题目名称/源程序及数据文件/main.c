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
		printf("---");	//页眉设计
	for(j=1;j<10;j++)
	    printf("\n");
	n=readFile(tra);//读取文件中的车次信息条数
	if(!n)
	{
		n=createFile(tra);//创立文件存放
	}
	do
	{
		fmenu();
		scanf("%d",&choice);
		if(choice<=3&&choice>=0)
			n=runmenu(tra,choice,n);
		else 
			printf("\t\t\t\t\t错误，请检查后再一次输入！\n");
		system("cls");//清屏
		for(j=1;j<8;j++)
		{
			printf("\n");//空格控制
		}	
	}while(choice);
	saveFile(tra,n);//保存文件
	return 0;
}