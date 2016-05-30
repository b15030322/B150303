#include <stdio.h>
#include <string.h>
#include<conio.h>
void main()
{
	char password[7];
	int i,n;
	for(i=0;i<7;i++)
	{	n=i;
		password[i]=getch();
		if(password[i]=='\b')
		{	
			i=i-2;
		    printf("\b");
			printf(" ");
		}
		if(n==i)
		{
			printf("*");
		}
		else 
		{
			printf("\b");
		}
	}
}