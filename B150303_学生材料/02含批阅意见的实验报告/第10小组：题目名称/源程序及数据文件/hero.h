#ifndef _HERO
#define _HERO
#include <string.h>
#define NUM 20
struct Hero
{
	long num;
	char name [20];
	char skill [20];
	char character[20];
	char partner[20];
	char rival[20];
	int wins;
	int appearance;
	int rank;
	double rate;
	int kill;
	int death;
};
typedef struct Hero Hero;
#define sizeHero sizeof(Hero)
int readHero( Hero hero[],int n);
void printHero( Hero hero[],int n);                   
void calcuRank(Hero hero[],int n);                  /*根据胜率来计算英雄名次*/
int larger(Hero h1,Hero h2,int condition);    
void sortHero(Hero hero[],int n,int condition);     /*选择法从小到大排序，按condition所规定的条件*/
int searchHero(Hero hero[],int n,Hero h,int condition,int f[]) ; 
int insertHero(Hero hero[],int n,Hero h);
int deleteHero(Hero hero[],int n,Hero h);							
#endif