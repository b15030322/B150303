/* ��criminal.h�ļ����������� */
#ifndef _CRIMINAL             /*�������룬��ֹ�ظ������Ĵ���*/
#define _CRIMINAL 
#include <string.h>
#define NUM 20                /*���������Ա�����������˴����Ը���ʵ����Ҫ�޸ĳ���ֵ*/
struct Criminal {
	long num;													//����
	char name[20];												//����
	char sex[10];													//�Ա�
	int year;
int month;
int day;														//����ʱ��
int total;														//�ܳ��ڴ���
};
typedef struct Criminal Criminal;

#define sizeCri sizeof(Criminal)      /*һ��������Ա������Ϣ��¼����Ҫ���ڴ�ռ��С*/

int readCri(Criminal cri[],int n);       /*���������Ա������Ϣ��¼ֵ������Ϊ0������涨������¼ʱֹͣ*/

void printCri(Criminal  *Cri , int n);   /*������з�����Ա��¼��ֵ*/

int equal(Criminal s1,Criminal s2,int condition);  /*����condition�����ж�����Criminal����������ȷ�*/
int larger(Criminal s1,Criminal s2,int condition);  /*����condition�Ƚ�Criminal�������ݴ�С*/
void reverse(Criminal cri[],int n);             /*������Ա��¼����Ԫ������*/

void calcuTotal(Criminal cri[],int n);           /*���ݳ������ݼ�������Criminal�ܳ�������Ĵ���*/

/*void calcuRank(Criminal cri[],int n);           �����ּܷ���ѧ�������Σ������в�������
void calcuMark(double m[3][3],Criminal cri[],int n); /*�����ſε���ߡ���͡�ƽ���֣�m�����һά
/*��ʾ���ſΣ��ڶ�ά��ʾ��ߡ���͡�ƽ����*/

void sortCri(Criminal cri[],int n,int condition);   /*ѡ�񷨴�С�������򣬰�condition���涨������*/

int searchCri(Criminal cri[],int n,Criminal s,int condition,int f[]);  /*������������������s��ȵĸ�Ԫ��*/
/*�±�����f�����У���f��������Ϊ���ҽ�����ܲ�ֹһ����¼*/
int insertCri(Criminal cri[],int n,Criminal s);                   /*�������в���һ��Ԫ�ذ���������*/
int deleteCri(Criminal cri[],int n,Criminal s);                   /*��������ɾ��һ��ָ�����ŵ�Ԫ��*/
#endif
