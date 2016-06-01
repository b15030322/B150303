/*②book.c文件的完整内容*/
#include "book.h"
#include <stdio.h>

int readBoo(Book *boo , int n) 
{        
	int i,j;
	for (i=0;i<n;i++)
	{
		printf("Input one book\'s information\n");
		printf("num:  ");
	    scanf("%ld", &boo[i].num);
		if (boo[i].num==0) break;
		printf("title: ");
		scanf("%s",boo[i].title);	
		printf("author:  ");
		scanf("%s",boo[i].author);
		printf("price:  ");
		scanf("%d",&boo[i].price);
    	     boo[i].total=0;              
		printf("Input four data of the book:\n");
		for (j=0;j<4;j++)
	    {
		    scanf("%d",&boo[i].score[j]);	
		}
		boo[i].rank=0;
	}
	return i;                      
}
void printBoo ( Book  *boo , int n)      
{
    int i,j;
	for (i=0;i<n;i++)
	{
		printf("%10ld", boo[i].num);
		printf("%10s", boo[i].title);
		printf("%10s", boo[i].author);
		printf("%10d", boo[i].price);
		for (j=0;j<4;j++)
		printf("%10d",boo[i].score[j]);
	    printf("%15d",boo[i].total);
		printf("%10d\n",boo[i].rank);
	}
}

int equal(Book b1,Book b2,int condition) 
{
	if (condition==1)                  
		return b1.num==b2.num;
	else if (condition==2)               
     {
	     if (strcmp(b1.title,b2.title)==0) 	return 1;
		else return 0;
     }
	else if (condition==3)                /*如果参数condition的值为3，则比较名次*/
			return b1.rank==b2.rank;
	else if (condition==4)          
			return b1.total==b2.total;
	else return 1;                      
} 

int larger(Book b1,Book b2,int condition)  
{
	if (condition==1)                  
		return b1.num>b2.num;
	if (condition==2)                   
		return b1.total>b2.total;	
	else return 1;
}

void reverse(Book boo[],int n)           
{
	int i;
	Book temp;
	for (i=0;i<n/2;i++)                  
	{
		temp=boo[i];
		boo[i]=boo[n-1-i];
		boo[n-1-i]=temp;
	}
}

void calcuTotal(Book boo[],int n)        
{
	int i,j;
	for (i=0;i<n;i++)                    
	{
		boo[i].total =0;
		for (j=0;j<4;j++)               
			boo[i].total +=boo[i].score[j];
	}	
}
void calcuRank(Book boo[],int n)     
{
	int i ;                       
	sortBoo(boo,n,2);            
	reverse(boo,n);
	boo[0].rank=1;                    
	for (i=1;i<n;i++)                   
	{
		if (equal(boo[i],boo[i-1],4))      
			boo[i].rank=boo[i-1].rank;     
	    else
			boo[i].rank=i+1;        
	}
}

void calcuMark(double m[4][4],Book boo[],int n) 
{
	int i,j;
	for (i=0;i<n;i++)               	
	{ 
		m[i][0]=boo[0].score[i];     
		for (j=1;j<n;j++)
			if (m[i][0]<boo[j].score[i])
				m[i][0]=boo[j].score[i];
	}
	for (i=0;i<n;i++)                 
	{ 
		m[i][1]=boo[0].score[i];      
		for (j=1;j<n;j++)
			if (m[i][1]>boo[j].score[i])
				m[i][1]=boo[j].score[i];
	}
	for (i=0;i<n;i++)                 
	{ 
		m[i][2]=boo[0].score[i];     
		for (j=1;j<n;j++)
			m[i][2]+=boo[j].score[i];
		m[i][2]/=n;
	}
}

void sortBoo(Book boo[],int n,int condition) 
{
	int i,j,m;                     
	Book t;
	for (i=0;i<n-1;i++)                
	{
		m=i;
		for (j=i+1;j<n;j++)            
			if (larger(boo[m],boo[j],condition))
				m=j;
		if (i!=m)               
		{
			t=boo[i];
			boo[i]=boo[m];
			boo[m]=t;
		}
	}
}

int searchBoo(Book boo[],int n,Book b,int condition,int f[ ])  

{
	int i,j=0,find=0;
	for (i=0;i<n;i++)                                 
		if (equal(boo[i],b,condition))  
		{
			f[j++]=i;                         
			find++;	                                                  
		}
	 return find;                                
}

int insertBoo(Book boo[],int n,Book b)            
{
	int i;
	sortBoo(boo,n,1);                             
	for (i=0;i<n;i++)
	{
		if (equal(boo[i],b,1))                    
		{
		    printf("this record exist,can not insert again!\n");
		    return n;
		}
	}
	for (i=n-1;i>=0;i--)                         
	{
		if (!larger(boo[i],b,1))                  
		break;
		boo[i+1]=boo[i];                        
	}
	boo[i+1]=b;                                                                  
	n++;                                    
	return n;                               
}
int deleteBoo(Book boo[],int n,Book b)          
{
	int i,j;
	for (i=0;i<n;i++)                          
		if (equal(boo[i],b,1))   break;         
	if (i==n)                               
	{
		printf("This record does not exist!\n");  
		return n;
	}
	for (j=i; j<n-1; j++)                      
		boo[j]=boo[j+1];                    
                                                                            
	n--;                                      
	return n;                                 
}
