
///////////////////////��̬//////////////////
#if 0
#define Max_Size 1000
typedef unsigned int size_t;
typedef int DataType;

typedef struct SeqList
{
	DataType _array[Max_Size];//�洢�ռ�
	int _size;//��ЧԪ�صĸ���
}SeqList,*pSeqList;
 

//��ʼ��
void SeqListInit(pSeqList ps);
//β��
void SeqListPushBack(pSeqList ps,DataType data);
//βɾ
void SeqListPopBack(pSeqList ps);
//ͷ��
void SeqListPushFront(pSeqList ps, DataType data);
//ͷɾ
void SeqListPopFront(pSeqList ps);
//����ָ��λ��Ԫ��
void SeqListInsert(pSeqList ps, size_t pos,DataType data);
//���ָ��λ��Ԫ��
void SeqListErase(pSeqList ps, size_t pos);
//����Ԫ��
int SeqListFind(pSeqList ps,  DataType data);
//ɾ��Ԫ��
void SeqListRemove(pSeqList ps, DataType data);
//ɾ�������ض�Ԫ��
void SeqListRemoveAll(pSeqList ps, DataType data);
//�п�
int SeqListEmpty(pSeqList ps );
//��Ч����
int SeqListSize(pSeqList ps);
//��ӡ
void SeqLisPrint(pSeqList ps);
#endif

///////////////////////��̬///////////////
typedef unsigned int size_t;
typedef int DataType;

typedef struct SeqListD
{
	DataType* _array;
	size_t _size;//��ЧԪ�صĸ���
	size_t _capacity;//��ЧԪ�صĸ���
}SeqListD, *pSeqListD;

//��ʼ��
void SeqListDInit(pSeqListD ps);
//β��
void SeqListDPushBack(pSeqListD ps, DataType data);
//βɾ
void SeqListDPopBack(pSeqListD ps);
//�п�
int SeqListDEmpty(pSeqListD ps);
//��Ч����
int SeqListDSize(pSeqListD ps);
//���
void SeqListDClear(pSeqListD ps);
//������С
int SeqListDCapacity(pSeqListD ps);
//����
void SeqListDDestory(pSeqListD ps);
//������� ����
int CheckCapacity(pSeqListD ps);
//��ӡ
void SeqLisDPrint(pSeqListD ps);




