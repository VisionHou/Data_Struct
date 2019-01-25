#pragma once
extern struct BTNode;
typedef struct BTNode* DataType;
typedef struct Node
{
	DataType data;
	struct Node* _pNext;
}Node, *pNode;

typedef struct Queue
{
	pNode _pHead;
	pNode _pTail;

}Queue;
//�Ƚ��ȳ�

void QueueInit(Queue* q);
pNode BuyQueueNode(DataType data);
void QueuePush(Queue* q, DataType data);
void QueuePop(Queue* q);
DataType QueueFront(Queue* q);
DataType QueueBack(Queue* q);
int QueueSize(Queue* q);
int QueueEmpty(Queue* q);
void QueuePrint(Queue* q);
#include<stdio.h>
#include<assert.h>
#include<windows.h>
#include<string.h>

#define Max_Size 100


typedef struct Stack
{
	DataType _array[Max_Size];//������
	int _top;//��ЧԪ�ظ���(��ʾջ��λ��)
}Stack;

//��ʼ��
void StackInit(Stack* s);

//��ջ
void StackPush(Stack* s, DataType data);

//��ջ
void StackPop(Stack* s);

//��ȡջ��Ԫ��
DataType StackTop(Stack* s);

//��ȡ��ЧԪ�صĸ���
int StackSize(Stack* s);

//ջ�Ƿ�Ϊ��
int StackEmpty(Stack* s);

//��ӡջ
void PrintStack(Stack* s);


typedef char BTDataType;
typedef struct BinTreeNode
{
	struct BinTreeNode* _pLeft;//������
	struct BinTreeNode* _pRight;//������
	BTDataType _data;//��ǰ�ڵ�����
}BTNode,*PBTNode;


//����������
void CreateBinTree(PBTNode pRoot, BTDataType array[], int size, BTDataType invalid);

//����������
PBTNode CopyBinTree(PBTNode pRoot);

//�ݹ�-ǰ�����
void PreOrder(PBTNode pRoot);

//�ݹ�-�������
void InOrder(PBTNode pRoot);

//�ݹ�-�������
void PostOrder(PBTNode pRoot);

//�������
void LevelOrder(PBTNode pRoot);

//���ٶ�����
void DestroyBinTree(PBTNode* pRoot);

//�ݹ�-�������ľ���
void MirrorBinTreeNode(PBTNode pRoot);

//�������нڵ����
int BinTreeSize(PBTNode pRoot);

//��������Ҷ�ӽڵ����
int BinTreeLeaf(PBTNode pRoot);

//�������е�k��ڵ�ĸ���
int BinTreeKLevelNode(PBTNode pRoot, int k);

//�������ĸ߶�
int BinTreeHight(PBTNode pRoot);

//����ֵΪdata�Ľڵ�
PBTNode BinTreeFind(PBTNode pRoot, BTDataType data);

//�ڵ��Ƿ��ڶ�������
int IsNodeInBinTree(PBTNode pRoot, PBTNode pNode);

//���һ�����Ƿ�Ϊ��ȫ������
int IsCompleteBinTree(PBTNode pRoot);
