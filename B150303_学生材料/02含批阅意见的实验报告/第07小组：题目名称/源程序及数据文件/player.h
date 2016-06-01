#ifndef _PLAYER             /*条件编译，防止重复包含的错误*/
#define _PLAYER
#include <string.h>
#define NUM 20                /*定义球员人数常量，此处可以根据实际需要修改常量值*/
struct Player                   /*球员记录的数据域*/
{
		long num;
		char name[20];
		char pos[10];
		char team[20];
        int height;
		int weight;		
		int ascore;
        int rebound;
        int assist;
		int steal;
		int appearance;
		int total;
		int rank;
		int score[3];
};
typedef struct Player Player;
#define sizePla sizeof(Player)      /*一个球员记录所需要的内存空间大小*/
int readPla(Player pla[],int n);       /*读入球员记录值，编号为0或读满规定条数记录时停止*/
void printPla(Player  *pla , int n);   /*输出所有球员记录的值*/
int equal(Player p1,Player p2,int condition);  /*根据condition条件判断两个Player类型数据相等否*/
int larger(Player p1,Player p2,int condition);  /*根据condition比较Student类型数据大小*/
void reverse(Player pla[],int n);             /*球员记录数组元素逆置*/

void calcuTotal(Player pla[],int n);           /*计算所有球员的总分*/
void calcuRank(Player pla[],int n);           /*根据总分计算球员的名次，允许有并列名次*/
void calcuMark(double m[2][2],Player pla[],int n); /*求场均得分、篮板、助攻的最高、最低，m数组第一维*/
/*表示哪门课，第二维表示最高、最低*/

void sortPla(Player pla[],int n,int condition);   /*选择法从小到大排序，按condition所规定的条件*/

int searchPla(Player pla[],int n,Player p,int condition,int f[]) ;  /*根据条件找数组中与s相等的各元素*/
/*下标置于f数组中，设f数组是因为查找结果可能不止一条记录*/
int insertPla(Player pla[],int n,Player p);                   /*向数组中插入一个元素按学号有序*/
int deletePla(Player pla[],int n,Player p);                   /*从数组中删除一个指定学号的元素*/
#endif