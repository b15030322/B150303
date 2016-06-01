#include <string.h>
#include <stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<windows.h> 
struct Type
{
     float price;						//车票价格
	 int free;						 //剩余票数     		
};									 //车票价格
typedef struct Type type;
typedef struct train
{
	char number[10];                  //车号	
	int hour;						//出发时间
	int minute;
    int time2;						//总车程
	char start[20];					//起始站
	char end[20]; 					//终点站
	struct Type type1;             //一等座
	struct Type type2;				//二等座
}train;
#define K 100
train tra[K];
int insert(train tra[],int n,train t,int j);//插入车次信息
int createFile(train tra[]);//建立初始文件
int readFile(train tra[]);//读取文件		
void saveFile(train tra[],int n);//保存文件
void book(train tra[],int n); //订票函数
void space();//空格控制函数
int read(train tra[]);//添加函数
int add(train tra[],int n,train t);//录入函数
void modify(train tra[],int n,train t);//修改函数
int del(train tra[],int n,train t);//删除函数
void put(train tra[],int n);//显示函数
void calcurank(train tra[],int n);//车票价格和总车程排序函数
void cancle(train tra[],int n);//退票函数
int check();//管理员密码登录
void UserReg(); //用户注册函数
int Login();   //用户登录函数
void find_train(train tra[],int n);//车号查找列车
int runmenu(train tra[], int choice,int n);//一级主菜单	
int managermenu(train tra[],int n);//二级管理员菜单	
void searchmenu(train tra[],int n);//二级查询菜单
void operatemenu(train tra[],int n);//二级客户菜单
void fmenu();//一级菜单显示	
void smenuone();//二级管理员菜单显示	
void smenutwo();//二级查询菜单显示	
void smenuthree();//二级客户菜单显示	
void cover();//封面显示