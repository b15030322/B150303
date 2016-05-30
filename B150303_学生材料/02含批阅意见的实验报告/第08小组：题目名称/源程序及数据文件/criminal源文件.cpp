/*��criminal.c�ļ�����������*/
#include "criminal.h"
#include <stdio.h>

int readCri(Criminal  *cri , int n)          /*���������Ա��¼ֵ������Ϊ0������涨������¼ʱֹͣ*/
{
	int i;
	for (i=0;i<n;i++)
	{
		printf("Input one criminal\'s information\n");
		printf("num:  ");
	     scanf("%ld", &cri[i].num);
		if (cri[i].num==0) break;
		printf("name: ");
		scanf("%s",cri[i].name);	
		printf("sex:  ");
		scanf("%s",cri[i].sex);
    	     cri[i].total=0;                /*�ܳ��ڴ�����Ҫ������ã���ֵ��Ϊ0*/
		printf("Input year of the criminal:");
		    scanf("%d",&cri[i].year);
					printf("Input month of the criminal:");
	scanf("%d",&cri[i].month);
						printf("Input day of the criminal:");
	scanf("%d",&cri[i].day);
	/*cri[i].rank=0;                 �˴�Ϊ�ܳ��ڴ��������ֵ��Ϊ0*/
	}
	return i;                         /*����ʵ�ʶ���ļ�¼����*/
}

void printCri (Criminal  *cri, int n)       /*������з�����Ա��¼��ֵ*/
{
    int i;
	for (i=0;i<n;i++)
	{
		printf("%2ld  ", cri[i].num);
		printf("%15s", cri[i].name);
		printf("%15s", cri[i].sex);
		printf("%18d/%2d/%2d",cri[i].year,cri[i].month,cri[i].day);
	    printf("%20d\n",cri[i].total);
	    /*printf("%5d\n",cri[i].rank);*/
	}
}

int equal(Criminal s1,Criminal s2,int condition)  /*����ж�����Criminal��¼���*/
{
	if (condition==1)                    /*�������condition��ֵΪ1����Ƚ�ѧ��*/
		return s1.num==s2.num;
	else if (condition==2)                /*�������condition��ֵΪ2����Ƚ�����*/
     {
	     if (strcmp(s1.name,s2.name)==0) 	return 1;
		else return 0;
     }
 /*else if (condition==3)                �������condition��ֵΪ3����Ƚ��ܳ��ڴ���
	     return s1.rank==s2.rank;*/
 else if (condition==4)                /*�������condition��ֵΪ4����Ƚ��ܷ�*/
		return s1.total==s2.total;
	else return 1;                       /*�����������1*/
} 

int larger(Criminal s1,Criminal s2,int condition)  /*����condition�����Ƚ�����Criminal��¼�Ĵ�С*/
{
	if (condition==1)                    /*�������condition��ֵΪ1����Ƚ�����*/
		return s1.num>s2.num;
	if (condition==2)                    /*�������condition��ֵΪ2����Ƚ��ܷ�*/
		return s1.total>s2.total;	
	else return 1; /*�����������1*/
}

void reverse(Criminal cri[],int n)             /*����Ԫ������*/
{
	int i;
	Criminal temp;
	for (i=0;i<n/2;i++)                   /*ѭ������ΪԪ��������һ��*/
	{
		temp=cri[i];
		cri[i]=cri[n-1-i];
		cri[n-1-i]=temp;
	}
}

/*void calcuTotal(Criminal cri[],int n)         �������з�����Ա���ܳ��ڴ���
{
	int i,j;
	for (i=0;i<n;i++)                    ���ѭ����������ѧ����¼
	{
		cri[i].total =0;
		for (j=0;j<3;j++)               �ڲ�ѭ������ÿ�γ�������
			cri[i].total +=stu[i].score[j];
	}	
}*/

