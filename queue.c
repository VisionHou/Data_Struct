#include"queue.h"
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>


void QueueInit(Queue* q)
{
	assert(q);
	q->_pHead = q->_pTail = NULL;
}

pNode BuyQueueNode(DataType data)
{
	pNode pNewNode = (Node*)malloc(sizeof(Node));
	if (pNewNode == NULL)
		return NULL;

	pNewNode->data = data;
	pNewNode->_pNext = NULL;
	return pNewNode;
}

void QueuePush(Queue* q, DataType data)
{
	assert(q);
	if (q->_pHead == NULL)
		q->_pHead = q->_pTail = BuyQueueNode(data);

	else
	{
		q->_pTail->_pNext= BuyQueueNode(data);
		q->_pTail = q->_pTail->_pNext;
	}
}

void QueuePop(Queue* q)
{
	assert(q);
	if (q->_pHead == NULL)
		return;

	pNode pDel = q->_pHead;
	q->_pHead = pDel->_pNext;
	free(pDel);

}


DataType QueueFront(Queue* q)
{
	return q->_pHead->data;
}

DataType QueueBack(Queue* q)
{
	return q->_pTail->data;
}

int QueueSize(Queue* q)
{
	pNode Cur = q->_pHead;
	int count = 0;
	while (Cur)
	{
		count++;
		Cur = Cur->_pNext;
	}
	return count;
}

int QueueEmpty(Queue* q)
{
	if (q->_pHead == NULL)
		return 0;
	return 1;
}

void QueuePrint(Queue* q)
{
	if (q->_pHead == NULL)
	{
		printf("╤сапн╙©у\n");
		return 0;
	}
	else
	{
		pNode pCur = q->_pHead;
		while (pCur)
		{
			printf("%d  ", pCur->data);
			pCur = pCur->_pNext;
		}
		printf("\n");
	}
}