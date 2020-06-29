#include<vector>
#include<cstdlib>
using namespace std;


//原地归并
void Merge(vector<int>::iterator first, vector<int>::iterator middle, vector<int>::iterator last)
{

}

void MergeSortAux(vector<int>::iterator first,vector<int>::iterator last)
{
	if (last - first > 1) {
		//int center = (last-first) / 2;
		vector<int>::iterator middle = first + (last - first) / 2;
		MergeSortAux(first,middle);
		MergeSortAux(middle,last);
		Merge(first, middle, last);
	}
}

void MergeSort(vector<int>& v)
{

	MergeSortAux(v.begin(),v.end());
}

//=========================================================================================================================

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
	if (left < right) {		//元素个数>=2时才需要排序
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