#include"BSTreekv.h"
#include<assert.h>
#include<malloc.h>
#include<stdio.h>

//初始化二叉搜索树
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

//插入值为value的元素
void InsertBSTree(BSTreeNode** pRoot, keyType key, ValueType value)
{
	assert(pRoot);
	if (*pRoot == NULL)
	{
		*pRoot = BuyBSTreeNode(key, value);
		return;
	}
	//找插入位置
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

	//插入新节点
	pCur = BuyBSTreeNode(key, value);
	if (key < pParent->_pair._key)
		pParent->_pLeft = pCur;
	else
		pParent->_pRight = pCur;

}

//删除值为value的节点
void DeleteBSTree(BSTreeNode** pRoot, keyType key)
{
	assert(pRoot);
	
	BSTreeNode* pCur = *pRoot;
	BSTreeNode* pParent = NULL;
	
	//找待删除节点的位置
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

	//没找到
	if (pCur == NULL)
		return ;

	//带删除节点只有左子树或为叶子节点
	if (!pCur->_pRight)
	{
		//是根节点
		if (pCur == *pRoot)
			*pRoot = pCur->_pLeft;

		//是双亲的左孩子
		if (pCur == pParent->_pLeft)
			pParent->_pLeft = pCur->_pLeft;

		//是双亲的右孩子
		else
			pParent->_pRight = pCur->_pLeft;
	}

	//带删除节点只有右子树
	else if (!pCur->_pLeft)
	{
		//是根节点
		if (pCur == *pRoot)
			*pRoot = pCur->_pRight;

		//是双亲的左孩子
		if (pCur == pParent->_pLeft)
			pParent->_pLeft = pCur->_pRight;

		//是双亲的右孩子
		else
			pParent->_pRight = pCur->_pRight;
	}

	//左右子树都存在,右子树中找最左的节点
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

//查找值为value的节点
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

//中序遍历二叉搜索树
void InOrder(BSTreeNode* pRoot)
{
	if (pRoot)
	{
		InOrder(pRoot->_pLeft);
		printf("%d,%d ", pRoot->_pair._key, pRoot->_pair._value);
		InOrder(pRoot->_pRight);
	}
}

//销毁二叉搜索树
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