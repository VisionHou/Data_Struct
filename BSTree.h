#pragma once

typedef int DataType;
typedef struct BSTreeNode
{
	struct BSTreeNode* _pLeft;
	struct BSTreeNode* _pRight;
	DataType _data;
}BSTreeNode;

#if 0
///////////////ѭ������/////////////
////////////////////////////////////

//��ʼ������������
void InitBSTree(BSTreeNode** pRoot);

//����ֵΪdata��Ԫ��
void InsertBSTree(BSTreeNode** pRoot, DataType data);

//ɾ��ֵΪdata�Ľڵ�
void DeleteBSTree(BSTreeNode** pRoot, DataType data);

//����ֵΪdata�Ľڵ�
int FindBSTree(BSTreeNode* pRoot, DataType data);

//�����������������
void InOrder(BSTreeNode* pRoot);

//���ٶ���������
void Destroy(BSTreeNode** pRoot);

#endif

//////////////////�ݹ�////////
//��ʼ������������
void InitBSTree(BSTreeNode** pRoot);

//����ֵΪdata��Ԫ��
int InsertBSTree(BSTreeNode** pRoot, DataType data);

//ɾ��ֵΪdata�Ľڵ�
int DeleteBSTree(BSTreeNode** pRoot, DataType data);

//����ֵΪdata�Ľڵ�
BSTreeNode* FindBSTree(BSTreeNode* pRoot, DataType data);

//�����������������
void InOrder(BSTreeNode* pRoot);

//���ٶ���������
void Destroy(BSTreeNode** pRoot);

