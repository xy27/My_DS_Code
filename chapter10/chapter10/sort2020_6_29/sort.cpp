#include<cstdlib>
#include<iostream>
#include"sort.h"

void InsertionSort(int A[], int N)
{
	for (int i = 1; i < N; ++i) {
		int j = i;
		int temp = A[i];		//��������(����)��Ԫ���ȱ��浽temp
		for (j = i; j > 0 && A[j - 1] > temp; --j)
			A[j] = A[j - 1];
		A[j] = temp;
	}
}

void InsertionSort_W(int A[], int N)
{
	for (int i = 1; i < N; ++i) {
		int j = i;
		int temp = A[i];
		while (j > 0 && A[j - 1] > temp) {
			A[j] = A[j - 1];
			--j;
		}
		A[j] = temp;
	}
}

void BubbleSort(int A[], int N)
{
	for (int i = 0; i < N - 1; ++i) {	//ÿ��ѭ����ʼ����N-i��Ԫ���������
		for (int j = 0; j < N - i - 1; ++j) {	//j=0
			if (A[j] > A[j + 1]) {
				int temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
			}
		}
	}
}

void BubbleSort_O(int A[], int N)
{
	bool order = false;					//order���������Ƿ�����
	for (int i = 0; i < N - 1 && order==false; ++i) {	//ÿ��ѭ����ʼ����N-i��Ԫ���������

		order = true;
		for (int j = 0; j < N - i - 1; ++j) {	//j=0
			if (A[j] > A[j + 1]) {
				int temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;

				order = false;
			}
		}
	}
}

void ShellSort(int A[], int N)
{
	int i, j, Increment;
	int temp;

	for (Increment = N / 2; Increment > 0; Increment /= 2) {
		for (i = Increment; i < N; ++i) {
			temp = A[i];
			for (j = i; j >= Increment && A[j - Increment] > temp; j -= Increment)
				A[j] = A[j - Increment];
			A[j] = temp;
		}
	}
}

//���Զ����������е�ϣ������  ϣ��������ʵ�ǲ�������


//��Ҫһ����̵��ܽ�
void ShellSort_D(int A[], int N, int delta[],int t)//delta:�������У�t:delta�ĳ���
{
	for (int i = 0; i < t; ++i) {
		for (int j = delta[i]; j < N; ++j) {	//һ�β������򣬱Ƚϼ����delta[i]
			int temp = A[j];
			int k = j;
			for (k = j; k > 0 && A[k - delta[i]] > temp; k -= delta[i])
				A[k] = A[k - delta[i]];
			A[k] = temp;
		}
	}
}


//�鲢����     �㷨��ʵ�ܼ�    ���ϲ�ʱ����������ƺܹؼ�

void Merge(int A[], int temp_array[], int left_pos, int right_pos, int right_end)
{
	int temp_pos = left_pos;
	int left_end = right_pos - 1;
	int num_elements = right_end - left_pos + 1;

	while (left_pos <= left_end && right_pos <= right_end)
		if (A[left_pos] < A[right_pos])
			temp_array[temp_pos++] = A[left_pos++];
		else
			temp_array[temp_pos++] = A[right_pos++];

	while (left_pos <= left_end)
		temp_array[temp_pos++] = A[left_pos++];
	while (right_pos <= right_end)
		temp_array[temp_pos++] = A[right_pos++];

	for (int i = 0; i < num_elements; ++i, --right_end)
		A[right_end] = temp_array[right_end];
}


void MSort(int A[], int temp_array[], int left, int right)
{
	if (left < right) {		//Ԫ�ظ���>=2ʱ����Ҫ����
		int mid = (left + right) / 2;
		MSort(A, temp_array, left, mid);
		MSort(A, temp_array, mid + 1, right);
		Merge(A, temp_array, left, mid + 1, right);
	}
}

void MergeSort(int A[], int N)
{
	int* temp_array = (int*)malloc(N * sizeof(int));
	if (temp_array) {
		MSort(A, temp_array, 0, N - 1);
		free(temp_array);
	}
	return;
}

//��������

int Median3(int A[], int left, int right)
{
	int mid = (left + right) / 2;

	if (A[left] > A[mid])
		std::swap(A[left], A[mid]);
	if (A[left] > A[right])
		std::swap(A[left], A[right]);
	if (A[mid] > A[right])
		std::swap(A[mid], A[right]);

	std::swap(A[mid], A[right - 1]);
	return A[right - 1];
}

void QSort(int A[], int left, int right)		//����ǳ�����
{
	if (right - left > Cutoff) {
		int pivot = Median3(A, left, right);
		int i = left;
		int j = right - 1;

		while (true) {
			while (A[++i] < pivot) {}
			while (A[--j] > pivot) {}

			if (i < j)
				std::swap(A[i], A[j]);
			else
				break;
		}
		std::swap(A[i], A[right - 1]);

		QSort(A, left, i - 1);
		QSort(A, i + 1, right);
	}
	else
		InsertionSort(A, right - left + 1);

	return ;
}

void PercDown(int A[], int i, int N)		//ά����A[i]Ϊ�����Ķѵ�����(������)
{
	int temp = A[i];				//Ҫ��A[i]���ں��ʵ�λ�ã�A[i]��ʱΪ��Ѩ
	while (LeftChild(i) < N) {
		int child = LeftChild(i);
		if (child != N - 1 && A[child + 1] > A[child])	//find max child
			++child;
		if (A[child] > temp) {
			A[i] = A[child];	//��Ѩ����
			i = child;
		}
		else
			break;
	}
	A[i] = temp;
}

//��ʵ�Ͳ�������Ĳ���һ��


void BuildHeap(int A[], int N)	//�����������ϴ�����
{
	for (int i = N / 2 - 1; i >= 0; --i)	//�ӽ��A[N/2-1]һֱ��A[0]���ѵĶ�����
		PercDown(A, i, N);
}


void HeapSort(int A[], int N)	//��������ж�����
{
	BuildHeap(A, N);	//�����������ϴ�����

	for (int i = N - 1; i > 0; --i) {	//�����Ԫ�����η��ڶ�β��ͬʱҲҪά�ֶ����ԣ��ѵĴ�С��1
		std::swap(A[0], A[i]);
		PercDown(A, 0, i);
	}
}
