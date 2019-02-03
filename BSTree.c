#include"BSTree.h"
#include<assert.h>
#include<malloc.h>
#include<stdio.h>

#if 0
void InitBSTree(BSTreeNode** pRoot)
{
	assert(pRoot);
	*pRoot = NULL;
}

BSTreeNode* BuyBSTreeNode(DataType data)
{
	BSTreeNode* NewNode = (BSTreeNode*)malloc(sizeof(BSTreeNode));
	if (NewNode == NULL)
	{
		assert(0);
		return;
	}

	NewNode->_data = data;
	NewNode->_pLeft = NULL;
	NewNode->_pRight = NULL;

	return NewNode;
}

//����ֵΪdata��Ԫ��
void InsertBSTree(BSTreeNode** pRoot, DataType data)
{
	assert(pRoot);

	BSTreeNode* pCur = NULL;
	BSTreeNode* pParent = NULL;

	//��Ϊ�գ�ֱ�Ӳ���
	if (*pRoot == NULL)
	{
		*pRoot = BuyBSTreeNode(data);
		return;
	}
	
	//�����գ����ҵ�����λ�ã��ýڵ㲻����ʱ����
	pCur = *pRoot;
	while (pCur)
	{
		if (pCur->_data > data)
		{
			pParent = pCur;
			pCur = pParent->_pLeft;
		}
		else if (pCur->_data < data)
		{
			pParent = pCur;
			pCur = pParent->_pRight;
		}
		else
			return;
	}

	pCur = BuyBSTreeNode(data);
	if (data > pParent->_data)
		pParent->_pRight = pCur;
	else
		pParent->_pLeft = pCur;

}

//ɾ��ֵΪdata�Ľڵ�
void DeleteBSTree(BSTreeNode** pRoot, DataType data)
{
	assert(pRoot);

	BSTreeNode* pDel = *pRoot;
	BSTreeNode* pParent = NULL;

	//�ҵ��ýڵ�λ��
	while (pDel)
	{
		if (data > pDel->_data)
		{
			pParent = pDel;
			pDel = pDel->_pRight;
		}
		else if (data < pDel->_data)
		{
			pParent = pDel;
			pDel = pDel->_pLeft;
		}
		else
			break;
	}
	
	if (pDel == NULL)
		return;
	
	//Ҷ�ӽڵ��ֻ������������
	if (!pDel->_pRight)
	{
		//�Ǹ��ڵ㣬�ø��ڵ�ָ����ڵ������
		if (pDel == pRoot)
			pRoot = pDel->_pLeft;

		//���Ǹ��ڵ㣬��˫�׽ڵ�����ӣ���˫�׵�������ָ���ɾ���ڵ��������
		//��˫�׵��Һ��ӣ���˫�׵���ָ��ָ���ɾ���ڵ��������
		if(pDel==pParent->_pLeft)
			pParent->_pLeft = pDel->_pLeft;
		if (pDel == pParent->_pRight)
			pParent->_pRight = pDel->_pLeft;
		free(pDel);
	}

	//ֻ������������
	if (!pDel->_pLeft)
	{
		//�Ǹ��ڵ㣬�ø��ڵ�ָ����ڵ���Һ���
		if (pDel == pRoot)
			pRoot = pDel->_pRight;
		//���Ǹ��ڵ㣬��˫�����ӣ���˫�׵���ָ��ָ���ɾ���ڵ��������
		//��˫�׵��Һ��ӣ���˫�׵���ָ��ָ���ɾ���ڵ��������
		if (pDel == pParent->_pLeft)
			pParent->_pLeft = pDel->_pRight;
		if (pDel == pParent->_pRight)
			pParent->_pRight = pDel->_pRight;

		free(pDel);
	}

	//�������������ڣ�������������С�Ľڵ�Ϊ����ڵ�Ȼ��ɾ������ڵ�
	if (pDel->_pLeft&&pDel->_pRight)
	{
		BSTreeNode* replace = pDel->_pRight;
		while (replace->_pLeft)
		{
			pParent = replace;
			replace = replace->_pLeft;
		}

		pDel->_data = replace->_data;
		if (replace == pParent->_pLeft)
			pParent->_pLeft = replace->_pRight;
		
		else
			pDel->_pRight = replace->_pRight;

		free(replace);

	}

}

