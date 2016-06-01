#include"iostream.h"
#include"string.h"
#include"fstream.h"
#include<windows.h>
#include <iomanip.h>
/***********************���峣����*****************************/
 
      const int Maxr=100;     //���Ķ�����
      const int Marb=100;     //����ͼ����
      const int Maxbor=5;     //ÿλ��������5����

/**************************����ͼ����*****************************************/

       class Book         //ͼ����
       {
         private:
              int tag;             //ɾ�����  1����ɾ   0��δɾ 
              int no;              //ͼ����
              char name[20];  //����
			  char publish[20];  //������
              int onshelf;    //�Ƿ��ڼ�   1���ڼ�  0���ѽ�  
         public:
              Book(){};
              char *getname()            //��ȡ����
                 {return name;}
              int getno()                 //��ȡͼ����
                 {return no;}
              int gettag()                 //��ȡɾ�����
                 {return tag;}
              void setname(char na[])       //��������
              {
                 strcpy(name,na);
              }
			 void setpublish(char pu[])
			 {
				 strcpy(publish,pu);
			 }

              void delbook()                 //ɾ��ͼ��
                  {tag=1;}
              void addbook(int n,char *na,char *pu)     //����ͼ��
              {
                   tag=0;
                   no=n;     
                   strcpy(name,na);
				   strcpy(publish,pu);
                   onshelf=1;
              }
              int borrowbook()        //�������
              {
                  if(onshelf==1)
                  {
                      onshelf=0;     
                      return 1;
                  }
                  return 0;
              }
              void retbook()             //�������
              {
                 onshelf=1;
              }
              void disp()
              {
                cout<<setw(10)<<no<<setw(20)<<name<<setw(20)<<publish<<setw(15)<<(onshelf==1?"�ڼ�":"�ѽ�")<<endl;
              }
       };
/***********************************************************************/
  //����ͼ�����
       class BDatabase 
       {
        private:
          int top;                  //ͼ���¼ָ��
          Book book[Marb];          //ͼ���¼
        public:
          BDatabase()               //���캯������book.txt����book[]��
          {
             Book b;                //����ͼ����Ķ���
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
          void clear()             //ȫɾ
          {
               top=-1;
          }
          int addbook(int n,char *na ,char *pu            )          //����ͼ��
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
          Book *query(int bookid)                 //����ͼ��
          {
             for(int i=0;i<=top;i++)
               if(book[i].getno()==bookid&&book[i].gettag()==0)
                  return &book[i];
             return NULL;
          }
          void bookdata();                     //ͼ���ά��
          void disp()
          {
             for (int i=0;i<=top;i++)
                if(book[i].gettag()==0)
                  book[i].disp();
          }
          ~BDatabase()            //������������book[]д��book.txt�ļ���
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
               cout<<"\t\t\t�������ͼ��ά���������"<<endl<<"\t\t\t\t1������"<<endl<<"\t\t\t\t2������"<<endl<<"\t\t\t\t3��ɾ��"<<endl<<"\t\t\t\t4������"<<endl<<"\t\t\t\t5����ʾ"<<endl<<"\t\t\t\t6��ȫɾ"<<endl<<"\t\t\t\t0���˳�=��"<<endl;
               cin>>choice;
               switch(choice)
               {
                case 1:
                         cout<<"\t\t\t\t����ͼ����:";
                         cin>>bookid;
                         cout<<"\t\t\t\t����ͼ������:";
                         cin>>bname;
						 cout<<"\t\t\t\t���������:";
						 cin>>bpub;
                         addbook(bookid,bname,bpub);
						 
                         break;
                 case 2:
                         cout<<"\t\t\t\t����ͼ����:";
                         cin>>bookid;
                         b=query(bookid);
                         if (b==NULL)
                         {
                              cout<<"\t\t\t\t��ͼ�鲻����"<<endl;
                              break;
                         }
                         cout<<"\t\t\t\t�����µ�����:";
                         cin>>bname;
                         b->setname(bname);
                         break;
                 case 3:
                         cout<<"\t\t\t\t����ͼ����:";
                         cin>>bookid;
                         b=query(bookid);
                         if(b==NULL)
                         {
                            cout<<"\t\t\t\t��ͼ�鲻����"<<endl;
                            break;
                         }
                         b->delbook();
                         break;
                 case 4:
                         cout<<"\t\t\t\t����ͼ����:";
                         cin>>bookid;
                         b=query(bookid);
                         if (b==NULL)
                         {
                            cout<<"\t\t\t\t��ͼ�鲻����"<<endl;
                            break;
                         }
						 else
						 {
                         cout<<"       ���            ����             ������            �Ƿ��ڼ�"<<endl;
                         b->disp();
						 }
                         break;
                 case 5:
					      cout<<"        ���            ����              ������            �Ƿ��ڼ�"<<endl;
                         disp();
                         break;
                 case 6:
                         clear();
                         break;
               }
             }
       }