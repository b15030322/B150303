#include<stdio.h>
#include<stdlib.h>
#include"hero.h"
int createFile(Hero hero[])
{
	FILE *fp;
	int n;
	if((fp=fopen("d:\\hero.dat", "wb")) == NULL)
	{
		printf("can not open file !\n");
		exit(0);
	}
	printf("input heros\' information:\n");
	n=readHero(hero,NUM);
	fwrite(hero,sizeHero,n,fp);
	fclose(fp);
	return n;
}

int readFile(Hero hero[] ) 
{
	FILE *fp;
	int i=0;
	if((fp=fopen("d:\\hero.dat", "rb")) == NULL)
	{
		printf("file does not exist,create it first:\n");
		return 0;
	}
	fread(&hero[i],sizeHero,1,fp);
	while(!feof(fp))
	{
		i++;
		fread(&hero[i],sizeHero,1,fp);
	}
	fclose(fp);
	return i;
}

void saveFile(Hero hero[],int n)
{
	FILE *fp;
	if((fp=fopen("d:\\hero.dat","wb"))==NULL)
	{
		printf("can not open file !\n");
		exit(0);
	}
	fwrite(hero,sizeHero,n,fp);
	fclose(fp);
}
