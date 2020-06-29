#define Cutoff (3)
#define LeftChild(i) (2*(i)+1)
void InsertionSort(int A[], int N);
void ShellSort(int A[], int N);
void MSort(int A[], int temp_array[], int left, int right);
void MergeSort(int A[], int N);
void Merge(int A[], int temp_array[], int left_pos, int right_pos, int rightend);

int Median3(int A[], int left, int right);
void Qsort(int A[], int left, int right);
int Partition(int A[], int left, int right);

void PercDown(int A[], int i, int N);
void HeapSort(int A[], int N);

void BuildHeap(int A[], int N);
void Insert(int A[], int x);

void PercUp(int A[], int i, int N);