#include"heap.h"
#include<stdio.h>
#include<windows.h>
#include<assert.h>
#if 0
void Swap(DataType* pLeft, DataType* pRight)
{
	DataType tmp;
	assert(pLeft);
	assert(pRight);

	tmp = *pLeft;
	*pLeft = *pRight;
	*pRight = tmp;
}

void _AdjustDown(Heap* hp, int parent)
{
	//child始终标记左右孩子最小的孩子
	int child = parent * 2 + 1;
	int size = hp->_size;

	while (child < size)
	{
		//找左右孩子最小的孩子，右孩子可能不存在
		if (child + 1 < size&&hp->_array[child] > hp->_array[child + 1])
		{
			child += 1;
		}

		//较小孩子与双亲进行比较，若比双亲大则交换
		//交换后可能不满足堆的性质，继续调整
		if (hp->_array[parent] > hp->_array[child])
		{
			Swap(&hp->_array[parent], &hp->_array[child]);
			child = parent * 2 + 1;
		}
		else
			return;
	}
}

void _AdjustUp(Heap* hp, int child)
{
	int parent = (child - 1) >> 1;

	while (child)
	{
		//孩子是否比双亲小，交换
		if (hp->_array[parent] > hp->_array[child])
		{
			Swap(&hp->_array[parent], &hp->_array[child]);
			child = parent;
			parent = (child - 1) >> 1;
		}
		else
			return;
	}
}
void CreatHeap(Heap* hp, DataType* array, int size)
{
	//给堆申请新空间
	hp->_array = (DataType*)malloc(sizeof(DataType)*size);
	if (hp->_array == NULL)
	{
		assert(0);
		return 0;
	}

	//将数组中元素放入堆中
	for (int i= 0 ; i < size; ++i)
	{
		hp->_array[i] = array[i];
	}
	hp->_capacity = size;
	hp->_size = size;

	//堆调整(向下调整)
	int root = (size - 2) >> 1;//从倒数第一个非叶子节点位置开始调整
	for (; root >= 0; --root)
	{
		_AdjustDown(hp, root);
	}
}

void _CheckCapacity(Heap* hp)
{
	assert(hp);
	if (hp->_size == hp->_capacity)
	{
		//开空间
		int newcapacity = 2 * hp->_capacity;
		DataType* tmp = (DataType*)malloc(sizeof(newcapacity));
		if (tmp == NULL)
		{
			assert(0);
			return;
		}

		//搬移元素
		for (int i = 0; i < hp->_size; ++i)
			tmp[i] = hp->_array[i];

		free(hp->_array);
		hp->_array = tmp;
		hp->_capacity = newcapacity;
	}
}


void InsertHeap(Heap* hp, DataType data)
{
	int child = 0;
	int parent = 0;
	assert(hp);

	//先检测是否需要增容
	_CheckCapacity(hp);

	//插入元素
	hp->_array[hp->_size++] = data;

	//插入元素后有可能破坏堆
	_AdjustUp(hp, hp->_size - 1);
}

DataType TopHeap(Heap* hp)
{
	assert(hp);
	return hp->_array[0];
}

int EmptyHeap(Heap* hp)
{
	assert(hp);
	return 0 == hp->_size;
}

int SizeHeap(Heap* hp)
{
	assert(hp);
	return hp->_size;
}

//删除堆顶元素
void DeletetHeap(Heap* hp)
{
	if (EmptyHeap(hp))
		return;

	//用堆中最后一个元素和堆顶元素交换
	//删除最后一个元素(堆元素个数减一)
	hp->_array[0] = hp->_array[hp->_size - 1];
	hp->_size--;

	//堆的性质可能被破坏
	_AdjustDown(hp, 0);
}


void DestroyHeap(Heap* hp)
{
	assert(hp);
	if (hp->_array)
	{
		free(hp->_array);
		hp->_capacity = 0;
		hp->_size = 0;
	}
}

#endif
//大于
int Greater(DataType left, DataType right)
{
	return left > right;
}

//小于
int Less(DataType left, DataType right)
{
	return left < right;
}
void Swap(DataType* pLeft, DataType* pRight)
{
	DataType tmp;
	assert(pLeft);
	assert(pRight);

	tmp = *pLeft;
	*pLeft = *pRight;
	*pRight = tmp;
}

void _AdjustDown(Heap* hp, int parent)
{
	//child始终标记左右孩子最小的孩子
	int child = parent * 2 + 1;
	int size = hp->_size;

	while (child < size)
	{
		//找左右孩子最小的孩子，右孩子可能不存在
		if (child + 1 < size && hp->_con(hp->_array[child+1] , hp->_array[child]))
		{
			child += 1;
		}

		//较小孩子与双亲进行比较，若比双亲大则交换
		//交换后可能不满足堆的性质，继续调整
		if (hp->_con(hp->_array[parent] , hp->_array[child]))
		{
			Swap(&hp->_array[parent], &hp->_array[child]);
			child = parent * 2 + 1;
		}
		else
			return;
	}
}

