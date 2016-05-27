#include "hero.h"
#include <stdio.h>

int readHero(Hero *hero,int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		printf("Input one hero\'s information\n");
		printf("num:  ");
		scanf("%ld",&hero[i].num);
		if (hero[i].num==0) break;
		printf("name: ");
		scanf("%s",hero[i].name);
		printf("character: ");
        scanf("%s",hero[i].character);
        printf("partner: ");
        scanf("%s",hero[i].partner);
        printf("rival: ");
        scanf("%s",hero[i].rival);
        printf("wins: ");
        scanf("%ld",hero[i].wins);
        printf("appearance: ");
        scanf("%ld",hero[i].appearance);
        printf("kills: ");
        scanf("%ld",hero[i].kill);
        printf("death: ");
        scanf("%ld",hero[i].death);
		printf("rate: ");
		scanf("%ld",hero[i].rate);
        hero[i].rank=0;
	    printf("Input four skills of the hero:\n");
		for (j=0;j<4;j++)
		{
			scanf("%s",&hero[i].skill[j]);
		}
		hero[i].rank=0;
	}
		return i;
}

void printHero (Hero *hero,int n)
{
	int i,j;
	for (i=0;i<n;i++)
	{
		printf("%5ld",hero[i].num);
		printf("%8s",hero[i].name);
		for (j=0;j<4;j++)
			printf("%8s",hero[i].skill[j]);
		printf("%8s",hero[i].character);
		printf("%8s",hero[i].partner);
		printf("%8s",hero[i].rival);
		printf("%8ld",hero[i].wins);
		printf("%8ld",hero[i].appearance);
		printf("%8ld",hero[i].kill);
		printf("%8ld",hero[i].death);
		printf("%8ld",hero[i].rate);
		printf("%8ld",hero[i].rank);
	}
}
int equal(Hero h1,Hero h2,int condition)
{
	if (condition==1)
		return h1.num==h2.num;
	else if (condition==2)
	{
		if (strcmp(h1.name,h2.name)==0)
			return 1;
		else return 0;
	}
	else if (condition==3)
		return h1.rank==h2.rank;
	else if (condition==4)
		return h1.rate==h2.rate;
	else return 1;
}
int larger(Hero h1,Hero h2,int condition)
{
	if(condition==1)
		return h1.num>h2.num;
	if(condition==2)
		return h1.rate>h2.rate;
	else 
		return 1;
}
void sortHero(Hero hero[],int n,int condition)
{
	int i,j,minpos;
	Hero t;
	for(i=0;i<n-1;i++)
	{
		minpos=i;
		for(j=i+1;j<n;j++)
			if(larger(hero[minpos],hero[j],condition))
				minpos=j;
			if(i!=minpos)
			{
				t=hero[i];
				hero[i]=hero[minpos];
				hero[minpos]=t;
			}
	}
}
int searchHero(Hero hero[],int n,Hero h,int condition,int f[ ])
{
	int i,j=0,find=0;
	for(i=0;i<n;i++)
		if(equal(hero[i],h,condition))
		{
			f[j++]=i;
			find++;
		}
		return find;
}

void calcuRank(Hero hero[],int n)
{
	int i;
	sortHero(hero,n,2);
    hero[0].rank=1;
	for (i=1;i<n;i++)
	{
		if(equal(hero[i],hero[i-1],4))
			hero[i].rank=hero[i-1].rank;
		else
			hero[i].rank=i+1;
	}
}

int insertHero(Hero hero[],int n,Hero h)
 {
	 int i;
	 sortHero(hero,n,1);
	 for (i=0;i<n;i++)
	 {
		 if (equal(hero[i],h,1))
		 {
			 printf("this record exist,can not inset again!\n");
			 return n;
		 }
	 }
	 for (i=n-1;i>=0;i--)
	 {
		 if (!larger(hero[i],h,1))
			 break;
		 hero[i+1]=hero[i];
	 }
		 hero[i+1]=h;
		 n++;
		 return n;
 }

 int deleteHero(Hero hero[],int n,Hero h)
 {
	 int i,j;
	 for(i=0;i<n;i++)
		 if (equal(hero[i],h,1))  break;
		 if(i==n)
		 {
			 printf("This record does not exist!\n");
			 return n;
		 }
		 for (j=i;j<n-1;j++)
			 hero[j]=hero[j+1];
		 n--;
		 return n;
 }
