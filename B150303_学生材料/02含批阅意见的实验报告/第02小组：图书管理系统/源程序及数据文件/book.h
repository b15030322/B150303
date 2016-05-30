#include"iostream.h"
#include"string.h"
#include"fstream.h"
#include<windows.h>
//#include<stdlib.h>
#include <iomanip.h>
/**************************定义常数据*****************************************/
const int Maxr=100;                          //最多的读者
const int Marb=100;                          //最多的图书数
const int Maxbor=5;                          //每位读者最多借5本书
/**************************定义图书类*****************************************/
class Book                                   //图书类
{
private:
    int tag;                                 //删除标记  1：已删   0：未删 
    int no;                                  //图书编号
    char name[20];                           //书名
    char publish[20];                        //出版社
    int onshelf;                             //是否在架   1：在架  0：已借  
public:
     Book(){};
     char *getname()                        //获取姓名
       {return name;}
     int getno()                            //获取图书编号
       {return no;}
     int gettag()                           //获取删除标记
       {return tag;}             
     void setname(char na[])                //设置书名
       {strcpy(name,na)
     void setpublish(char)
       {strcpy(publish,pu);}
     void delbook()                          //删除图书
       {tag=1;}
     void addbook(int n,char *na,char *pu)   //增加图书
     {
           tag=0;
           no=n;     
           strcpy(name,na);
	   strcpy(publish,pu);
           onshelf=1;
      }
      int borrowbook()                     //借书操作
      {
          if(onshelf==1)
          {
              onshelf=0;     
              return 1;
           }
           return 0;
       }
       void retbook()                      //还书操作
       {
          onshelf=1;
       }
       void disp()
       {
           cout<<"\t\t"<<no<<"\t\t"<<name<<"\t\t"<<publish<<"\t\t"<<(onshelf==1?"在架":"已借")<<endl;
       }
};
/****************************定义图书库类*******************************************/
class BDatabase 
{
private:
    int top;                           //图书记录指针
    Book book[Marb];                   //图书记录
public:
    BDatabase()                        //构造函数，将book.txt读到book[]中
    {
        Book b;                        //建立图书类的对象
        top=-1;
        fstream file("book.txt",ios::in);
        while(1)
        {
             file.read((char *)&b,sizeof(b));
             if(!file)
             break;
             top++;
             book[top]=b;
        }
        file.close();
     }
    void clear()                        //全删
    {
        top=-1;
    }
    int addbook(int n,char *na ,char *pu) //增加图书
    {
        Book *p=query(n);
        if(p==NULL)
        {
            top++;
            book[top].addbook(n,na,pu);
            return 1;
         }
         return 0;
    }
    Book *query(int bookid)                 //查找图书
    {
        for(int i=0;i<=top;i++)
        if(book[i].getno()==bookid&&book[i].gettag()==0)
        return &book[i];
        return NULL;
     }
     void bookdata();                     //图书库维护
     void disp()
     {
         for (int i=0;i<=top;i++)
         if(book[i].gettag()==0)
         book[i].disp();
      }
      ~BDatabase()                       //析构函数，将book[]写入book.txt文件中
     {
         fstream file("book.txt",ios::out);
         for(int i=0;i<=top;i++)
         if(book[i].gettag()==0)
         file.write((char *)&book[i],sizeof(book[i]));
         file.close();
      }
};
void BDatabase::bookdata()
{
      int choice=1;
      char bname[40];
      int bookid;
      char bpub[40];
      Book *b;
      while (choice!=0)
      {
          cout<<"  ★☆★☆★☆图书维护★☆★☆★☆"<<endl<<"            1：新增"<<endl<<"            2：更改"<<endl<<"            3：删除"<<endl<<"            4：查找"<<endl<<"            5：显示"<<endl<<"            6：全删"<<endl<<"            0：退出=〉"<<endl;
          cin>>choice;
          switch(choice)
          {
          case 1:
               cout<<"            输入图书编号:";
               cin>>bookid;
               cout<<"            输入图书书名:";
               cin>>bname;
	       cout<<"            输入出版社:";
	       cin>>bpub;
               addbook(bookid,bname,bpub);			 
               break;
          case 2:
               cout<<"            输入图书编号:";
               cin>>bookid;
               b=query(bookid);
               if (b==NULL)
               {
                 cout<<"            该图书不存在"<<endl;
                 break;
               }
               cout<<"            输入新的书名:";
               cin>>bname;
               b->setname(bname);
               break;
          case 3:
               cout<<"            输入图书编号:";
               cin>>bookid;
               b=query(bookid);
               if(b==NULL)
               {
                    cout<<"            该图书不存在"<<endl;
                    break;
                }
                b->delbook();
                break;
          case 4:
                cout<<"            输入图书编号:";
                cin>>bookid;
                b=query(bookid);
                if (b==NULL)
                {
                     cout<<"            该图书不存在"<<endl;
                     break;
                }
		else
	        {
                     cout<<"               编号            书名           出版社            是否在架"<<endl;
                     b->disp();
	        }
                break;
          case 5:
		cout<<"               编号            书名           出版社            是否在架"<<endl;
                disp();
                break;
         case 6:
                clear();
                break;
         }
      }
   }