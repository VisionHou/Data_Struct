#include "BT.h"
#include<stdio.h>
#include<malloc.h>
#include<assert.h>

/////////////////////////////////
PBTNode  BuyBinTreeNode(BTDataType data)
{
	PBTNode pNewNode = (PBTNode)malloc(sizeof(BTNode));
	if (pNewNode == NULL)
	{
		assert(0);
		return NULL;
	}

	pNewNode->_data = data;
	pNewNode->_pLeft = NULL;
	pNewNode->_pRight = NULL;
	return pNewNode;
}

 _CreateBinTree(PBTNode* pRoot, BTDataType array[], int size, int* index, BTDataType invalid)
{
	assert(pRoot);
	if (*index < size&& invalid != array[*index])
	{
		//�������ڵ�
		*pRoot = BuyBinTreeNode(array[*index]);

		//�������ڵ��������
		++(*index);
		_CreateBinTree(&(*pRoot)->_pLeft, array, size, index, invalid);

		//�������ڵ��������
		++(*index);
		_CreateBinTree(&(*pRoot)->_pRight, array, size, index, invalid);

	}
}
void CreateBinTree(PBTNode pRoot, BTDataType array[], int size, BTDataType invalid )
{
	int index = 0;
	_CreateBinTree(pRoot, array, size, &index, invalid);
}

PBTNode CopyBinTree(PBTNode pRoot)
{
	PBTNode pNewRoot = NULL;
	
	if (pRoot)
	{
		//�������ڵ�
		pNewRoot = BuyBinTreeNode(pRoot->_data);

		//�������ڵ��������
		if (pRoot->_pLeft)
			pRoot->_pLeft = CopyBinTree(pRoot->_pLeft);

		//�������ڵ��������
		if (pRoot->_pRight)
			pRoot->_pRight = CopyBinTree(pRoot->_pRight);
	}

	return pNewRoot;
}

//ǰ�����
void PreOrder(PBTNode pRoot)
{
	//��->������->������
	if (pRoot)
	{
		printf("%c ", pRoot->_data);
		PreOrder(pRoot->_pLeft);
		PreOrder(pRoot->_pRight);		
	}
}

void PreOrderNor(PBTNode pRoot)
{
	Stack s;
	StackInit(&s);
	StackPush(&s, pRoot);
	PBTNode pCur;
	while (!StackEmpty(&s))
	{               
		pCur = StackTop(&s);
		StackPop(&s);
		printf("%c ",pCur->_data);
		if(pCur->_pRight)
			StackPush(&s, pCur->_pRight);
		if(pCur->_pLeft)
			StackPush(&s, pCur->_pLeft);
	}
}

//�������
void InOrder(PBTNode pRoot)
{
	//������->��->������
	if (pRoot)
	{
		InOrder(pRoot->_pLeft);
		printf("%c ", pRoot->_data);
		InOrder(pRoot->_pRight);
	}

}

void InOrderNor(PBTNode pRoot)
{
	if (pRoot == NULL)
		return;
	Stack s;
	StackInit(&s);
	PBTNode pCur=pRoot;


	while (pCur || !StackEmpty(&s))
	{
		//������ߵĽڵ�
		while (pCur)
		{
			StackPush(&s, pCur);
			pCur = pCur->_pLeft;
		}
		pCur = StackTop(&s);
		printf("%c ", pCur->_data);
		StackPop(&s);
		pCur = pCur->_pRight;
	}

}
//�������
void PostOrder(PBTNode pRoot)
{
	//������->������->��
	if (pRoot)
	{
		PostOrder(pRoot->_pLeft);
		PostOrder(pRoot->_pRight);
		printf("%c ", pRoot->_data);

	}
}
void PostOrderNor(PBTNode pRoot)
{
	if (pRoot == NULL)
		return;
	Stack s;
	StackInit(&s);
	PBTNode pCur = pRoot;
	PBTNode pPre = NULL;//������ʹ��Ľڵ�

	while (pCur || !StackEmpty(&s))
	{
		while (pCur)
		{
			StackPush(&s, pCur);
			pCur = pCur->_pLeft;
		}
		PBTNode Top = StackTop(&s);

		if (Top->_pRight == NULL||Top->_pRight==pPre)
		{
			printf("%c ", Top->_data);
			pPre = Top;
			StackPop(&s);
		}
		else
		{
			pCur = Top->_pRight;
		}
	}
}

//�������
void LevelOrder(PBTNode pRoot)
{
	if (pRoot == NULL)
		return;
	
	Queue q;
	QueueInit(&q);
	QueuePush(&q, pRoot);

	while (!QueueEmpty(&q))
	{
		PBTNode pCur = QueueFront(&q);
		printf("%c ", pCur->_data);
		QueuePop(&q);

		if (pCur->_pLeft)
			QueuePush(&q,pCur->_pLeft);

		if (pCur->_pRight)
			QueuePush(&q,pCur->_pRight);
	}

}
//���ٶ�����
void DestroyBinTree(PBTNode* pRoot)
{
	assert(pRoot);
	if (*pRoot)
	{
		//����������
		DestroyBinTree(&(*pRoot)->_pLeft);

		//����������
		DestroyBinTree(&(*pRoot)->_pRight);

		//���ٸ��ڵ�
		free(*pRoot);
		*pRoot = NULL;
	}
}

