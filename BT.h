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
//先进先出

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
	DataType _array[Max_Size];//数组存放
	int _top;//有效元素个数(表示栈顶位置)
}Stack;

//初始化
void StackInit(Stack* s);

//入栈
void StackPush(Stack* s, DataType data);

//出栈
void StackPop(Stack* s);

//获取栈顶元素
DataType StackTop(Stack* s);

//获取有效元素的个数
int StackSize(Stack* s);

//栈是否为空
int StackEmpty(Stack* s);

//打印栈
void PrintStack(Stack* s);


typedef char BTDataType;
typedef struct BinTreeNode
{
	struct BinTreeNode* _pLeft;//左子树
	struct BinTreeNode* _pRight;//右子树
	BTDataType _data;//当前节点数据
}BTNode,*PBTNode;


//创建二叉树
void CreateBinTree(PBTNode pRoot, BTDataType array[], int size, BTDataType invalid);

//拷贝二叉树
PBTNode CopyBinTree(PBTNode pRoot);

//递归-前序遍历
void PreOrder(PBTNode pRoot);

//递归-中序遍历
void InOrder(PBTNode pRoot);

//递归-后序遍历
void PostOrder(PBTNode pRoot);

//层序遍历
void LevelOrder(PBTNode pRoot);

//销毁二叉树
void DestroyBinTree(PBTNode* pRoot);

//递归-二叉树的镜像
void MirrorBinTreeNode(PBTNode pRoot);

//二叉树中节点个数
int BinTreeSize(PBTNode pRoot);

//二叉树中叶子节点个数
int BinTreeLeaf(PBTNode pRoot);

//二叉树中第k层节点的个数
int BinTreeKLevelNode(PBTNode pRoot, int k);

//二叉树的高度
int BinTreeHight(PBTNode pRoot);

//查找值为data的节点
PBTNode BinTreeFind(PBTNode pRoot, BTDataType data);

//节点是否在二叉树中
int IsNodeInBinTree(PBTNode pRoot, PBTNode pNode);

//检测一棵树是否为完全二叉树
int IsCompleteBinTree(PBTNode pRoot);
