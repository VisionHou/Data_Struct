
///////////////////////静态//////////////////
#if 0
#define Max_Size 1000
typedef unsigned int size_t;
typedef int DataType;

typedef struct SeqList
{
	DataType _array[Max_Size];//存储空间
	int _size;//有效元素的个数
}SeqList,*pSeqList;
 

//初始化
void SeqListInit(pSeqList ps);
//尾插
void SeqListPushBack(pSeqList ps,DataType data);
//尾删
void SeqListPopBack(pSeqList ps);
//头插
void SeqListPushFront(pSeqList ps, DataType data);
//头删
void SeqListPopFront(pSeqList ps);
//插入指定位置元素
void SeqListInsert(pSeqList ps, size_t pos,DataType data);
//清除指定位置元素
void SeqListErase(pSeqList ps, size_t pos);
//查找元素
int SeqListFind(pSeqList ps,  DataType data);
//删除元素
void SeqListRemove(pSeqList ps, DataType data);
//删除所有特定元素
void SeqListRemoveAll(pSeqList ps, DataType data);
//判空
int SeqListEmpty(pSeqList ps );
//有效个数
int SeqListSize(pSeqList ps);
//打印
void SeqLisPrint(pSeqList ps);
#endif

///////////////////////动态///////////////
typedef unsigned int size_t;
typedef int DataType;

typedef struct SeqListD
{
	DataType* _array;
	size_t _size;//有效元素的个数
	size_t _capacity;//有效元素的个数
}SeqListD, *pSeqListD;

//初始化
void SeqListDInit(pSeqListD ps);
//尾插
void SeqListDPushBack(pSeqListD ps, DataType data);
//尾删
void SeqListDPopBack(pSeqListD ps);
//判空
int SeqListDEmpty(pSeqListD ps);
//有效个数
int SeqListDSize(pSeqListD ps);
//清除
void SeqListDClear(pSeqListD ps);
//容量大小
int SeqListDCapacity(pSeqListD ps);
//销毁
void SeqListDDestory(pSeqListD ps);
//检测容量 扩容
int CheckCapacity(pSeqListD ps);
//打印
void SeqLisDPrint(pSeqListD ps);




