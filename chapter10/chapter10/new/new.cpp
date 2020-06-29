
#include"new.h"
#include<iostream>

void InsertionSort(int A[], int N) {
	int i,j,temp;
	for (i = 1; i < N; ++i) {
		temp = A[i];
		for (j = i; j > 0 && A[j - 1] > temp; --j)
			A[j] = A[j - 1];
		A[j] = temp;
	}
}

//感觉对希尔排序的理解还不够
void ShellSort(int A[], int N) {
	int i, j, increment,temp;

	for (increment = N / 2; increment > 0; increment /= 2) {//控制希尔排序增量序列
		for (i = increment; i < N; i++) {//控制每一趟希尔排序
			temp = A[i];
			for (j = i; j >= increment; j -= increment)//控制交换操作
				if (temp < A[j - increment])
					A[j] = A[j - increment];
				else break;
			A[j] = temp;
		}
	}
}

//归并过程
void Merge(int A[], int temp_array[], int left_pos, int right_pos, int right_end) {
	int left_end,temp_pos,num;
	left_end = right_pos - 1;
	temp_pos = left_pos;
	num = right_end - left_pos + 1;
	//main loop
	while (left_pos <= left_end && right_pos <= right_end) {
		if (A[left_pos] <= A[right_pos])
			temp_array[temp_pos++] = A[left_pos++];
		else
			temp_array[temp_pos++] = A[right_pos++];
	}
	while (left_pos <= left_end)	//copy rest of first half
		temp_array[temp_pos++] = A[left_pos++];
	while (right_pos <= right_end)	//copy rest of second half
		temp_array[temp_pos++] = A[right_pos++];
	//copy temp_array back
	for (int i = 0; i < num; i++, right_end--)
		//A[right_end--] = temp_array[right_end--]; right_end在一次循环中减了两次，好蠢的错误
		A[right_end] = temp_array[right_end];
}

//归并排序
void MergeSort(int A[], int N) {
	int *temp_array = (int*)malloc(N * sizeof(int));	//这个辅助空间的设计非常好
	if (temp_array) {
		MSort(A, temp_array, 0, N - 1);
		free(temp_array);
	}
}

void MSort(int A[], int temp_array[], int left, int right) {
	int center;
	if (left < right) {	//只有一个元素，自然有序，不用做任何事
		center = (left+right) / 2;
		MSort(A, temp_array, left, center);
		MSort(A, temp_array, center + 1, right);
		Merge(A, temp_array, left, center + 1, right);
	}
}

//选择枢纽
int Median3(int A[], int left, int right) {
	int center = (left + right) / 2;

	if (A[left] > A[center])
		std::swap(A[left], A[center]);
	if (A[left] > A[right])
		std::swap(A[left], A[right]);
	if (A[center] > A[right])
		std::swap(A[center], A[right]);
	//Invariant:A[left]<=A[center]<=A[right]
	std::swap(A[center], A[right - 1]);	//hide pivot
	return A[right - 1];	//return pivot
}

void Qsort(int A[], int left, int right) {
	int i, j, pivot;

	if (left + Cutoff <= right) {
		//分割
		pivot = Median3(A, left, right);
		i = left; j = right - 1;
		while (true) {
			while (A[++i] < pivot) {}
			while (A[--j] > pivot) {}
			if (i < j)
				std::swap(A[i], A[j]);
			else break;
		}
		std::swap(A[i], A[right - 1]);	//restore pivot
		//分割完成

		Qsort(A, left, i - 1);
		Qsort(A, i + 1, right);
	}
	else //do an insertion sort on the subarray
		InsertionSort(A + left, right - left + 1);
}

//下溯      其实就是比较，寻找合适的位置，插入排序是与前面有序序列比较，
//下溯是父结点与孩子结点不停地比较，寻找合适的位置
void PercDown(int A[], int i, int N) {
	int child,temp;
	for (temp = A[i]; LeftChild(i) < N; i = child) {
		child = LeftChild(i);
		if (child != N - 1 &&A[child + 1] > A[child])
			child++;
		if (temp < A[child])
			A[i] = A[child];
		else break;
		//A[i] = temp;
	}
	A[i] = temp;
}

void HeapSort(int A[], int N) {
	int i;
	for (i = N/2-1; i >= 0; --i)	//BuildHeap
		PercDown(A, i, N);
	for (i = N - 1; i > 0; --i) {	//DeleteMax
		std::swap(A[0], A[i]);
		PercDown(A, 0, i);
	}
}

void BuildHeap(int A[], int N) {
	for (int i = N / 2 - 1; i >= 0; --i)
		PercDown(A, i, N);
}






void Insert(int A[], int x) {

}

/*
在根节点处产生了一个空穴，由于堆少了一个元素，因此堆中最后一个元素必须移动到该堆的某个地方
deletemin中只是没有交换
heapsort中交换了
过程都是一样的空穴向下移动，最终将最后一个元素放在空穴中

*/