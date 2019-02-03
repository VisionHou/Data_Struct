#pragma once

typedef int DataType;
typedef struct BSTreeNode
{
	struct BSTreeNode* _pLeft;
	struct BSTreeNode* _pRight;
	DataType _data;
}BSTreeNode;

#if 0
///////////////循环遍历/////////////
////////////////////////////////////

//初始化二叉搜索树
void InitBSTree(BSTreeNode** pRoot);

//插入值为data的元素
void InsertBSTree(BSTreeNode** pRoot, DataType data);

//删除值为data的节点
void DeleteBSTree(BSTreeNode** pRoot, DataType data);

//查找值为data的节点
int FindBSTree(BSTreeNode* pRoot, DataType data);

//中序遍历二叉搜索树
void InOrder(BSTreeNode* pRoot);

//销毁二叉搜索树
void Destroy(BSTreeNode** pRoot);

#endif

//////////////////递归////////
//初始化二叉搜索树
void InitBSTree(BSTreeNode** pRoot);

//插入值为data的元素
int InsertBSTree(BSTreeNode** pRoot, DataType data);

//删除值为data的节点
int DeleteBSTree(BSTreeNode** pRoot, DataType data);

//查找值为data的节点
BSTreeNode* FindBSTree(BSTreeNode* pRoot, DataType data);

//中序遍历二叉搜索树
void InOrder(BSTreeNode* pRoot);

//销毁二叉搜索树
void Destroy(BSTreeNode** pRoot);

