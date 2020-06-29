#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#include"../../../chapter2/sqlist/sqlist.h"
#include"./type.h"
#include"./insert_sort.h"

/*
 * ���ļ�filename�ж�ȡ���ݴ���˳���L��0�ŵ�Ԫ����
 */
Status CreateSqlist(Sqlist &L, char*filename)
{
	InitList_Sq(L);

	FILE *pf;
	ElemType e;

	pf = fopen(filename, "r");
	if (pf == NULL) {
		printf("���ļ�%sʧ�ܣ�", filename);
		return ERROR;
	}
	while (fscanf(pf, "%d", &e) != EOF)
		ListInsert_Sq(L, 2, e);
	fclose(pf);
	return OK;
}
/*
 * ��˳�������������
 */
void InsertSort(Sqlist &L)
{
	int i, j;
	for (i = 2; i <= L.length; i++) {//�ӵڶ���Ԫ�ؿ�ʼ���в�������
		L.elem[0] = L.elem[i];	 //ֵ�����ڱ�,���ÿ�δ������Ԫ��
		j = i - 1;					
		while (j > 0 && L.elem[j] > L.elem[0]) {
			L.elem[j + 1] = L.elem[j];
			j--;
		}
		L.elem[j + 1] = L.elem[0];
	}
}

void BInsertSort(Sqlist &L)
{
	int i, j, low, high, mid;
	for (i = 2; i <= L.length; i++) {
		L.elem[0] = L.elem[i];
		high = i - 1;
		low = 1;
		while (high >= low) {
			mid = (high + low) / 2;
			if (L.elem[0] < L.elem[mid])
				high = mid - 1;
			else
				low = mid + 1;
		}
		for (j == i - 1; j >= low; j--)
			L.elem[j + 1] = L.elem[j];
			L.elem[low] = L.elem[0];
	}	
}


/*
 * ��������������һ�����򣨲�������
 */
void ShellInsert(Sqlist &L, int dk)
{
	int i, j;
	for (i = dk + 1; i <= L.length; i++) {
		if (L.elem[i] < L.elem[i - dk]) {
			L.elem[0] = L.elem[i];
			j = i - dk;
			while (j > 0 && L.elem[j] > L.elem[0]) {
				L.elem[j + dk] = L.elem[j];
				j = j - dk;
			}
			L.elem[j + dk] = L.elem[0];
		}
	}
}


/*
 * ϣ�����򣬰���������dlta[0..t-1]��˳���L��ϣ��������dlta[t-1]����Ϊ1
 */
void ShellSort(Sqlist &L, int dlta[], int t)
{
	int k;
	for (k = 0; k < t; k++)
		ShellInsert(L, dlta[k]);
}