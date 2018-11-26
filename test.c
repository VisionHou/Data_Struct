#include"queue.h"
#include<windows.h>

void TestQueue()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	QueuePrint(&q);

	QueuePop(&q);
	QueuePrint(&q);

	printf("Front= %d\n",QueueFront(&q));
	printf("Back= %d\n", QueueBack(&q));
	printf("size= %d\n", QueueSize(&q));
	printf("ret= %d\n", QueueEmpty(&q));

}

int main()
{
	TestQueue();
	system("pause");
	return 0;
}