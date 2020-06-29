#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#include"../../../chapter2/sqlist/sqlist.h"
#include"./type.h"
#include"./insert_sort.h"

/*
 * 从文件filename中读取数据创建顺序表L，0号单元不用
 */
Status CreateSqlist(Sqlist &L, char*filename)
{
	InitList_Sq(L);

	FILE *pf;
	ElemType e;

	pf = fopen(filename, "r");
	if (pf == NULL) {
		printf("打开文件%s失败！", filename);
		return ERROR;
	}
	while (fscanf(pf, "%d", &e) != EOF)
		ListInsert_Sq(L, 2, e);
	fclose(pf);
	return OK;
}
/*
 * 对顺序表作插入排序
 */
void InsertSort(Sqlist &L)
{
	int i, j;
	for (i = 2; i <= L.length; i++) {//从第二个元素开始进行插入排序
		L.elem[0] = L.elem[i];	 //值赋给哨兵,存放每次待排序的元素
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
 * 按给定增量进行一趟排序（插入排序）
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
 * 希尔排序，按增量序列dlta[0..t-1]对顺序表L作希尔排序，且dlta[t-1]必须为1
 */
void ShellSort(Sqlist &L, int dlta[], int t)
{
	int k;
	for (k = 0; k < t; k++)
		ShellInsert(L, dlta[k]);
}