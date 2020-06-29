#ifndef INSERT_SORT_H
#define INSERT_SORT_H


/*静态链表*/
#define SIZE 100
typedef struct {		//表结点类型
	int key;
	int next;
}SLNode;

typedef struct {		//静态链表
	SLNode r[SIZE];		//0号单元为表头结点
	int length;			//链表当前长度
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
