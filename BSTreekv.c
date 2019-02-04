#include"BSTreekv.h"
#include<assert.h>
#include<malloc.h>
#include<stdio.h>

//��ʼ������������
void InitBSTree(BSTreeNode** pRoot)
{
	assert(pRoot);
	*pRoot = NULL;
}

BSTreeNode* BuyBSTreeNode(keyType key, ValueType value)
{
	BSTreeNode* NewNode = (BSTreeNode*)malloc(sizeof(BSTreeNode));
	if (NewNode == NULL)
	{
		assert(0);
		return;
	}

	NewNode->_pair._key = key;
	NewNode->_pair._value = value;
	NewNode->_pLeft = NULL;
	NewNode->_pRight = NULL;

	return NewNode;
}

//����ֵΪvalue��Ԫ��
void InsertBSTree(BSTreeNode** pRoot, keyType key, ValueType value)
{
	assert(pRoot);
	if (*pRoot == NULL)
	{
		*pRoot = BuyBSTreeNode(key, value);
		return;
	}
	//�Ҳ���λ��
	BSTreeNode* pCur = *pRoot;
	BSTreeNode* pParent = NULL;

	while (pCur)
	{
		if (key < pCur->_pair._key)
		{
			pParent = pCur;
			pCur = pCur->_pLeft;
		}

		else if (key > pCur->_pair._key)
		{
			pParent = pCur;
			pCur = pCur->_pRight;
		}

		else
			return;
	}

	//�����½ڵ�
	pCur = BuyBSTreeNode(key, value);
	if (key < pParent->_pair._key)
		pParent->_pLeft = pCur;
	else
		pParent->_pRight = pCur;

}

//ɾ��ֵΪvalue�Ľڵ�
void DeleteBSTree(BSTreeNode** pRoot, keyType key)
{
	assert(pRoot);
	
	BSTreeNode* pCur = *pRoot;
	BSTreeNode* pParent = NULL;
	
	//�Ҵ�ɾ���ڵ��λ��
	while (pCur)
	{
		if (key == pCur->_pair._key)
		{
			break;
		}
		else if (key < pCur->_pair._key)
		{
			pParent = pCur;
			pCur = pCur->_pLeft;
		}
		else
		{
			pParent = pCur;
			pCur = pCur->_pRight;
		}

	}

	//û�ҵ�
	if (pCur == NULL)
		return ;

	//��ɾ���ڵ�ֻ����������ΪҶ�ӽڵ�
	if (!pCur->_pRight)
	{
		//�Ǹ��ڵ�
		if (pCur == *pRoot)
			*pRoot = pCur->_pLeft;

		//��˫�׵�����
		if (pCur == pParent->_pLeft)
			pParent->_pLeft = pCur->_pLeft;

		//��˫�׵��Һ���
		else
			pParent->_pRight = pCur->_pLeft;
	}

	//��ɾ���ڵ�ֻ��������
	else if (!pCur->_pLeft)
	{
		//�Ǹ��ڵ�
		if (pCur == *pRoot)
			*pRoot = pCur->_pRight;

		//��˫�׵�����
		if (pCur == pParent->_pLeft)
			pParent->_pLeft = pCur->_pRight;

		//��˫�׵��Һ���
		else
			pParent->_pRight = pCur->_pRight;
	}

	//��������������,��������������Ľڵ�
	else
	{
		BSTreeNode* pDel = pCur->_pRight;
		while (pDel->_pLeft)
		{
			pParent = pDel;
			pDel = pDel->_pLeft;
		}

		pCur->_pair._key = pDel->_pair._key;
		pCur->_pair._value = pDel->_pair._value;

		if (pDel == pParent->_pLeft)
			pParent->_pLeft = pDel->_pRight;
		else
			pParent->_pRight = pDel->_pRight;

		pCur = pDel;
	}

	free(pCur);
}

//����ֵΪvalue�Ľڵ�
BSTreeNode* FindBSTree(BSTreeNode* pRoot, keyType key)
{
	BSTreeNode* pCur = pRoot;
	while (pCur)
	{
		if (pRoot->_pair._key > key)
			pCur = pCur->_pLeft;
		else if (pRoot->_pair._key < key)
			pCur = pCur->_pRight;
		else
			return pCur;
	}
	
	return NULL;
}

//�����������������
void InOrder(BSTreeNode* pRoot)
{
	if (pRoot)
	{
		InOrder(pRoot->_pLeft);
		printf("%d,%d ", pRoot->_pair._key, pRoot->_pair._value);
		InOrder(pRoot->_pRight);
	}
}

//���ٶ���������
void Destroy(BSTreeNode** pRoot)
{
	assert(pRoot);
	if (*pRoot)
	{
		Destroy(&(*pRoot)->_pLeft);
		Destroy(&(*pRoot)->_pRight);
		free(*pRoot);
		(*pRoot) = NULL;
	}
}