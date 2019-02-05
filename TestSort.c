#include"sort.h"
#include<stdio.h>
#include<windows.h>

void TestSort()
{
	int array[] = { 2,5,4,9,3,6,8,7,1,0 };
	//InsertSort(array, sizeof(array) / sizeof(array[0]));
	//InsertSort_OP(array, sizeof(array) / sizeof(array[0]));
	ShellSort(array, sizeof(array) / sizeof(array[0]));

	PrintArray(array, sizeof(array) / sizeof(array[0]));
}

int main()
{
	TestSort();
	system("pause");
	return 0;
}