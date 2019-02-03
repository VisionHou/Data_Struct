#include"BSTree.h"
#include<Windows.h>
#include<stdio.h>


void TestBSTree()
{
	int arr[] = { 5,3,4,1,7,8,2,6,0,9 };
	BSTreeNode* pRoot=NULL;
	InitBSTree(&pRoot);

	int i = 0;
	for (; i < sizeof(arr) / sizeof(0); i++)
		InsertBSTree(&pRoot, arr[i]);

	printf("中序遍历：");
	InOrder(pRoot);
	printf("\n");


	DeleteBSTree(&pRoot, 5);
	printf("中序遍历：");
	InOrder(pRoot);
	printf("\n");
	printf("%d\n", FindBSTree(pRoot, 5));

}
int main()
{
	TestBSTree();
	system("pause");
	return 0;
}