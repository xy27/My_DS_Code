#include<iostream>
#include"sort.h"
using namespace std;

int main()
{
	int A[] = { 81,94,11,96,12,35,17,95,28,58,41,75,15 };

	//InsertionSort(A, 13);
	//InsertionSort_W(A, 13);
	//BubbleSort(A, 13);
	//BubbleSort_O(A, 13);
	//ShellSort(A, 13);

	//int delta[3] = { 5 };
	//ShellSort_D(A, 13, delta, 1);

	//MergeSort(A, 13);

	//QSort(A, 0, 12);

	HeapSort(A, 13);

	for (auto x : A)std::cout << x << ' ';
	std::cout << std::endl;

	return 0;
}