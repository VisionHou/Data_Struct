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

//插入值为data的元素
void InsertBSTree(BSTreeNode** pRoot, DataType data)
{
	assert(pRoot);

	BSTreeNode* pCur = NULL;
	BSTreeNode* pParent = NULL;

	//树为空，直接插入
	if (*pRoot == NULL)
	{
		*pRoot = BuyBSTreeNode(data);
		return;
	}
	
	//树不空，先找到插入位置，该节点不存在时插入
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

//删除值为data的节点
void DeleteBSTree(BSTreeNode** pRoot, DataType data)
{
	assert(pRoot);

	BSTreeNode* pDel = *pRoot;
	BSTreeNode* pParent = NULL;

	//找到该节点位置
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
	
	//叶子节点或只有左子树存在
	if (!pDel->_pRight)
	{
		//是根节点，让根节点指向根节点的左孩子
		if (pDel == pRoot)
			pRoot = pDel->_pLeft;

		//不是根节点，是双亲节点的左孩子，让双亲的左子树指向待删除节点的左子树
		//是双亲的右孩子，让双亲的右指针指向待删除节点的左子树
		if(pDel==pParent->_pLeft)
			pParent->_pLeft = pDel->_pLeft;
		if (pDel == pParent->_pRight)
			pParent->_pRight = pDel->_pLeft;
		free(pDel);
	}

	//只有右子树存在
	if (!pDel->_pLeft)
	{
		//是根节点，让根节点指向根节点的右孩子
		if (pDel == pRoot)
			pRoot = pDel->_pRight;
		//不是根节点，是双亲左孩子，让双亲的左指针指向带删除节点的右子树
		//是双亲的右孩子，让双亲的右指针指向带删除节点的右子树
		if (pDel == pParent->_pLeft)
			pParent->_pLeft = pDel->_pRight;
		if (pDel == pParent->_pRight)
			pParent->_pRight = pDel->_pRight;

		free(pDel);
	}

	//左右子树都存在，在右子树里最小的节点为替代节点然后删除替代节点
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

//查找值为data的节点
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

//中序遍历二叉搜索树
void InOrder(BSTreeNode* pRoot)
{
	//二叉搜索树的中序遍历是一个有序序列
	if (pRoot == NULL)
		return;

	InOrder(pRoot->_pLeft);
	printf("%d ", pRoot->_data);
	InOrder(pRoot->_pRight);

}

//销毁二叉搜索树
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


//初始化二叉搜索树
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
//插入值为data的元素
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

//删除值为data的节点
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

		//待删除节点为叶子节点或只有右孩子
		if (!pDel->_pLeft)
		{
			*pRoot = pDel->_pLeft;
			free(pDel);
			return 1;
		}

		//待删除节点只有左孩子
		else if (!pDel->_pRight)
		{
			*pRoot = pDel->_pRight;
			free(pDel);
			return 1;
		}
		
		//左右子树都存在
		else
		{
			BSTreeNode* replace = (*pRoot)->_pRight;
			while (replace->_pLeft)
				replace = replace->_pLeft;

			//替换法删除
			pDel->_data = replace->_data;

			//在删除节点的右子树中删除替代节点
			DeleteBSTree(&(*pRoot)->_pRight, replace->_data);
		}
	}
}

//查找值为data的节点
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

//中序遍历二叉搜索树
void InOrder(BSTreeNode* pRoot)
{
	if (pRoot == NULL)
		return;
	InOrder(pRoot->_pLeft);
	printf("%d ", pRoot->_data);
	InOrder(pRoot->_pRight);

}

//销毁二叉搜索树
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
