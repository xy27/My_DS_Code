
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

//�о���ϣ���������⻹����
void ShellSort(int A[], int N) {
	int i, j, increment,temp;

	for (increment = N / 2; increment > 0; increment /= 2) {//����ϣ��������������
		for (i = increment; i < N; i++) {//����ÿһ��ϣ������
			temp = A[i];
			for (j = i; j >= increment; j -= increment)//���ƽ�������
				if (temp < A[j - increment])
					A[j] = A[j - increment];
				else break;
			A[j] = temp;
		}
	}
}

//�鲢����
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
		//A[right_end--] = temp_array[right_end--]; right_end��һ��ѭ���м������Σ��ô��Ĵ���
		A[right_end] = temp_array[right_end];
}

//�鲢����
void MergeSort(int A[], int N) {
	int *temp_array = (int*)malloc(N * sizeof(int));	//��������ռ����Ʒǳ���
	if (temp_array) {
		MSort(A, temp_array, 0, N - 1);
		free(temp_array);
	}
}

void MSort(int A[], int temp_array[], int left, int right) {
	int center;
	if (left < right) {	//ֻ��һ��Ԫ�أ���Ȼ���򣬲������κ���
		center = (left+right) / 2;
		MSort(A, temp_array, left, center);
		MSort(A, temp_array, center + 1, right);
		Merge(A, temp_array, left, center + 1, right);
	}
}

//ѡ����Ŧ
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
		//�ָ�
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
		//�ָ����

		Qsort(A, left, i - 1);
		Qsort(A, i + 1, right);
	}
	else //do an insertion sort on the subarray
		InsertionSort(A + left, right - left + 1);
}

//����      ��ʵ���ǱȽϣ�Ѱ�Һ��ʵ�λ�ã�������������ǰ���������бȽϣ�
//�����Ǹ�����뺢�ӽ�㲻ͣ�رȽϣ�Ѱ�Һ��ʵ�λ��
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
�ڸ��ڵ㴦������һ����Ѩ�����ڶ�����һ��Ԫ�أ���˶������һ��Ԫ�ر����ƶ����öѵ�ĳ���ط�
deletemin��ֻ��û�н���
heapsort�н�����
���̶���һ���Ŀ�Ѩ�����ƶ������ս����һ��Ԫ�ط��ڿ�Ѩ��

*/