#include <string.h>
#include <stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<windows.h> 
struct Type
{
     float price;						//��Ʊ�۸�
	 int free;						 //ʣ��Ʊ��     		
};									 //��Ʊ�۸�
typedef struct Type type;
typedef struct train
{
	char number[10];                  //����	
	int hour;						//����ʱ��
	int minute;
    int time2;						//�ܳ���
	char start[20];					//��ʼվ
	char end[20]; 					//�յ�վ
	struct Type type1;             //һ����
	struct Type type2;				//������
}train;
#define K 100
train tra[K];
int insert(train tra[],int n,train t,int j);//���복����Ϣ
int createFile(train tra[]);//������ʼ�ļ�
int readFile(train tra[]);//��ȡ�ļ�		
void saveFile(train tra[],int n);//�����ļ�
void book(train tra[],int n); //��Ʊ����
void space();//�ո���ƺ���
int read(train tra[]);//��Ӻ���
int add(train tra[],int n,train t);//¼�뺯��
void modify(train tra[],int n,train t);//�޸ĺ���
int del(train tra[],int n,train t);//ɾ������
void put(train tra[],int n);//��ʾ����
void calcurank(train tra[],int n);//��Ʊ�۸���ܳ���������
void cancle(train tra[],int n);//��Ʊ����
int check();//����Ա�����¼
void UserReg(); //�û�ע�ắ��
int Login();   //�û���¼����
void find_train(train tra[],int n);//���Ų����г�
int runmenu(train tra[], int choice,int n);//һ�����˵�	
int managermenu(train tra[],int n);//��������Ա�˵�	
void searchmenu(train tra[],int n);//������ѯ�˵�
void operatemenu(train tra[],int n);//�����ͻ��˵�
void fmenu();//һ���˵���ʾ	
void smenuone();//��������Ա�˵���ʾ	
void smenutwo();//������ѯ�˵���ʾ	
void smenuthree();//�����ͻ��˵���ʾ	
void cover();//������ʾ