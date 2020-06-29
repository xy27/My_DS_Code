#ifndef INSERT_SORT_H
#define INSERT_SORT_H


/*��̬����*/
#define SIZE 100
typedef struct {		//��������
	int key;
	int next;
}SLNode;

typedef struct {		//��̬����
	SLNode r[SIZE];		//0�ŵ�ԪΪ��ͷ���
	int length;			//����ǰ����
}SLinkList;

Status CreateSqlist(Sqlist &L, char *filename);
void InsertSort(Sqlist &L);
void BInsertSort(Sqlist &L);
void TwoInsertSort(Sqlist &L);
void TableInsert(SLinkList &S, char *filename);
void Arrang(SLinkList &SL);
void swap(int &i, int &j);
void ShellInsert(Sqlist &L, int dk);
void ShellSort(Sqlist &L, int dlta[], int t);


#endif // !INSERT_SORT_H