/*void calcuMark(double m[3][3],Criminal cri[],int n) �����ſε���ߡ���͡�ƽ����
������ʽ������ά����m�ĵ�һά�������ſΣ��ڶ�ά������ߡ���͡�ƽ����
{
	int i,j;
	for (i=0;i<3;i++)                 �����ſε���߷�		
	{ 
		m[i][0]=stu[0].score[i];     
		for (j=1;j<n;j++)
			if (m[i][0]<stu[j].score[i])
				m[i][0]=stu[j].score[i];
	}
	for (i=0;i<3;i++)                  /*�����ſε���ͷ�
	{ 
		m[i][1]=stu[0].score[i];      
		for (j=1;j<n;j++)
			if (m[i][1]>stu[j].score[i])
				m[i][1]=stu[j].score[i];
	}
	for (i=0;i<3;i++)                 /*�����ſε�ƽ����
	{ 
		m[i][2]=stu[0].score[i];     
		for (j=1;j<n;j++)
			m[i][2]+=stu[j].score[i];
		m[i][2]/=n;
	}
}*/

void sortCri(Criminal cri[],int n,int condition)  /*ѡ�����򣬰�condition������С��������*/
{
	int i,j,minpos;                      /*minpos�����洢������СԪ�����ڵ��±�*/
	Criminal t;
	for (i=0;i<n-1;i++)                  /*����ѭ����n-1��*/
	{
		minpos=i;
		for (j=i+1;j<n;j++)             /*Ѱ�ұ�����СԪ�����ڵ��±�*/
			if (larger(cri[minpos],cri[j],condition))
				minpos=j;
		if (i!=minpos)                 /*��֤������СԪ�ص����±�Ϊi��λ��*/
		{
			t=cri[i];
			cri[i]=cri[minpos];
			cri[minpos]=t;
		}
	}
}

int searchCri(Criminal cri[],int n,Criminal s,int condition,int f[ ])  /*��cri��������condition��������*/
/*��s��ͬ��Ԫ�أ����ڲ�ֹһ����¼������������˽���ЩԪ�ص��±����� f������*/
{
	int i,j=0,find=0;
	for (i=0;i<n;i++)                                 /*�����ҵ�Ԫ��*/
		if (equal(cri[i],s,condition))  
		{
			f[j++]=i;                          /*�ҵ�����ȵ�Ԫ�أ������±�ŵ�f������*/
			find++;	                        /*ͳ���ҵ���Ԫ�ظ���*/                              
		}
	 return find;                                /*����find����ֵΪ0���ʾû�ҵ�*/ 
}

int insertCri(Criminal cri[],int n,Criminal s)              /*��cri��������ѧ�ŵ�������һ��Ԫ��s*/
{
	int i;
	sortCri(cri,n,1);                              /*�Ȱ���������*/
	for (i=0;i<n;i++)
	{
		if (equal(cri[i],s,1))                      /*������ͬ��������룬��֤���ŵ�Ψһ��*/
		{
		    printf("this record exist,can not insert again!\n");
		    return n;
		}
	}
	for (i=n-1;i>=0;i--)                          /*�����Ŵ�С��������*/
	{
		if (!larger(cri[i],s,1))                    /*���s���ڵ�ǰԪ��cri[i]�����˳�ѭ��*/
		break;
	cri[i+1]=cri[i];                         /*����Ԫ��cri[i]����һ��λ��*/
	}
	cri[i+1]=s;                                /*���±�i+1������Ԫ��s*/                                   
	n++;                                     /*Ԫ�ظ�������1*/
	return n;                                  /*��������Ԫ�ظ���*/
}

int deleteCri(Criminal cri[],int n,Criminal s)            /*��������ɾ��ָ�����ŵ�һ��Ԫ��*/
{
	int i,j;
	for (i=0;i<n;i++)                           /*Ѱ�Ҵ�ɾ����Ԫ��*/
		if (equal(cri[i],s,1))   break;            /*����ҵ����Ԫ�����˳�ѭ��*/
	if (i==n)                                 /*����Ҳ�����ɾ����Ԫ��*/
	{
		printf("This record does not exist!\n");    /*������ʾ��ϢȻ�󷵻�*/
		return n;
	}
	for (j=i; j<n-1; j++)                        /*�˴���������Ϊi<n��equal(cri[i],s,1)����*/ 
		cri[j]=cri[j+1];                       /*ͨ���ƶ�����ɾ���±�Ϊi��Ԫ��*/
                                                                            
	n--;                                      /*Ԫ�ظ������ټ�1*/
	return n;                                  /*�������и���*/
}

