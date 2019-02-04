#pragma once

//�ڵ��зż�ֵ��
typedef int keyType;
typedef int ValueType;

typedef struct Pair
{
	keyType _key;//�ؼ���
	ValueType _value;//ֵ
}Pair;

typedef struct BSTreeNode
{
	struct BSTreeNode* _pLeft;
	struct BSTreeNode* _pRight;
	Pair _pair;
}BSTreeNode;

//��ʼ������������
void InitBSTree(BSTreeNode** pRoot);

//����ֵΪdata��Ԫ��
void InsertBSTree(BSTreeNode** pRoot, keyType key,ValueType value);

//ɾ��ֵΪdata�Ľڵ�
void DeleteBSTree(BSTreeNode** pRoot, keyType key);

//����ֵΪdata�Ľڵ�
BSTreeNode* FindBSTree(BSTreeNode* pRoot, keyType key);

//�����������������
void InOrder(BSTreeNode* pRoot);

//���ٶ���������
void Destroy(BSTreeNode** pRoot);
