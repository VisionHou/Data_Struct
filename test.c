#include"SList.h"
#include<Windows.h>
#include<stdio.h>

#if 0
void TestSList()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqLisPrint(&s);

	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqLisPrint(&s);

	SeqListPushFront(&s, 5);
	SeqListPushFront(&s, 6);
	SeqLisPrint(&s);

	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqLisPrint(&s);

	SeqListInsert(&s, 3, 7);
	SeqLisPrint(&s);

	SeqListErase(&s, 2);
	SeqLisPrint(&s);

	SeqListFind(&s, 2)
		;
	SeqListRemove(&s,3);
	SeqLisPrint(&s);

	SeqListRemoveAll(&s, 4);
	SeqLisPrint(&s);

	int sz = 0;
	printf("有效元素个数是%d\n", SeqListSize(&s));
}
#endif

void TestSListD()
{
	SeqListD s;
	SeqListDInit(&s);
	SeqListDPushBack(&s, 1);
	SeqListDPushBack(&s, 2);
	SeqListDPushBack(&s, 3);
	SeqLisDPrint(&s);

	SeqListDPopBack(&s);
	SeqLisDPrint(&s);

	printf("size=%d\n", SeqListDSize(&s));
	printf("capacity=%d\n", SeqListDCapacity(&s));

	SeqListDClear(&s);
	printf("size=%d\n", SeqListDSize(&s));
	printf("capacity=%d\n", SeqListDCapacity(&s));




}
int main()
{
	//TestSList();
	TestSListD();
	system("pause");
	return 0;
}