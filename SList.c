#include"SList.h"
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>

#if 0
void SeqListInit(pSeqList ps)
{
	if (ps == NULL)
		return;
	ps->_size = 0;
}

void SeqListPushBack(pSeqList ps, DataType data)
{
	if (ps == NULL)
		return;
	if (ps->_size == Max_Size)
	{
		printf("顺序表满了!!!\n");
		return;
	}
	ps->_array[ps->_size++] = data;
}

void SeqListPopBack(pSeqList ps)
{
	if (SeqListEmpty(ps))
		return;
	ps->_size--;
}

void SeqListPushFront(pSeqList ps, DataType data)
{
	assert(ps);
	if (ps->_size == Max_Size)
	{
		printf("顺序表满了!!!\n");
		return;
	}
	//从后往前搬移元素
	for (int i = ps->_size; i > 0; i--)
	{
		ps->_array[i] = ps->_array[i - 1];
	}
	//插入元素
	ps->_array[0] = data;
	ps->_size++;
}

void SeqListPopFront(pSeqList ps)
{
	assert(ps);
	if (SeqListEmpty(ps))
		return;
	//从前往后搬元素
	for (int i = 0; i < ps->_size-1; i++)
	{
		ps->_array[i] = ps->_array[i + 1];
	}
	ps->_size--;
}

void SeqListInsert(pSeqList ps, size_t pos, DataType data)
{
	assert(ps);
	if (ps->_size == Max_Size)
	{
		printf("顺序表满了!!!\n");
		return;
	}
	if (ps->_size > pos)
	{
		//从后往前搬移元素
		for (int i = ps->_size; i > pos; i--)
		{
			ps->_array[i] = ps->_array[i - 1];
		}
		//插入元素
		ps->_array[pos] = data;
		ps->_size++;
	}

}

//删除指定位置的元素
void SeqListErase(pSeqList ps, size_t pos)
{
	assert(ps);
	for (int i =pos;i<ps->_size-1;i++)
	{
		ps->_array[i] = ps->_array[i + 1];
	}
	ps->_size--;
}

int SeqListFind(pSeqList ps, DataType data)
{
	assert(ps);
	for (int i = 0; i < ps->_size ; i++)
	{
		if (ps->_array[i] == data);
		printf("找到了\n");
		return i;
	}
	printf("找不到\n");
	return -1;
}

//删除元素
void SeqListRemove(pSeqList ps, DataType data)
{
	SeqListErase(ps, SeqListFind(ps, data));
}

//删除所有指定元素
void SeqListRemoveAll(pSeqList ps, DataType data)
{
	assert(ps);
	int count = 0;

	for (int i = 0; i < ps->_size; i++)
	{
		if (ps->_array[i] == data)
			count++;
		else
		{
			//向前覆盖法
			ps->_array[i - count] = ps->_array[i];
		}
	}
	ps->_size -= count;
}

int SeqListEmpty(pSeqList ps)
{
	assert(ps);
	//返回0是非空，否则空
	return ps->_size == 0;
}

int SeqListSize(pSeqList ps)
{
	return ps->_size;
}

void SeqLisPrint(pSeqList ps)
{
	for (int i = 0; i < ps->_size; i++)
	{
		printf("%d  ", ps->_array[i]);
	}
	printf("\n");
}
#endif

//初始化
void SeqListDInit(pSeqListD ps)
{
	if (ps == NULL)
		return;
	ps->_array = (DataType*)malloc(3 * sizeof(DataType));
	if (ps->_array == NULL)
		return;

	ps->_capacity = 3;
	ps->_size = 0;
}

//尾插
void SeqListDPushBack(pSeqListD ps, DataType data)
{
	if (ps == NULL)
		return;
	if (!CheckCapacity(&ps))
		return;
	ps->_array[ps->_size++] = data;
}

//尾删
void SeqListDPopBack(pSeqListD ps)
{
	if (SeqListDEmpty(&ps))
		return;
	ps->_size--;
}

//判空
int SeqListDEmpty(pSeqListD ps)
{
	return ps->_size == 0;
}

//有效个数
int SeqListDSize(pSeqListD ps)
{
	return ps->_size;
}

//清除
void SeqListDClear(pSeqListD ps)
{
	ps->_size = 0;
}

//容量大小
int SeqListDCapacity(pSeqListD ps)
{
	return ps->_capacity;

}

//销毁
void SeqListDDestory(pSeqListD ps)
{
	if (ps->_array)
	{
		free(ps->_array);
		ps->_capacity = 0;
		ps->_size = 0;
	}
}

//检测容量 扩容
int CheckCapacity(pSeqListD ps)
{
	if (ps->_capacity == NULL)
		return 0;

	if (ps->_size == ps->_capacity)
	{
		//扩容
		size_t newcapacity = ps->_capacity * 2;
		DataType* tmp = (DataType*)malloc(newcapacity * sizeof(DataType));
		if (tmp == NULL)
			return;
		
		//原空间的元素搬移到新空间
		memcpy(tmp, ps->_array, ps->_size * sizeof(DataType));

		//释放旧空间
		free(ps->_array);

		ps->_array = tmp;
		ps->_capacity = newcapacity;
	}
	return 1;
}

void SeqLisDPrint(pSeqListD ps)
{
	for (int i = 0; i < ps->_size; i++)
	{
		printf("%d  ", ps->_array[i]);
	}
	printf("\n");
}