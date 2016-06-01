#include "train.h"
#include <stdlib.h>
#include <windows.h>
#include <stdio.h>
int createFile(train tra[])
{
	FILE *fp;
	int n;
	if((fp=fopen("D:\\程序上机\\C语言文件\\train.dat","wb"))==NULL)
	{
		printf("can not open file!\n");
		exit(0);
	}
	n=read(tra);
	fwrite(tra,sizeof(train),n,fp);
	fclose(fp);
	return n;
}

//-----------读取文件------------//
int readFile(train tra[ ])                     /*将文件中的内容读出置于结构体数组tra中*/
{
   	FILE *fp;
	int i=0;
	if((fp=fopen("D:\\程序上机\\C语言文件\\train.dat", "rb")) == NULL)  /*以读的方式打开指定文件*/
	{
	    printf("文件打不开\n");  /*如果打开失败输出提示信息*/
	    return 0;                              /*然后返回0*/
	}
    fread(&tra[i],sizeof(train),1,fp);                   /*读出第一条记录*/
   	while(!feof(fp))                            /*文件未结束时循环*/
	{
		i++;
	    fread(&tra[i],sizeof(train),1,fp);              /*再读出下一条记录*/
     }
	fclose(fp);                                /*关闭文件*/
	return i;                                  /*返回记录条数*/
}
//--------------保存文件-------------//
void saveFile(train tra[],int n)                  /*将结构体数组的内容写入文件*/
{	
  	FILE *fp;
   	if((fp=fopen("D:\\程序上机\\C语言文件\\train.dat", "wb")) == NULL) /*以写的方式打开指定文件*/
	{
		printf("can not open file !\n");           /*如果打开失败，输出提示信息*/
		exit(0);									 /*然后退出*/
	}

	fwrite(tra,sizeof(train),n,fp);
	fclose(fp);                              /*关闭文件*/
}
