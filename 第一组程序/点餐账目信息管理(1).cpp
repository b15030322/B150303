#include <stdio.h>
#include <string.h>
#include <process.h>
#include <cstdlib>
#define jiaozigeshu 4//�����ж�����
void dayincaidan(void);//��ӡ�˵�
void dayinzhangdan(int n,int x);//��ӡ�˵�
void diancan(int i);//��ͺ���
void cost(int n,int x);//�������Ѷ�
void jiezhang(void);//����
void genggai(void);//���Ķ���
void shanchudingdan(int n,int x);//ɾ������
void tongji(int h);//ͳ��
void chaxun(int h);//��ѯ
void paixu(int h);//����
void tiancai(int n,int x);//���
void huancai(int n,int x);//����
void shancai(int n,int x);//ɾ��
void zengjian(int n,int x);//������
struct joz//�ýṹ�����ڴ���ԭʼ��Ϣ���³���ֻ���ò�����
{
	char zhonglei;
	char mingzi[10];
	int jiage;
	int num;//ʣ���������������
}jz[jiaozigeshu];
struct jiaozi//�ýṹ�����ڴ��������Ϣ���˵����Ը���
{
	char zhonglei;
	char mingzi[10];
	int jiage;
	int num;//ʣ���������������
}jiao[jiaozigeshu];
struct DC//�ýṹ�����ڴ���ÿһ���ĵ����Ϣ
{
	int bianhao;//������ţ����ں���ͳ��
	struct date//�ṹ�嶨��ʱ��
	{	
		int hour;
		int minute;
	}shijian;
	int zhuohao;
	int gukeshuliang;
    struct dd//�ṹ�嶨�嶩����Ϣ
	{
		char zhonglei;
		int shuliang;
	}dc[jiaozigeshu];
	int caileishu;//�����˼�����
	int cost;
	char zhuangtai[20];
}dcxx[50];
int main()
{
	int n,h=1,m=0;//hΪϵͳ���ı�ţ���һ�β����һ��
	FILE*fp;FILE*fd;//��ӡ�˵�
	FILE *fp1,*fp2;
	jiaozi stu[2] = {{'a','b',1,1,},{'b','a',2,2}};
	if((fp=fopen("G:\\��ҵ\\xinxi.txt","a+"))==NULL)//Ϊ������ģ����ӵ�������Ϣ������һ�����д���ļ����˴�ֱ�ӵ���
	{
		printf("ϵͳ�����޷�����˵�\n");
		exit(0);
	}
   for(int i=0;i<jiaozigeshu;i++)//ʹ��if��ʾ����
	{
	fscanf(fp,"%s%s%d%d", &jiao[i].zhonglei, &jiao[i].mingzi,&jiao[i].jiage,&jiao[i].num);  // ѭ����ȡ
	} 
	fclose(fp);  //�ر��ļ�
    while(1)
	{
        system("color F1");
		printf("-------------------------\n");  /*����һ��ѡ��Ĺ��ܣ����Ե�ͣ����ˣ���ѯ����������,ͳ�ƣ�����*/
		printf("   ��ӭ����ѡ��ϵͳ      \n");
		printf("     1.���              \n");
		printf("     2.����(��ʾ�˵�)    \n");  //�ȵ�ͺ���ˣ������Ұѵ�ͺͽ��˷ֿ�
		printf("     3.��������(����ɾ��)\n");
		printf("     4.ͳ��              \n");
		printf("     5.��ѯ              \n");
		printf("     6.����              \n");
		printf("     7.�ػ�              \n");
		printf(" �������Ӧ���ѡ����  \n");
		printf("-------------------------\n");
		do//�����do while ��ֹ�������
		{
			scanf("%d",&n);	fflush(stdin);
			switch(n)
			{
				case 1: diancan(h++);break;
				case 2: jiezhang();break;
				case 3: genggai();break;
				case 4: tongji(h-1);break;
				case 5: chaxun(h-1);break;
				case 6: paixu(h-1);break;
				case 7: printf("ϵͳ�ػ�\n");break;
				default:printf("���벻��ȷ������������\n");
			}
		}while(n!=1&&n!=2&&n!=3&&n!=4&&n!=5&&n!=6&&n!=7);
		if(n==7) 
			break;    //����ѭ����ϵͳ����
	}
	if((fd=fopen("G:\\��ҵ\\xiaoshou.txt","w+"))==NULL)//����һ�ļ�����Ľ����ȫ��������Ϣ
	{
		printf("�ļ�����error\n");
		exit(0); 
	}
	fclose(fd);
}
void dayincaidan(void)
{
	int i;
	printf("������������������������---------������\n");
    printf("��    ��ӭ        �˵�       ����    ��\n");
	printf("���������� �������� ���Ӽ۸� ʣ��������\n");     
	printf("������������������������������-��������\n");
	printf("**********************************************\n");
	for(i=0;i<jiaozigeshu;i++)//ʹ��if��ʾ����
	{
		printf("    %c      %-10s     %d\t",jiao[i].zhonglei,jiao[i].mingzi,jiao[i].jiage);
		if(jiao[i].num>0)
			printf("%d\n",jiao[i].num);
		else
			printf("   ������\n");
	}//�˵����꣬����������ʾ
}
void dayinzhangdan(int n,int x)
{
	int i;
	printf("������%d   ",n);printf("���ţ�%d   ",dcxx[n].zhuohao);printf("���ʱ�䣺%2d:%2d\n",dcxx[n].shijian.hour,dcxx[n].shijian.minute);
	printf("������������������������---------������\n");
    printf("��    лл        �˵�       �ݹ�    ��\n");
	printf("����������                   ����������\n");     
	printf("������������������������������-��������\n");
	for(i=0;i<x;i++)
			printf("%4c%30d\n",dcxx[n].dc[i].zhonglei,dcxx[n].dc[i].shuliang);
		printf("*******************************************\n");
	cost(n,x);
	printf("�ܼ� %d yuan\n",dcxx[n].cost);
}
void diancan(int i)
{
		int j=0,t=0,r=0,m=0;
		dayincaidan();
		printf("��ţ�%d\n",dcxx[i].bianhao=i);/*bianhao(���)�������Ӧ*/
		printf("�롤����ʱ��(��: 12 15 (����\" ��\")): ");scanf("%d %d",&dcxx[i].shijian.hour,&dcxx[i].shijian.minute);fflush(stdin);
		printf("�롤��������: ");scanf("%d",&dcxx[i].zhuohao);printf("\n");fflush(stdin);
		printf("�롤����˿�����: ");scanf("%d",&dcxx[i].gukeshuliang);printf("\n");fflush(stdin);
		printf("\n����#�ּ��������,���������ʼ���\n");getchar();fflush(stdin);
		do
		{
			printf("\n����ˮ������(������ĸ��:a,b)��");scanf("%c",&dcxx[i].dc[j].zhonglei);fflush(stdin);
			printf("����ˮ��������");scanf("%d",&dcxx[i].dc[j].shuliang);printf("\n");fflush(stdin);
			for(m=0;m<jiaozigeshu;m++)
				if(jiao[m].zhonglei==dcxx[i].dc[j].zhonglei)
					jiao[m].num=jiao[m].num-dcxx[i].dc[j].shuliang;
			j++;
		}while(getchar()!='#');
		dcxx[i].caileishu=j;
        cost(i,j);	
		printf("Ӧ����%d\n",dcxx[i].cost);
		strcpy(dcxx[i].zhuangtai,"δ֧��");
		fflush(stdin);

}
void jiezhang(void)
{
	int n,ch;
	printf("�롤������\n");scanf("%d",&n);fflush(stdin);
    dayinzhangdan(n,dcxx[n].caileishu);
	printf("�Ƿ����ڸ��y or n\n");
	ch=getchar(); fflush(stdin);
	if(ch=='y')
	{
		printf("����ɹ�\n");
		strcpy(dcxx[n].zhuangtai,"��֧��");
	}
	else
		return ;
}
void genggai(void)
{
	int n,x;
	printf("�롤������Ҫ���ĵı��\n"); scanf("%d",&n); fflush(stdin);
	printf("�롤���������\n");
	printf("1.���  2.����  3.ɾ��  4.�������� 5.ɾ������\n"); 
	scanf("%d",&x);fflush(stdin);
	switch(x)
	{
	case 1: tiancai(n,dcxx[n].caileishu);break;
	case 2: huancai(n,dcxx[n].caileishu);break;
	case 3: shancai(n,dcxx[n].caileishu);break;
	case 4: zengjian(n,dcxx[n].caileishu);break;
	case 5: shanchudingdan(n,dcxx[n].caileishu);break;
	default: printf("������󷵻ص�����Ļ\n");
	}
}
void tongji(int h)
{
	int sum=0,guke=0,i;
	for(i=1;i<=h;i++)
	{
		sum+=dcxx[i].cost;
		guke+=dcxx[i].gukeshuliang;
	}
	printf("�����۶�Ϊ%d\n�ܹ˿�����Ϊ%d\n",sum,guke);
}
void chaxun(int h) 
{
	char ch,dh;
	int i,count=1;
	printf("1.��ѯ���ӿ������d  2.��ѯδ֧����������s\n");
	dh=getchar();fflush(stdin);
	switch(dh)
	{
	case 'd':
		{
			printf("����������������������\n");
			printf("���������� �������� ��\n");     
			printf("������������������--��\n");
			printf("*********************\n");
			for(i=0;i<jiaozigeshu;i++)//ʹ��if��ʾ����
				printf("     %c    %s \n",jiao[i].zhonglei,jiao[i].mingzi);//���Ӵ���
			printf("�롤����������ࣺ");
			ch=getchar();fflush(stdin); 
			for(i=0;i<jiaozigeshu;i++)
			{
				if(ch==jiao[i].zhonglei)
					printf("ʣ������Ϊ%d\n",jiao[i].num);
			}
			printf("��ѯ���\n");
		}
			break;
	case 's':
		{
			for(i=1;i<=h;i++)
			if(strcmp(dcxx[i].zhuangtai,"δ֧��")==0)
			{
				printf("δ֧���Ķ����ţ�%d\n",dcxx[i].bianhao);
				printf("Ӧ����%d\n",dcxx[i].cost);
				count++;
			}
			if(count==h)
				printf("��δ֧������\n");
		}
			break;
	default:printf("������󣬷���������\n");return ;
	}
}
void paixu(int h)
{

	int i,j,k,h1,hh,m1,mm,q,f1,f2,t;
    int a[jiaozigeshu]={0};int b[4]={0,1,2,3};
	printf("�����Ӧ�������:1.�����۽������  2.��ʱ�������\n");
    fflush(stdin);scanf("%d",&q);fflush(stdin);
	switch(q)
	{
	case 1:
			printf("�������ӵ͵������򣨰�����\n");
			for(i=0;i<jiaozigeshu;i++)
				a[i]=(jz[i].num-jiao[i].num)*jiao[i].jiage;/*���������Ľ��*/
			for(i=0;i<jiaozigeshu;i++)
			{
				k=i;
				for(j=i;j<=jiaozigeshu-1;j++)
				{
					if(a[j]>=a[k])
						k=j;
					if(a[k]!=a[j])
					{
						t=a[j];
						a[j]=a[k];
						a[k]=t;
						t=b[j];
						b[j]=b[k];
						b[k]=t;
					}	
				}
			}
			for(i=0;i<jiaozigeshu;i++)
				printf("%c %s %2dԪ\n",jiao[b[i]].zhonglei,jiao[b[i]].mingzi,a[i]);
			break;
	case 2:
			printf("�롤�����ѯ��ʱ���\n");
			printf("��������ʼʱ��(��:12ʱ15�ּ�����12 15(����\" ��\"))��");scanf("%d %d",&h1,&m1);printf("\n");fflush(stdin);
			printf("��������ֹʱ��(��:12ʱ15�ּ�����12 15(����\" ��\"))��");scanf("%d %d",&hh,&mm);printf("\n");fflush(stdin);	
			for(i=1;i<=h;i++)
				if((dcxx[i].shijian.hour*60+dcxx[i].shijian.minute)>=(h1*60+m1))
				{
					printf("��ʼ���Ϊ%d",f1=i);
					break;
				}
			for(j=i-1;i<=h;i++)
				if((dcxx[i].shijian.hour*60+dcxx[i].shijian.minute)>=(hh*60+mm))
				{
					printf(" ��ֹ���Ϊ%d\n",f2=i);
					break;
				}
			for(i=f1;i<=f2;i++)
				for(j=0;j<dcxx[i].caileishu;j++)
					switch(dcxx[i].dc[j].zhonglei)
					{
						case 'a': a[0]+=dcxx[i].dc[j].shuliang;break;
						case 'b': a[1]+=dcxx[i].dc[j].shuliang;break;
						case 'c': a[2]+=dcxx[i].dc[j].shuliang;break;
						case 'd': a[3]+=dcxx[i].dc[j].shuliang;break;
					};	
			printf("����ӵ͵���Ϊ��\n");
			for(i=0;i<jiaozigeshu;i++)
			{
				k=i;
				for(j=i;j<=jiaozigeshu-1;j++)
				{
					if(a[j]>=a[k])
						k=j;
					if(a[k]!=a[j])
					{
						t=a[j];
						a[j]=a[k];
						a[k]=t;
						t=b[j];
						b[j]=b[k];
						b[k]=t;
					}	
				}
			}
			for(i=0;i<jiaozigeshu;i++)
				printf("%c %s %2d��\n",jiao[b[i]].zhonglei,jiao[b[i]].mingzi,a[i]);
			break;
	default:printf("������󣬻ص�������\n");return ;
	}
}