void Swap(PBTNode* pLeft, PBTNode* pRight)
{
	PBTNode temp;
	temp = *pLeft;
	*pLeft = *pRight;
	*pRight = temp;
}
//�ݹ�-�������ľ���
void MirrorBinTreeNode(PBTNode pRoot)
{
	if (pRoot == NULL || (pRoot->_pLeft == NULL && pRoot->_pRight == NULL))
		return;
	
	Swap(&pRoot->_pLeft, &pRoot->_pRight);
	MirrorBinTreeNode(pRoot->_pLeft);
	MirrorBinTreeNode(pRoot->_pRight);
}

void MirrorBinTreeNodeNor(PBTNode pRoot)
{
	if (pRoot == NULL || (pRoot->_pLeft == NULL && pRoot->_pRight == NULL))
		return;

	PBTNode pCur = pRoot;
	Queue q;
	QueueInit(&q);
	QueuePush(&q, pRoot);
	while (StackEmpty(&q))
	{
		Swap(&pCur->_pLeft, &pRoot->_pRight);
		if(pCur->_pLeft)
			QueuePush(&q, pRoot->_pLeft);
		if(pCur->_pRight)
			QueuePush(&q, pRoot->_pRight);

		QueuePop(&q);
	}
}

//�������нڵ����
int BinTreeSize(PBTNode pRoot)
{
	if (pRoot == NULL)
		return 0;

	if (pRoot->_pLeft == NULL && pRoot->_pRight == NULL)
		return 1;

	return BinTreeSize(pRoot->_pLeft) + BinTreeSize(pRoot->_pRight)+1;
}

//��������Ҷ�ӽڵ����
int BinTreeLeaf(PBTNode pRoot)
{
	if (pRoot == NULL)
		return 0;
	if (pRoot->_pLeft == NULL && pRoot->_pRight == NULL)
		return 1;

	return BinTreeLeaf(pRoot->_pLeft) + BinTreeLeaf(pRoot->_pRight);

}

//�������е�k��ڵ�ĸ���
int BinTreeKLevelNode(PBTNode pRoot, int k)
{
	if (pRoot == NULL || k < 0)
		return 0;

	if (k == 1)
		return 1;

	return BinTreeKLevelNode(pRoot->_pLeft,k-1) + BinTreeKLevelNode(pRoot->_pRight,k-1);
}

//�������ĸ߶�
int BinTreeHight(PBTNode pRoot)
{
	int leftHight = 0;
	int rightHight = 0;

	if (pRoot == NULL)
		return 0;
	if (pRoot->_pLeft == NULL || pRoot->_pRight == NULL)
		return 1;

	leftHight = BinTreeHight(pRoot->_pLeft);
	rightHight = BinTreeHight(pRoot->_pRight);

	return leftHight>rightHight?leftHight+1:rightHight+1;

}

//����ֵΪdata�Ľڵ�
PBTNode BinTreeFind(PBTNode pRoot, BTDataType data)
{
	PBTNode pCur = NULL;
	if (pRoot == NULL)
		return NULL;

	if (pRoot->_data == data)
		return pRoot;

	if (pCur = BinTreeFind(pRoot->_pLeft, data))
		return pCur;

	return BinTreeFind(pRoot->_pRight, data);
}

//�ڵ��Ƿ��ڶ�������
int IsNodeInBinTree(PBTNode pRoot, PBTNode pNode)
{
	if (pRoot == NULL||pNode==NULL)
		return 0;

	if (pRoot == pNode)
		return 1;

	if (IsNodeInBinTree(pRoot->_pLeft, pNode))
		return 1;

	return (IsNodeInBinTree(pRoot->_pRight, pNode));
}

//���һ�����Ƿ�Ϊ��ȫ������
int IsCompleteBinTree(PBTNode pRoot)
{
	if (pRoot == NULL)
		return 1;

	Queue q;
	QueueInit(&q);
	QueuePush(&q, pRoot);
	int flag = 0;

	while (!QueueEmpty(&q))
	{
		PBTNode Cur = QueueFront(&q);
		if (flag == 1)
		{
			if (Cur->_pLeft || Cur->_pRight)
				return 0;
		}
		else
		{
			//��������������
			if (Cur->_pLeft&&Cur->_pRight)
			{
				QueuePush(&q, Cur->_pLeft);
				QueuePush(&q, Cur->_pRight);
			}

			//����������
			else if (Cur->_pLeft)
			{
				QueuePush(&q, Cur->_pLeft);
				flag = 1;
			}

			//����������
			else if (Cur->_pRight)
				return 0;

			//��������
			else
				flag = 1;
		
		}
		QueuePop(&q);

	}
	return 1;
}
