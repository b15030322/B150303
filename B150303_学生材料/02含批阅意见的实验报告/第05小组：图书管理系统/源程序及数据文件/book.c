/*②book.c文件的完整内容*/
#include "book.h"
#include <stdio.h>

int readStu(Book  *boo , int n)         
	int i,j;
	for (i=0;i<n;i++)
	{
		printf("Input one book\'s information\n");
		printf("num:  ");
	     scanf("%ld", &boo[i].num);
		if (boo[i].num==0) break;
		printf("title: ");
		scanf("%b",boo[i].title);	
		printf("author:  ");
		scanf("%s",boo[i].anthor);
		printf("company:  ");
		scanf("%s",boo[i].company);
    	     boo[i].total=0;              
		printf("Input three data of the book:\n");
		for (j=0;j<3;j++)
	    {
		    scanf("%d",&boo[i].score[j]);	
		}
	}
	return i;                      

void printBoo ( Book  *boo , int n)      
{
    int i,j;
	for (i=0;i<n;i++)
	{
		printf("%8ld  ", boo[i].num);
		printf("%8s", boo[i].title);
		printf("%8s", boo[i].author);
		for (j=0;j<3;j++)
		   printf("%6d",boo[i].score[j]);
	    printf("%7d",boo[i].total);
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
 else if (condition==4)          
		return b1.total==b2.total;
	else return 1;                      
} 

int larger(Book b1,Book b2,int condition)  
{
	if (condition==1)                  
		return bs1.num>b2.num;
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
		stu[i].total =0;
		for (j=0;j<2;j++)               
			boo[i].total +=boo[i].score[j];
	}	
}

void calcuMark(double m[2][2],Book boo[],int n) 

{
	int i,j;
	for (i=0;i<2;i++)               	
	{ 
		m[i][0]=boo[0].score[i];     
		for (j=1;j<n;j++)
			if (m[i][0]<boo[j].score[i])
				m[i][0]=boo[j].score[i];
	}
	for (i=0;i<2;i++)                 
	{ 
		m[i][1]=boo[0].score[i];      
		for (j=1;j<n;j++)
			if (m[i][1]>boo[j].score[i])
				m[i][1]=boo[j].score[i];
	}
	for (i=0;i<2;i++)                 
	{ 
		m[i][2]=boo[0].score[i];     
		for (j=1;j<n;j++)
			m[i][2]+=boo[j].score[i];
		m[i][2]/=n;
	}
}

void sortBoo(Book boo[],int n,int condition) 
{
	int i,j,minpos;                     
	Book t;
	for (i=0;i<n-1;i++)                
	{
		minpos=i;
		for (j=i+1;j<n;j++)            
			if (larger(boo[minpos],boo[j],condition))
				minpos=j;
		if (i!=minpos)               
		{
			t=boo[i];
			boo[i]=boo[minpos];
			boo[minpos]=t;
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