void shancai(int n,int x)
{
	int i=0,ch,h;
	dayinzhangdan(n,x);
	dayincaidan();
	printf("ɾ���ֲ�(����˵Ĵ���):");ch=getchar();fflush(stdin);	
	for(i=0;i<x;i++)
	{
		if(ch==dcxx[n].dc[i].zhonglei)
		{	
			for(h=0;h<=jiaozigeshu;h++)//�ָ����
				if(ch==jiao[h].zhonglei)	
					jiao[h].num+=dcxx[n].dc[i].shuliang;
			dcxx[n].dc[i].shuliang=0;

		}
	}
	printf("�ɹ�������\n");
	
}
void zengjian(int n,int x)
{
	char ch;int b;int h;int i;
	dayinzhangdan(n,x);
	dayincaidan();
	printf("�������ֲ�(����˵�����):");ch=getchar();fflush(stdin);
	printf("�������� ���为��\n"); scanf("%d",&b);fflush(stdin);
	for(i=0;i<x;i++)
	{
		if(ch==dcxx[n].dc[i].zhonglei)
		{	
			for(h=0;h<=jiaozigeshu;h++)//�ָ����
				if(ch==jiao[h].zhonglei)	
					jiao[h].num-=b;
			dcxx[n].dc[i].shuliang+=b;
		}
	}
	printf("�ɹ�������\n");
}
void tiancai(int n,int x)
{
	char ch;int b,h;
	dayinzhangdan(n,x);
	dayincaidan();
	printf("�����ֲ�(����˵�����):");ch=getchar();fflush(stdin);
	printf("����������");scanf("%d",&b);fflush(stdin);
	dcxx[n].dc[x].zhonglei=ch;dcxx[n].dc[x].shuliang=b;dcxx[n].caileishu+=1;
	for(h=0;h<=jiaozigeshu;h++)//�ı���
				if(ch==jiao[h].zhonglei)	
					jiao[h].num-=b;
	printf("�ɹ�������\n");
}
void huancai(int n,int x)
{
	dayinzhangdan(n,x);
	dayincaidan();
	printf("\n");
	printf("ʵ�ֻ��˹��ܣ���ɾ��ԭ���Ĳ�������²ˣ�\n�����������\n");
	getchar();
	shancai(n,x);
	tiancai(n,x);
	printf("�ɹ�������\n");
}
void cost(int n,int x)
{
	int i,j,sum=0;
	for(i=0;i<x;i++)
		for(j=0;j<jiaozigeshu;j++)
			if(dcxx[n].dc[i].zhonglei==jiao[j].zhonglei)
				sum+=((jiao[j].jiage)*(dcxx[n].dc[i].shuliang));
	dcxx[n].cost=sum;
}
void shanchudingdan(int n,int x)
{
	int i,j;
	char ch;
	dayinzhangdan(n,x);
	dayincaidan();
	printf("\n");
	printf("ȷ��ɾ����\n����yɾ��������������ص�������: ");
	if((ch=getchar())=='y')
	{	
		fflush(stdin);
		strcpy(dcxx[n].zhuangtai,"����ɾ��");
		dcxx[n].cost=0;
		dcxx[n].gukeshuliang=0;
		for(i=0;i<x;i++)//ɾ����ָ����
			for(j=0;j<jiaozigeshu;j++)
				if(dcxx[n].dc[i].zhonglei==jiao[j].zhonglei)
					jiao[j].num+=dcxx[n].dc[i].shuliang;
		for(i=0;i<x;i++)
			dcxx[n].dc[i].shuliang=0;
		printf("������ɾ��\n");
	}
}



	


    





				


	
			

		




		 




	











