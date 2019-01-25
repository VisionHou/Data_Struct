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
		//创建根节点
		*pRoot = BuyBinTreeNode(array[*index]);

		//创建根节点的左子树
		++(*index);
		_CreateBinTree(&(*pRoot)->_pLeft, array, size, index, invalid);

		//创建根节点的右子树
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
		//拷贝根节点
		pNewRoot = BuyBinTreeNode(pRoot->_data);

		//拷贝根节点的左子树
		if (pRoot->_pLeft)
			pRoot->_pLeft = CopyBinTree(pRoot->_pLeft);

		//拷贝根节点的右子树
		if (pRoot->_pRight)
			pRoot->_pRight = CopyBinTree(pRoot->_pRight);
	}

	return pNewRoot;
}

//前序遍历
void PreOrder(PBTNode pRoot)
{
	//根->左子树->右子树
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

//中序遍历
void InOrder(PBTNode pRoot)
{
	//左子树->根->右子树
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
		//找最左边的节点
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
//后序遍历
void PostOrder(PBTNode pRoot)
{
	//左子树->右子树->根
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
	PBTNode pPre = NULL;//最近访问过的节点

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

//层序遍历
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
//销毁二叉树
void DestroyBinTree(PBTNode* pRoot)
{
	assert(pRoot);
	if (*pRoot)
	{
		//销毁左子树
		DestroyBinTree(&(*pRoot)->_pLeft);

		//销毁右子树
		DestroyBinTree(&(*pRoot)->_pRight);

		//销毁根节点
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
//递归-二叉树的镜像
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

//二叉树中节点个数
int BinTreeSize(PBTNode pRoot)
{
	if (pRoot == NULL)
		return 0;

	if (pRoot->_pLeft == NULL && pRoot->_pRight == NULL)
		return 1;

	return BinTreeSize(pRoot->_pLeft) + BinTreeSize(pRoot->_pRight)+1;
}

//二叉树中叶子节点个数
int BinTreeLeaf(PBTNode pRoot)
{
	if (pRoot == NULL)
		return 0;
	if (pRoot->_pLeft == NULL && pRoot->_pRight == NULL)
		return 1;

	return BinTreeLeaf(pRoot->_pLeft) + BinTreeLeaf(pRoot->_pRight);

}

//二叉树中第k层节点的个数
int BinTreeKLevelNode(PBTNode pRoot, int k)
{
	if (pRoot == NULL || k < 0)
		return 0;

	if (k == 1)
		return 1;

	return BinTreeKLevelNode(pRoot->_pLeft,k-1) + BinTreeKLevelNode(pRoot->_pRight,k-1);
}

//二叉树的高度
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

//查找值为data的节点
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

//节点是否在二叉树中
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

//检测一棵树是否为完全二叉树
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
			//左右子树都存在
			if (Cur->_pLeft&&Cur->_pRight)
			{
				QueuePush(&q, Cur->_pLeft);
				QueuePush(&q, Cur->_pRight);
			}

			//左子树存在
			else if (Cur->_pLeft)
			{
				QueuePush(&q, Cur->_pLeft);
				flag = 1;
			}

			//右子树存在
			else if (Cur->_pRight)
				return 0;

			//都不存在
			else
				flag = 1;
		
		}
		QueuePop(&q);

	}
	return 1;
}
