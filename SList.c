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
		printf("˳�������!!!\n");
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
		printf("˳�������!!!\n");
		return;
	}
	//�Ӻ���ǰ����Ԫ��
	for (int i = ps->_size; i > 0; i--)
	{
		ps->_array[i] = ps->_array[i - 1];
	}
	//����Ԫ��
	ps->_array[0] = data;
	ps->_size++;
}

void SeqListPopFront(pSeqList ps)
{
	assert(ps);
	if (SeqListEmpty(ps))
		return;
	//��ǰ�����Ԫ��
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
		printf("˳�������!!!\n");
		return;
	}
	if (ps->_size > pos)
	{
		//�Ӻ���ǰ����Ԫ��
		for (int i = ps->_size; i > pos; i--)
		{
			ps->_array[i] = ps->_array[i - 1];
		}
		//����Ԫ��
		ps->_array[pos] = data;
		ps->_size++;
	}

}

//ɾ��ָ��λ�õ�Ԫ��
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
		printf("�ҵ���\n");
		return i;
	}
	printf("�Ҳ���\n");
	return -1;
}

//ɾ��Ԫ��
void SeqListRemove(pSeqList ps, DataType data)
{
	SeqListErase(ps, SeqListFind(ps, data));
}

//ɾ������ָ��Ԫ��
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
			//��ǰ���Ƿ�
			ps->_array[i - count] = ps->_array[i];
		}
	}
	ps->_size -= count;
}

int SeqListEmpty(pSeqList ps)
{
	assert(ps);
	//����0�Ƿǿգ������
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

//��ʼ��
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

//β��
void SeqListDPushBack(pSeqListD ps, DataType data)
{
	if (ps == NULL)
		return;
	if (!CheckCapacity(&ps))
		return;
	ps->_array[ps->_size++] = data;
}

//βɾ
void SeqListDPopBack(pSeqListD ps)
{
	if (SeqListDEmpty(&ps))
		return;
	ps->_size--;
}

//�п�
int SeqListDEmpty(pSeqListD ps)
{
	return ps->_size == 0;
}

//��Ч����
int SeqListDSize(pSeqListD ps)
{
	return ps->_size;
}

//���
void SeqListDClear(pSeqListD ps)
{
	ps->_size = 0;
}

//������С
int SeqListDCapacity(pSeqListD ps)
{
	return ps->_capacity;

}

//����
void SeqListDDestory(pSeqListD ps)
{
	if (ps->_array)
	{
		free(ps->_array);
		ps->_capacity = 0;
		ps->_size = 0;
	}
}

//������� ����
int CheckCapacity(pSeqListD ps)
{
	if (ps->_capacity == NULL)
		return 0;

	if (ps->_size == ps->_capacity)
	{
		//����
		size_t newcapacity = ps->_capacity * 2;
		DataType* tmp = (DataType*)malloc(newcapacity * sizeof(DataType));
		if (tmp == NULL)
			return;
		
		//ԭ�ռ��Ԫ�ذ��Ƶ��¿ռ�
		memcpy(tmp, ps->_array, ps->_size * sizeof(DataType));

		//�ͷžɿռ�
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