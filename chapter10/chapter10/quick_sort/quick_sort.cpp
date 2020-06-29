#include<stdio.h>
#include<stdlib.h>

#include"./quick_sort.h"
#include"../../../chapter2/sqlist/sqlist.h"

int Partition(Sqlist &L, int low, int high)
{
	int i,j,pivotkey;
	i = low - 1;
	pivotkey = L.elem[high];
	for (j = low; j < high; j++) {
		if (L.elem[low] <= pivotkey) {
			i++;
			swap(L.elem[i], L.elem[j]);
		}
	}
	swap(L.elem[i + 1], pivotkey);
}

/*
 * ����a��b
 */
void swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

///*
//* ��������
//*/
//void QuickSorrt(Sqlist &L)
//{
//	QSort(L, 1, L.length);
//}

/*
 * �ݹ��˳���L�е�����L.elem[low..high]����������
 */
void Qsort(Sqlist &L, int low, int high)
{
	int pivotloc;
	if (low < high) {
		pivotloc = Partition(L, low, high);
		Qsort(L, low, pivotloc - 1);
		Qsort(L, pivotloc = 1, high);
	}
}

