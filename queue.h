typedef int DataType;

typedef struct Node
{
	DataType data;
	struct Node* _pNext;
}Node,*pNode;

typedef struct Queue
{
	pNode _pHead;
	pNode _pTail;

}Queue;
//先进先出

void QueueInit(Queue* q);
pNode BuyQueueNode(DataType data);
void QueuePush(Queue* q,DataType data);
void QueuePop(Queue* q);
DataType QueueFront(Queue* q);
DataType QueueBack(Queue* q);
int QueueSize(Queue* q);
int QueueEmpty(Queue* q);
void QueuePrint(Queue* q);