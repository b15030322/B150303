#include"iostream.h"
#include"string.h"
#include"fstream.h"
#include<windows.h>
#include <iomanip.h>
#include"book.h"
#include"reader.h"

/*****************************����ͼ��***************************/
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

/*********************����˵�����****************************/
void menu( )        
{
	cout<<"\n\n\n\n";
cout << "\t********************��ӭʹ��ͼ�����ϵͳ********************" << endl;
		cout << "\t  --------------------------------------------------------  " << endl;
		cout << "\t |                 ��(1)     ��  ��    ��                 |" << endl;
		cout << "\t |                 ��(2)     ��  ��    ��                 |" << endl;
		cout << "\t |                 ��(3)    ͼ��ά��   ��                 |" << endl;
		cout << "\t |                 ��(4)    ����ά��   ��                 |" << endl;
		cout << "\t |                 ��(0)    �˳�ϵͳ   ��                 |" << endl;
		cout << "\t  --------------------------------------------------------  " << endl;
	

		cout << "\t******************��ѡ�����ּ�ѡ����Ӧ�ķ���****************" << endl;
	/*	cout<<"================WELCOME================\n  ";
	
    	cout<<"         1. ��    ��  \n";
		cout<<"           2. ��    ��  \n";
		cout<<"           3. ͼ��ά��  \n";
        cout<<"           4. ����ά��  \n";
		cout<<"           0. �˳�ϵͳ  \n";*/

}
/**************************����***********************/
void order()/*ָ�����ģ��*/
{
    char passwd[]="B150303";/*��������*/
    char str[7];
    int i=0;
	
    cout<<"���������루#�ż�������:\n";
	
    while( (str[i]=cin.get() ) !='#')/*���ַ����룬'#'��Ϊ������־*/
    {
       if(str[i]!='\n')
        { 
           cout<<"*";
           i++;
         }
     }
     str[i]='\0';/*�����ַ���������־*/
     if(strcmp(str,passwd)==0)
     {
        cout<<"\n��½�ɹ���\n";
        
      }
      else
      {
         cout<<"\n�������,���������룺\n";
         order();
       }
 }
/*************************������*******************************/
int main()
{
    
	system("Color f0");
      draw(n);
   order();
	system ("cls");
		cout << endl ;
		cout << " \t     *   * ";cout << " ***** ";cout << " *     ";cout << " ***** ";cout << " ***** ";cout << " *   * ";cout << " ***** ";cout << "   *       "<<endl;
        cout << " \t     * * * ";cout << " *     ";cout << " *     ";cout << " *     ";cout << " *   * ";cout << " ** ** ";cout << " *     ";cout << "   *       "<<endl;
        cout << " \t     * * * ";cout << " ***** ";cout << " *     ";cout << " *     ";cout << " *   * ";cout << " * * * ";cout << " ***** ";cout << "   *       "<<endl;
        cout << " \t     ** ** ";cout << " *     ";cout << " *     ";cout << " *     ";cout << " *   * ";cout << " *   * ";cout << " *     ";cout << "           "<<endl;
        cout << " \t     *   * ";cout << " ***** ";cout << " ***** ";cout << " ***** ";cout << " ***** ";cout << " *   * ";cout << " ***** ";cout << "   *       "<<endl;
        cout<<endl;
  int choice=1;             
          int bookid;               //����ͼ����
          int readerid;             //������߱��          
          RDatabase ReaderDB;       //������߿���Ķ���
          Reader *r;                //���������Ķ���
          BDatabase BookDB;         //����ͼ�����Ķ���
          Book *b;                  //����ͼ����Ķ���
          while(choice!=0)
          {
			  
                menu( );

    cin>>choice;
	    if(choice>4)  
                  break; 
	    switch(choice)
            {
               case 1:
                       cout<<"\t\t\t����������������"<<endl<<"\t\t\t\t���߱��:"<<endl;
                       cin>>readerid;
                       cout<<"\t\t\t\tͼ����: ";
                       cin>>bookid;
                       r=ReaderDB.query(readerid);
                       if(r==NULL)
                       {
                            cout<<"\t\t\t\t�����ڸö��ߣ����ܽ���"<<endl;
                            break;
                       }
                       b=BookDB.query(bookid);
                       if(b==NULL)
                       {
                             cout<<"\t\t\t\t�����ڸ�ͼ�飬���ܽ���"<<endl;
                             break;
                       }
                       if (b->borrowbook()==0)
                       {
                          cout<<"\t\t\t\t��ͼ���ѽ�������ܽ���"<<endl;
                          break;
                       }
                       r->borrowbook(b->getno());
                       break;
                case 2:
                       cout<<"\t\t\t��������������"<<endl<<"\t\t\t\t���߱��:"<<endl;
                       cin>>readerid;
                       cout<<"\t\t\t\tͼ����:";
                       cin>>bookid;
                       r=ReaderDB.query(readerid);
                       if(r==NULL)
                       {
                            cout<<"\t\t\t\t�����ڸö��ߣ����ܻ���"<<endl;
                            break;
                       }
                       b=BookDB.query(bookid);
                       if(b==NULL)
                       {
                             cout<<"\t\t\t\t�����ڸ�ͼ�飬���ܻ���"<<endl;
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