/* ①criminal.h文件的完整内容 */
#ifndef _CRIMINAL             /*条件编译，防止重复包含的错误*/
#define _CRIMINAL 
#include <string.h>
#define NUM 20                /*定义服刑人员人数常量，此处可以根据实际需要修改常量值*/
struct Criminal {
	long num;													//狱号
	char name[20];												//姓名
	char sex[10];													//性别
	int year;
int month;
int day;														//入狱时间
int total;														//总出勤次数
};
typedef struct Criminal Criminal;

#define sizeCri sizeof(Criminal)      /*一个服刑人员基本信息记录所需要的内存空间大小*/

int readCri(Criminal cri[],int n);       /*读入服刑人员基本信息记录值，狱号为0或读满规定条数记录时停止*/

void printCri(Criminal  *Cri , int n);   /*输出所有服刑人员记录的值*/

int equal(Criminal s1,Criminal s2,int condition);  /*根据condition条件判断两个Criminal类型数据相等否*/
int larger(Criminal s1,Criminal s2,int condition);  /*根据condition比较Criminal类型数据大小*/
void reverse(Criminal cri[],int n);             /*服刑人员记录数组元素逆置*/

void calcuTotal(Criminal cri[],int n);           /*根据出勤内容计算所有Criminal总出勤情况的次数*/

/*void calcuRank(Criminal cri[],int n);           根据总分计算学生的名次，允许有并列名次
void calcuMark(double m[3][3],Criminal cri[],int n); /*求三门课的最高、最低、平均分，m数组第一维
/*表示哪门课，第二维表示最高、最低、平均分*/

void sortCri(Criminal cri[],int n,int condition);   /*选择法从小到大排序，按condition所规定的条件*/

int searchCri(Criminal cri[],int n,Criminal s,int condition,int f[]);  /*根据条件找数组中与s相等的各元素*/
/*下标置于f数组中，设f数组是因为查找结果可能不止一条记录*/
int insertCri(Criminal cri[],int n,Criminal s);                   /*向数组中插入一个元素按狱号有序*/
int deleteCri(Criminal cri[],int n,Criminal s);                   /*从数组中删除一个指定狱号的元素*/
#endif
