/* ①student.h文件的完整内容 */
#ifndef _STUDENT             /*条件编译，防止重复包含的错误*/
#define _STUDENT
#include <string.h>
#define NUM 20                /*定义图书数量常量，此处可以根据实际需要修改常量值*/
struct Book                   /*图书记录的数据域*/
{
	long num;											//编号
	char title[20];										//书名
	char author[10];									//作者
	char company[10];									//出版社
	int price;											//价格
	int a;												//搜索量
	int b;												//借阅量
};
typedef struct Book Book;
#define sizeBoo sizeof(Book)      /*一个图书记录所需要的内存空间大小*/
int readBoo(Book boo[],int n);       /*读入图书记录值，编号为0或读满规定条数记录时停止*/
void printBoo(Book  *boo , int n);   /*输出所有图书记录的值*/

int equal(Book b1,Book b2,int condition);  /*根据condition条件判断两个Book类型数据相等否*/
int larger(Book b1,Book b2,int condition);  /*根据condition比较Book类型数据大小*/
void reverse(Book b[],int n);             /*图书记录数组元素逆置*/

void calcuTotal(Book boo[],int n);           /*计算所有图书的总数据*/   
void calcuMark(double m[2][2],Book boo[],int n); /*求两数据的最高、最低、平均，m数组第一维*/
/*表示哪项数据，第二维表示最高、最低、平均*/

void sortBoo(Book boo[],int n,int condition);   /*选择法从小到大排序，按condition所规定的条件*/

int searchBoo(Boo boo[],int n,Book b,int condition,int f[]) ;  /*根据条件找数组中与s相等的各元素*/
/*下标置于f数组中，设f数组是因为查找结果可能不止一条记录*/
int insertBoo(Book boo[],int n,Book b);                   /*向数组中插入一个元素按学号有序*/
int deleteBoo(Book boo[],int n,Bool s);                   /*从数组中删除一个指定学号的元素*/
#endif