//����ֵΪdata�Ľڵ�
int FindBSTree(BSTreeNode* pRoot, DataType data)
{
	BSTreeNode* pCur = pRoot;

	while (pCur)
	{
		if (pCur->_data > data)
			pCur = pCur->_pLeft;

		else if (pCur->_data < data)
			pCur = pCur->_pRight;
		
		else
			return 1;

	}
	return 0;
}

//�����������������
void InOrder(BSTreeNode* pRoot)
{
	//���������������������һ����������
	if (pRoot == NULL)
		return;

	InOrder(pRoot->_pLeft);
	printf("%d ", pRoot->_data);
	InOrder(pRoot->_pRight);

}

//���ٶ���������
void Destroy(BSTreeNode** pRoot)
{
	assert(pRoot);
	if (*pRoot)
	{
		Destroy((*pRoot)->_pLeft);
		Destroy((*pRoot)->_pRight);
		free(*pRoot);
		*pRoot = NULL;

	}
}

#endif


//��ʼ������������
void InitBSTree(BSTreeNode** pRoot)
{
	assert(pRoot);
	pRoot = NULL;
}

BSTreeNode* BuyBSTreeNode(DataType data)
{
	BSTreeNode* NewNode = (BSTreeNode*)malloc(sizeof(BSTreeNode));
	if (NewNode == NULL)
	{
		assert(0);
		return;
	}

	NewNode->_data = data;
	NewNode->_pLeft = NULL;
	NewNode->_pRight = NULL;

	return NewNode;
}
//����ֵΪdata��Ԫ��
int InsertBSTree(BSTreeNode** pRoot, DataType data)
{
	if (*pRoot == NULL)
	{
		*pRoot = BuyBSTreeNode(data);
		return 1;
	}
	else
	{
		 if (data < (*pRoot)->_data)
			return InsertBSTree(&(*pRoot)->_pLeft, data);
		else if (data > (*pRoot)->_data)
			return InsertBSTree(&(*pRoot)->_pRight, data);
		else
			return 0;
	}
}

//ɾ��ֵΪdata�Ľڵ�
int DeleteBSTree(BSTreeNode** pRoot, DataType data)
{
	if (*pRoot == NULL)
		return 0;

	if(data<(*pRoot)->_data)
		DeleteBSTree(&(*pRoot)->_pLeft, data);
	else if(data < (*pRoot)->_data)
		DeleteBSTree(&(*pRoot)->_pRight, data);
	else
	{
		BSTreeNode* pDel = *pRoot;

		//��ɾ���ڵ�ΪҶ�ӽڵ��ֻ���Һ���
		if (!pDel->_pLeft)
		{
			*pRoot = pDel->_pLeft;
			free(pDel);
			return 1;
		}

		//��ɾ���ڵ�ֻ������
		else if (!pDel->_pRight)
		{
			*pRoot = pDel->_pRight;
			free(pDel);
			return 1;
		}
		
		//��������������
		else
		{
			BSTreeNode* replace = (*pRoot)->_pRight;
			while (replace->_pLeft)
				replace = replace->_pLeft;

			//�滻��ɾ��
			pDel->_data = replace->_data;

			//��ɾ���ڵ����������ɾ������ڵ�
			DeleteBSTree(&(*pRoot)->_pRight, replace->_data);
		}
	}
}

//����ֵΪdata�Ľڵ�
BSTreeNode* FindBSTree(BSTreeNode* pRoot, DataType data)
{
	if (pRoot == NULL)
		return NULL;

	if (pRoot->_data == data)
		return pRoot;
	else if (pRoot->_data > data)
	{
		return FindBSTree(pRoot->_pLeft, data);
	}
	else
		return FindBSTree(pRoot->_pRight, data);

}

//�����������������
void InOrder(BSTreeNode* pRoot)
{
	if (pRoot == NULL)
		return;
	InOrder(pRoot->_pLeft);
	printf("%d ", pRoot->_data);
	InOrder(pRoot->_pRight);

}

//���ٶ���������
void Destroy(BSTreeNode** pRoot)
{
	assert(pRoot);
	if (*pRoot)
	{
		Destroy((*pRoot)->_pLeft);
		Destroy((*pRoot)->_pRight);
		free(*pRoot);
		*pRoot = NULL;

	}
}
