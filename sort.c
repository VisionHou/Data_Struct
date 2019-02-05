#include"sort.h"
#include<stdio.h>

void PrintArray(int *array, int size)
{
	for (int i = 0; i < size - 1; i++)
		printf("%d ", array[i]);

	printf("\n");
}

void InsertSort(int *array, int size)
{
	int i = 1;
	for (; i < size; i++)
	{
		int end = i - 1;
		int key = array[i];

		//找插入元素的位置
		if (end >= 0 && array[end] > key)
		{
			array[end+1] = array[end];
			end--;
		}

		array[end+1] = key;
	}
}

void InsertSort_OP(int *array, int size)
{
	for (int i = 1; i < size; i++)
	{
		int key = array[i];
		int begin = 0;
		int end = i - 1;
		int mid = -1;

		//二分查找找插入元素的位置
		while (begin <= end)
		{
			mid = begin + ((end - begin) >> 1);
			if (key >= array[mid])
				begin = mid + 1;
			else
				end = mid - 1;
		}

		//向后搬移元素
		end = i - 1;
		while (end >= begin)
		{
			array[end + 1] = array[end];
			--end;

		}

		array[begin] = key;
	}
}

void ShellSort(int *array, int size)
{
	int i = 0;
	int gap = size;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (i = gap; i < size; i++)
		{
			int key = array[i];
			int end = i - gap;

			while (end >= 0 && key < array[end])
			{
				array[end + gap] = array[end];
				end -= gap;
			}
			
			array[end + gap] = key;
		
		}
	}
}