void _AdjustUp(Heap* hp, int child)
{
	int parent = (child - 1) >> 1;

	while (child)
	{
		//孩子是否比双亲小，交换
		if (hp->_con(hp->_array[parent] , hp->_array[child]))
		{
			Swap(&hp->_array[parent], &hp->_array[child]);
			child = parent;
			parent = (child - 1) >> 1;
		}
		else
			return;
	}
}

//初始化堆
void InitHeap(Heap* hp, Compare com)
{
	//申请空间
	hp->_array = (DataType*)malloc(sizeof(DataType) * 3);
	if (NULL == hp->_array)
	{
		assert(0);
		return;
	}
	hp->_capacity = 3;
	hp->_size = 0;
	hp->_con = com;
}


void CreatHeap(Heap* hp, DataType* array, int size, Compare com)
{
	if (hp == NULL)
		return;

	//给堆申请空间
	hp->_array = (DataType*)malloc(sizeof(DataType)*size);
	if (hp->_array == NULL)
	{
		assert(0);
		return 0;
	}

	//将数组中元素放入堆中
	for (int i = 0; i < size; ++i)
	{
		hp->_array[i] = array[i];
	}
	hp->_capacity = size;
	hp->_size = size;
	hp->_con = com;

	//堆调整(向下调整)
	int root = (size - 2) >> 1;//从倒数第一个非叶子节点位置开始调整
	for (; root >= 0; --root)
	{
		_AdjustDown(hp, root);
	}
}

void _CheckCapacity(Heap* hp)
{
	assert(hp);
	if (hp->_size == hp->_capacity)
	{
		//开空间
		int newcapacity = 2 * hp->_capacity;
		DataType* tmp = (DataType*)malloc(sizeof(newcapacity));
		if (tmp == NULL)
		{
			assert(0);
			return;
		}

		//搬移元素
		for (int i = 0; i < hp->_size; ++i)
			tmp[i] = hp->_array[i];

		free(hp->_array);
		hp->_array = tmp;
		hp->_capacity = newcapacity;
	}
}

void InsertHeap(Heap* hp, DataType data)
{
	int child = 0;
	int parent = 0;
	assert(hp);

	//先检测是否需要增容
	_CheckCapacity(hp);

	//插入元素
	hp->_array[hp->_size++] = data;

	_AdjustUp(hp, hp->_size - 1);
}

DataType TopHeap(Heap* hp)
{
	assert(hp);
	return hp->_array[0];
}

int EmptyHeap(Heap* hp)
{
	assert(hp);
	return 0 == hp->_size;
}

int SizeHeap(Heap* hp)
{
	assert(hp);
	return hp->_size;
}


void DeletetHeap(Heap* hp)
{
	if (EmptyHeap(hp))
		return;

	hp->_array[0] = hp->_array[hp->_size - 1];
	hp->_size--;

	_AdjustDown(hp, 0);
}


void DestroyHeap(Heap* hp)
{
	assert(hp);
	if (hp->_array)
	{
		free(hp->_array);
		hp->_capacity = 0;
		hp->_size = 0;
	}
}
void TestHeap()
{
	Heap  hp;
	int arr[] = { 53, 17, 78, 9, 45, 65, 87, 23, 31 };
	//CreatHeap(&hp, arr, sizeof(arr) / sizeof(arr[0]));
	CreatHeap(&hp, arr, sizeof(arr) / sizeof(arr[0]), Less);
	InsertHeap(&hp, 5);
	DeletetHeap(&hp);
	DestroyHeap(&hp);
}

void HeapAdjust(int array[], int size, int parent)
{
	int child = parent* 2+1;

	while (child < size)
	{
		if (child + 1 < size&&array[child] > array[child + 1])
			child += 1;

		if (array[parent] > array[child])
		{
			Swap(&array[parent], &array[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			return;
	}
}

void HeapSort(int array[],int size)
{
	//建堆:倒数第一个非叶子节点调整到根节点
	int root = ((size - 2) >> 1);
	int end = size - 1;
	for (; root >= 0; --root)
	{
		HeapAdjust(array,size,root);
	}
	//堆排序
	while (end)
	{
		Swap(&array[end], &array[0]);
		HeapAdjust(array, end, 0);
		--end;
	}
}

void TestHeapSort()
{
	int array[] = { 3 ,9 ,4,1,2,8,6,7,5,0 };
	HeapSort(array, sizeof(array) / sizeof(array[0]));
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", array[i]);
	}
}
int main()
{
	//TestHeap();
	TestHeapSort();
	system("pause");
	return 0;
}
