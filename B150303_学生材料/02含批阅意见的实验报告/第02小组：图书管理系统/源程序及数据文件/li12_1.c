#include"iostream.h"
#include"string.h"
#include"fstream.h"
#include<windows.h>
#include <iomanip.h>
#include"book.h"
#include"reader.h"
/******************************心形图形***************************/
int n=9;
void draw(int n)
{
  int i,j;
  for (i=1-(n>>1);i<=n;i++)
  if (i>=0)
   {
     for (j=0;j<i;j++) cout<<"  ";
     for (j=1;j<=2*(n-i)+1;j++) cout<<" *";
     cout<<"\n";
   }
  else
  {
     for (j=i;j<0;j++) cout<<"  ";
     for (j=1;j<=n+2*i+1;j++)  cout<<" *";
     for (j=1;j<=-1-2*i;j++) cout<<"  ";
     for (j=1;j<=n+2*i+1;j++) cout<<" *";
     cout<<"\n";
  }
}

/*************************顶层菜单函数****************************/
void menu( )        
{
    cout<<"\n\n\n\n";
    cout<<"================WELCOME================\n  ";
    cout<<"         1. 借    书  \n";
    cout<<"           2. 还    书  \n";
    cout<<"           3. 图书维护  \n";
    cout<<"           4. 读者维护  \n";
    cout<<"           0. 退出系统  \n";

}
/**************************密码***********************/
void order()/*指令操作模块*/
{
    char passwd[]="150303";/*设置密码*/
    char str[5];
    int i=0;
	
    cout<<"请输入密码（#号键结束）:\n";
	
    while( (str[i]=cin.get() ) !='#')/*逐字符读入，'#'作为结束标志*/
     {
       if(str[i]!='\n')
        { 
           cout<<"*";
           i++;
         }
     }
     str[i]='\0';/*增加字符串结束标志*/
     if(strcmp(str,passwd)==0)
     {
        cout<<"\n登陆成功！\n";
        
     }
      else
      {
         cout<<"\n密码错误,请重新输入：\n";
         order();
       }
 }
/*************************主函数*******************************/
int main()
{
    system("Color fb");
    draw(n);
    order();
    int choice=1;             
    int bookid;               //定义图书编号
    int readerid;             //定义读者编号          
    RDatabase ReaderDB;       //定义读者库类的对象
    Reader *r;                //定义读者类的对象
    BDatabase BookDB;         //定义图书库类的对象
    Book *b;                  //定义图书类的对象
    while(choice!=0)
   {
      menu( );
      cin>>choice;
      if(choice>4)  
        break; 
      switch(choice)
      {
      case 1:
          cout<<"  ★☆★☆★☆借书★☆★☆★☆"<<endl<<"            读者编号:"<<endl;
          cin>>readerid;
          cout<<"            图书编号: ";
          cin>>bookid;
          r=ReaderDB.query(readerid);
          if(r==NULL)
            {
              cout<<"            不存在该读者，不能借书"<<endl;
              break;
            }
          b=BookDB.query(bookid);
          if(b==NULL)
            {
              cout<<"            不存在该图书，不能借书"<<endl;
              break;
            }
          if (b->borrowbook()==0)
            {
              cout<<"            该图书已借出，不能借书"<<endl;
              break;
            }
          r->borrowbook(b->getno());
          break;
      case 2:
          cout<<"  ★☆★☆★☆还书★☆★☆★☆"<<endl<<"            读者编号:"<<endl;
          cin>>readerid;
          cout<<"            图书编号:";
          cin>>bookid;
          r=ReaderDB.query(readerid);
          if(r==NULL)
            {
               cout<<"            不存在该读者，不能还书"<<endl;
               break;
            }
          b=BookDB.query(bookid);
          if(b==NULL)
           {
               cout<<"            不存在该图书，不能还书"<<endl;
               break;
           }
          b->retbook();
          r->retbook(b->getno());
          break;
       case 3:
          BookDB.bookdata();
          break;
       case 4:
          ReaderDB.readerdata();
          break;
     }
   }
       

	return 0;
}