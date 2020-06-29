#include"new.h"
#include<iostream>

int main()
{
	int A[] = { 81,94,11,96,12,35,17,95,28,58,41,75,15 };
	/*int A[] = { 4,3,2,1 };	*///小的实例可以用来调式
	/*ShellSort(A, 13);*/
	/*MergeSort(A, 13);*/
	/*Qsort(A, 0, 12);*/
	//int A[] = { 15,12,11 };
	//InsertionSort(A, 3);
	HeapSort(A, 13);
	for (auto x : A)std::cout << x << ' ';

	std::cout << std::endl;

	system("pause");
	return 0;
}