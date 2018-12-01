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
	//childʼ�ձ�����Һ�����С�ĺ���
	int child = parent * 2 + 1;
	int size = hp->_size;

	while (child < size)
	{
		//�����Һ�����С�ĺ��ӣ��Һ��ӿ��ܲ�����
		if (child + 1 < size&&hp->_array[child] > hp->_array[child + 1])
		{
			child += 1;
		}

		//��С������˫�׽��бȽϣ�����˫�״��򽻻�
		//��������ܲ�����ѵ����ʣ���������
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
		//�����Ƿ��˫��С������
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
	//���������¿ռ�
	hp->_array = (DataType*)malloc(sizeof(DataType)*size);
	if (hp->_array == NULL)
	{
		assert(0);
		return 0;
	}

	//��������Ԫ�ط������
	for (int i= 0 ; i < size; ++i)
	{
		hp->_array[i] = array[i];
	}
	hp->_capacity = size;
	hp->_size = size;

	//�ѵ���(���µ���)
	int root = (size - 2) >> 1;//�ӵ�����һ����Ҷ�ӽڵ�λ�ÿ�ʼ����
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
		//���ռ�
		int newcapacity = 2 * hp->_capacity;
		DataType* tmp = (DataType*)malloc(sizeof(newcapacity));
		if (tmp == NULL)
		{
			assert(0);
			return;
		}

		//����Ԫ��
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

	//�ȼ���Ƿ���Ҫ����
	_CheckCapacity(hp);

	//����Ԫ��
	hp->_array[hp->_size++] = data;

	//����Ԫ�غ��п����ƻ���
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

//ɾ���Ѷ�Ԫ��
void DeletetHeap(Heap* hp)
{
	if (EmptyHeap(hp))
		return;

	//�ö������һ��Ԫ�غͶѶ�Ԫ�ؽ���
	//ɾ�����һ��Ԫ��(��Ԫ�ظ�����һ)
	hp->_array[0] = hp->_array[hp->_size - 1];
	hp->_size--;

	//�ѵ����ʿ��ܱ��ƻ�
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
//����
int Greater(DataType left, DataType right)
{
	return left > right;
}

//С��
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
	//childʼ�ձ�����Һ�����С�ĺ���
	int child = parent * 2 + 1;
	int size = hp->_size;

	while (child < size)
	{
		//�����Һ�����С�ĺ��ӣ��Һ��ӿ��ܲ�����
		if (child + 1 < size && hp->_con(hp->_array[child+1] , hp->_array[child]))
		{
			child += 1;
		}

		//��С������˫�׽��бȽϣ�����˫�״��򽻻�
		//��������ܲ�����ѵ����ʣ���������
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
		//�����Ƿ��˫��С������
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

//��ʼ����
void InitHeap(Heap* hp, Compare com)
{
	//����ռ�
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

	//��������ռ�
	hp->_array = (DataType*)malloc(sizeof(DataType)*size);
	if (hp->_array == NULL)
	{
		assert(0);
		return 0;
	}

	//��������Ԫ�ط������
	for (int i = 0; i < size; ++i)
	{
		hp->_array[i] = array[i];
	}
	hp->_capacity = size;
	hp->_size = size;
	hp->_con = com;

	//�ѵ���(���µ���)
	int root = (size - 2) >> 1;//�ӵ�����һ����Ҷ�ӽڵ�λ�ÿ�ʼ����
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
		//���ռ�
		int newcapacity = 2 * hp->_capacity;
		DataType* tmp = (DataType*)malloc(sizeof(newcapacity));
		if (tmp == NULL)
		{
			assert(0);
			return;
		}

		//����Ԫ��
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

	//�ȼ���Ƿ���Ҫ����
	_CheckCapacity(hp);

	//����Ԫ��
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
	//����:������һ����Ҷ�ӽڵ���������ڵ�
	int root = ((size - 2) >> 1);
	int end = size - 1;
	for (; root >= 0; --root)
	{
		HeapAdjust(array,size,root);
	}
	//������
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
