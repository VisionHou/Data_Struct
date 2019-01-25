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

	printf("ǰ������� ");
	PreOrder(pRoot);
	printf("\n");

	printf("ǰ������� ");
	PreOrderNor(pRoot);
	printf("\n");

	printf("��������� ");
	InOrder(pRoot);
	printf("\n");


	printf("��������� ");
	InOrderNor(pRoot);
	printf("\n");

	printf("��������� ");
	PostOrder(pRoot);
	printf("\n");

	printf("��������� ");
	PostOrderNor(pRoot);
	printf("\n");

	printf("��������� ");
	LevelOrder(pRoot);
	printf("\n");

	MirrorBinTreeNode(pRoot);
	MirrorBinTreeNode(pRoot);
	printf("��������� ");
	LevelOrder(pRoot);
	printf("\n");

	printf("�������нڵ�ĸ�����: %d\n", BinTreeSize(pRoot));
	printf("��������Ҷ�ӽڵ�ĸ�����: %d\n", BinTreeLeaf(pRoot));
	printf("�������е�4��ڵ�ĸ�����: %d\n", BinTreeKLevelNode(pRoot,4));
	printf("�������ĸ߶���: %d\n", BinTreeHight(pRoot));

	pNode = BinTreeFind(pRoot, 'E');
	if (IsNodeInBinTree(pRoot,pNode))
		printf("%c�ڶ�������\n", pNode->_data);
	else
		printf("%c���ڶ�������\n", pNode->_data);

	if (IsCompleteBinTree(pRoot))
		printf("����ȫ������\n");
	else
		printf("������ȫ������\n");

}
int main()
{
	TestBinTree();
	system("pause");
	return 0;
}
