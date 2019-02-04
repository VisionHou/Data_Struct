#pragma once

//节点中放键值对
typedef int keyType;
typedef int ValueType;

typedef struct Pair
{
	keyType _key;//关键码
	ValueType _value;//值
}Pair;

typedef struct BSTreeNode
{
	struct BSTreeNode* _pLeft;
	struct BSTreeNode* _pRight;
	Pair _pair;
}BSTreeNode;

//初始化二叉搜索树
void InitBSTree(BSTreeNode** pRoot);

//插入值为data的元素
void InsertBSTree(BSTreeNode** pRoot, keyType key,ValueType value);

//删除值为data的节点
void DeleteBSTree(BSTreeNode** pRoot, keyType key);

//查找值为data的节点
BSTreeNode* FindBSTree(BSTreeNode* pRoot, keyType key);

//中序遍历二叉搜索树
void InOrder(BSTreeNode* pRoot);

//销毁二叉搜索树
void Destroy(BSTreeNode** pRoot);
