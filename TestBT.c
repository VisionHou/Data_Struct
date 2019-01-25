#include"BT.h"
#include<windows.h>
#include<stdio.h>
#include<string.h>
void TestBinTree()
{
	char* str = "ABD###CE##F";
	PBTNode pRoot = NULL;
	PBTNode pNewRoot = NULL;
	PBTNode pNode = NULL;
	int IsComBinTree = 0;

	CreateBinTree(&pRoot, str, strlen(str), '#');
	//pNewRoot = CopyBinTree(pRoot);

	printf("前序遍历： ");
	PreOrder(pRoot);
	printf("\n");

	printf("前序遍历： ");
	PreOrderNor(pRoot);
	printf("\n");


	printf("中序遍历： ");
	InOrder(pRoot);
	printf("\n");


	printf("中序遍历： ");
	InOrderNor(pRoot);
	printf("\n");

	printf("后序遍历： ");
	PostOrder(pRoot);
	printf("\n");

	printf("后序遍历： ");
	PostOrderNor(pRoot);
	printf("\n");

	printf("层序遍历： ");
	LevelOrder(pRoot);
	printf("\n");

	MirrorBinTreeNode(pRoot);
	MirrorBinTreeNode(pRoot);
	printf("层序遍历： ");
	LevelOrder(pRoot);
	printf("\n");

	printf("二叉树中节点的个数是: %d\n", BinTreeSize(pRoot));
	printf("二叉树中叶子节点的个数是: %d\n", BinTreeLeaf(pRoot));
	printf("二叉树中第4层节点的个数是: %d\n", BinTreeKLevelNode(pRoot,4));
	printf("二叉树的高度是: %d\n", BinTreeHight(pRoot));

	pNode = BinTreeFind(pRoot, 'E');
	if (IsNodeInBinTree(pRoot,pNode))
		printf("%c在二叉树中\n", pNode->_data);
	else
		printf("%c不在二叉树中\n", pNode->_data);

	if (IsCompleteBinTree(pRoot))
		printf("是完全二叉树\n");
	else
		printf("不是完全二叉树\n");

}
int main()
{
	TestBinTree();
	system("pause");
	return 0;
}
