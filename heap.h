#pragma once

typedef int DataType;

#if 0
typedef struct Heap
{
	DataType* _array;//�����Ŷ��нڵ�
	int _size;
	int _capacity;
}Heap;

//������
void CreatHeap(Heap* hp, DataType* array, int size);

//�ڶ��в���ֵΪdata��Ԫ��
void InsertHeap(Heap* hp, DataType data);

//��ȡ�Ѷ�Ԫ��
DataType TopHeap(Heap* hp);

//�ж��Ƿ�Ϊ�ն�
int EmptyHeap(Heap* hp);

//��ȡ����Ԫ�ظ���
int SizeHeap(Heap* hp);

//ɾ���Ѷ�Ԫ��
void DeletetHeap(Heap* hp);

//���ٶ�
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


//����Ԫ�رȽϵıȽ���
//����
int Greater(DataType left, DataType right);

//С��
int Less(DataType left, DataType right);

//��ʼ����
void InitHeap(Heap* hp, Compare com);

//������
void CreatHeap(Heap* hp, DataType* array, int size, Compare com);

//�ڶ��в���ֵΪdata��Ԫ��
void InsertHeap(Heap* hp, DataType data);

//��ȡ�Ѷ�Ԫ��
DataType TopHeap(Heap* hp);

//�ж��Ƿ�Ϊ�ն�
int EmptyHeap(Heap* hp);

//��ȡ����Ԫ�ظ���
int SizeHeap(Heap* hp);

//ɾ���Ѷ�Ԫ��
void DeletetHeap(Heap* hp);

//���ٶ�
void DestroyHeap(Heap* hp);
