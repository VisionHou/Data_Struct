#include<iostream>
#include<vector>
#include<string.h>
#include<malloc.h>
#include<math.h>
#include<algorithm>
using namespace std;

//kmp算法
//前缀表
void Prefix_table(char pattern[], int prefix[], int n)
{
	prefix[0] = 0;
	int len = 0;
	int i = 1;
	while (i < n)
	{
		if (pattern[i] == pattern[len])
		{
			len++;
			prefix[i] = len;
			i++;
		}
		else
		{
			if (len > 0)
			{
				len = prefix[len - 1];//斜着移
			}
			else
			{
				prefix[i] = 0;
				i++; 
			}
		}
	}
}

//移位
void move_prefix_table(int prefix[], int n)
{
	for (int i = n-1; i > 0; i--)
	{
		prefix[i] = prefix[i-1];
	}
	prefix[0] = -1;
}
//kmp
void kmp_search(char text[], char pattern[])
{
	int n = strlen(pattern);
	int m = strlen(text);

	int* prefix = (int*)malloc(sizeof(int) * n);
	Prefix_table(pattern, prefix, n);
	move_prefix_table(prefix, n);
	//text[i] len(text)=m
	//pattern[j] len(pattern)=n
	int i = 0; 
	int j = 0;
	while (i < m)
	{
		if (j == n - 1 && text[i] == pattern[j])
		{
			printf("found in %d\n!!!", i-j);
			j = prefix[j];
		}
		if (text[i] == pattern[j])
		{
			i++;
			j++;
		}
		else
		{
			j = prefix[j];
			if (j == -1)
			{
				i++;
				j++;
			}
		}
	}
}
int main()
{
	char text[] = "ABABABCABAA";
	char pattern[] = "ABABCABAA";
	int prefix[9] = { 0 };
	kmp_search(text, pattern);
	/*Prefix_table(pattern, prefix, 9);
	move_prefix_table(prefix, 9);
	for (int i = 0; i < 9; i++)
		cout << prefix[i] << endl;*/
	return 0;
}

/*
//做任务，有冲突，最大和
int MaxAdd(int* arr, int size)
{
	if (size == 0)
		return arr[0];
	else if (size == 1)
		return max(arr[0], arr[1]);
	else
	{
		int a = arr[size] + MaxAdd(arr, size - 2);
		int b = MaxAdd(arr, size - 1);
		return max(a, b);
	}
}
int MaxAdd_Nor(int* arr, int size)
{
	int opt[7] = { 0 };
	opt[0] = arr[0];
	opt[1] = max(arr[0], arr[1]);
	for (int i = 2; i < size; i++)
	{
		int a = opt[i - 2] + arr[i];
		int b = opt[i - 1];
		opt[i] = max(a, b);
	}
	return opt[size-1];
}
*/


/*
//是否存在不连续的子集和为s
int SubSet(int* arr, int size, int s)
{
	if (size == 0)
		return arr[0] == s;
	else if (s == 0)
		return 1;
	else if (arr[size] > s)
		return SubSet(arr, size - 1, s);
	else
	{
		int a= SubSet(arr, size - 1, s);
		int b= SubSet(arr, size - 1, s-arr[size]);
		return a || b;
	}
}
int SubSet_nor(int* arr, int size, int s)
{
	int dp[6][10] = { 0 };
	for (int i = 0; i < 6; i++)
		dp[i][0] = 1;
	dp[0][arr[0]] = 1;
	for (int i = 1; i < 6; i++)
	{
		for (int j = 1; j <= s; j++)
		{
			if (arr[i] > j) dp[i][j] = dp[i - 1][j];
			else
			{
				int a = dp[i - 1][j-arr[i]];
				int b = dp[i - 1][j];
				dp[i][j] = a || b;
			}
		}
	}
	return dp[size][s];
}
*/
//int main()
//{
//	//int arr[7] = { 1,2,4,1,7,8,3 };
//	int arr[] = { 3,34,4,12,5,2 };
//	int s = 9;
//	int ret=SubSet(arr, 5, 9);
//	int ret1 = SubSet_nor(arr, 5, 9);
//	//int ret = MaxAdd_Nor(arr, sizeof(arr) / sizeof(arr[0]));
//	cout << ret1 << endl;
//	return 0;
//}
//

////时间 题号 单位得分 单位时间 
//int Max(int at, int i, vector<int>& s, vector<int>& t)
//{
//	if (at <= 0)
//		return 0;
//	if (i == 0)
//		return s[i];
//	int A = s[i] + Max(at - t[i], i - 1, s, t);//做这个题
//	int B = Max(at, i - 1, s, t);//不做这个题
//	return A > B ? A : B;
//}
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> score(n);//保存每个题得分
//	vector<int> time(n);//保存每个题所需时间
//	for (int i = 0; i < n; i++)
//		cin >> score[i];
//	for (int i = 0; i < n; i++)
//		cin >> time[i];
//	int alltime;
//	cin >> alltime;
//
//	int ret = Max(alltime, n - 1, score, time);
//	cout << ret << endl;
//	return 0;
//}



