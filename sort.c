#include"sort.h"
#include<stdio.h>
#include<assert.h>
void PrintArray(int *array, int size)
{
	for (int i = 0; i < size ; i++)
		printf("%d ", array[i]);

	printf("\n");
}

void InsertSort(int* array, int size)
{
	//从第二个开始排序
	for (int i = 1; i < size; i++)
	{
		int key = array[i];
		int end = i - 1;//下标
		while (end >= 0 && array[end] > key)//找插入位置
		{
			array[end + 1] = array[end];
			end--;
		}
		array[end+1] = key;
	}
}

void InsertSort_OP(int* array, int size)
{
	for (int i = 1; i < size; i++)
	{
		//二分查找找插入位置
		int key = array[i];
		int begin = 0;
		int end = i - 1;
		int mid = -1;
		while (begin <= end)
		{
			mid = begin + ((end - begin) >> 1);
			if (array[mid] < key)
				begin = mid + 1;
			else
				end = mid - 1;
		}
		//搬移元素
		end = i - 1;
		while (begin <= end)
		{
			array[end + 1] = array[end];
			end--;
		}
		array[end+1] = key;
	}
}

void ShellSort(int* array, int size)
{
	int gap = size;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = gap; i < size; i++)
		{
			int key = array[i];
			int end = i - gap;
			while (end >= 0 && key < array[end])
			{
				array[end + gap] = array[end];
				end-=gap;
			}
			array[end + gap] = key;
		}
	}
}

void Swap(int* pLeft, int* pRight)
{
	int temp = 0;
	assert(pLeft);
	assert(pRight);

	temp = *pLeft;
	*pLeft = *pRight;
	*pRight = temp;
}
void SelectSort(int* array, int size)
{
	for (int i = 0; i < size; i++)//外循环控制趟数
	{
		int k = i;
		for (int j = i + 1; j < size; j++)//找最小的
		{
			if (array[k] > array[j])
				k = j;
		}
		if(k!=i)
		{
			int tmp = array[i];
			array[i] = array[k];
			array[k] = tmp;
		}
	}
}

//堆排序
void HeapAdjust(int* array, int parent, int size)
{
	int child = 2 * parent + 1;
	while (child < size)
	{
		if (child + 1 < size && array[child + 1] > array[child])
			child += 1;//child标记较大元素
		if (array[child] > array[parent])
		{
			Swap(&array[child], &array[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			return;
	}
}
void HeapSort(int* array, int size)
{
	int end = size - 1;
	int root = (size - 2) >> 1;
	for (; root >= 0; root--)
		HeapAdjust(array, root, size);//建大堆
	while (end)
	{
		Swap(&array[0], &array[end]);
		HeapAdjust(array, 0, end--);
	}
}

void BubbleSort(int* array, int size)
{
	int flag = 1;
	for (int i = 0; i < size&&flag==1; i++)
	{
		int flag = 0;
		for (int j = 1; j < size - i; j++)
		{
			if (array[j - 1] > array[j])
			{
				flag = 1;
				Swap(&array[j - 1], &array[j]);//两两比较有逆序就交换 
			}
		}
	}
}
int Partion1(int* array, int left, int right)
{
	assert(array);
	int begin = left;
	int end = right-1;
	int key = array[end];
	while (begin < end)
	{
		while (begin < end && array[begin] <= key)
			begin++;
		while (begin < end && array[end] >= key)
			end--;
		if (begin < end)
			Swap(&array[begin], &array[end]);
	}
	Swap(&array[right - 1], &array[begin]);
	return begin;
}

int Partion2(int* array, int left, int right)
{
	assert(array);
	int begin = left;
	int end = right - 1;
	int key = array[end];
	while (begin < end)
	{
		while (begin < end && array[begin] <= key)
			begin++;
		if (begin < end)
			array[end] = array[begin];
		while (begin < end && array[end] >= key)
			end--;
		if (begin < end)
			array[begin] = array[end];
	}
	array[begin] = key;
	return begin;
}
int Partion3(int* array, int left, int right)
{
	int cur = left;
	int pre = cur-1;
	int end = right - 1;
	int key = array[end];
	while (cur<end)
	{
		while (array[cur] > key)
			cur++;
		if (array[cur] <= key)
		{
			pre++;
			Swap(&array[pre], &array[cur]);
			cur++;
		}
	}
	Swap(&array[pre], &array[end]);
	return pre;
}
//快排 递归[)
void QuickSort(int* array, int left,int right)
{
	if (left >= right)
		return;
		int div = Partion2(array, left, right);
		QuickSort(array, left, div);
		QuickSort(array, div + 1, right);
	
}