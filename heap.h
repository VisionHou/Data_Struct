#pragma once

typedef int DataType;

#if 0
typedef struct Heap
{
	DataType* _array;//数组存放堆中节点
	int _size;
	int _capacity;
}Heap;

//创建堆
void CreatHeap(Heap* hp, DataType* array, int size);

//在堆中插入值为data的元素
void InsertHeap(Heap* hp, DataType data);

//获取堆顶元素
DataType TopHeap(Heap* hp);

//判断是否为空堆
int EmptyHeap(Heap* hp);

//获取堆中元素个数
int SizeHeap(Heap* hp);

//删除堆顶元素
void DeletetHeap(Heap* hp);

//销毁堆
void DestroyHeap(Heap* hp);

#endif



typedef int (*Compare)(DataType, DataType);

typedef struct Heap
{
	DataType* _array;
	int _size;
	int _capacity;
	Compare _con;
}Heap;


//用于元素比较的比较器
//大于
int Greater(DataType left, DataType right);

//小于
int Less(DataType left, DataType right);

//初始化堆
void InitHeap(Heap* hp, Compare com);

//创建堆
void CreatHeap(Heap* hp, DataType* array, int size, Compare com);

//在堆中插入值为data的元素
void InsertHeap(Heap* hp, DataType data);

//获取堆顶元素
DataType TopHeap(Heap* hp);

//判断是否为空堆
int EmptyHeap(Heap* hp);

//获取堆中元素个数
int SizeHeap(Heap* hp);

//删除堆顶元素
void DeletetHeap(Heap* hp);

//销毁堆
void DestroyHeap(Heap* hp);
