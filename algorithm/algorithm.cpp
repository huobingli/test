// algorithm.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
// 排序函数
// 排序稳定？
// 排序稳定是指 排序之后具有相同关键字的元素之间的相对次序保持不变
// 反之，排序之后具有相同关键字的元素之间的相对次序改变的为不稳定排序

// 内排序 和 外排序 （排序需要多次内存交换）
// 内排序：排序过程中，整个表都是放在内存中处理，不涉及内外存数据的交换
// 外排序：排序过程中，需要进行内外存数据的交换

// 排序

//输出函数
void EchoArray(int R[], int n, int nStep)
{
	std::cout << nStep << "步";
	for (int i = 0; i < n; i++)
	{
		std::cout << R[i] << " ";
	}
	std::cout << "\n";
}

void EchoArray(const char name[], int R[], int n)
{
	std::cout << name << "结果" << ":";

	for (int i = 0; i < n; i++)
	{
		std::cout << R[i] << " ";
	}
	std::cout << "\n" << "end " << name << "\n";
}

// 插入排序
void InsertSort(char name[], int R[], int n)
{
	std::cout << name << " begin " << std::endl;
	int i, j;
	int tmp;
	for (i = 1; i < n; i++)
	{
		tmp = R[i];
		j = i - 1;
		while (j >= 0 && tmp < R[j])
		{
			R[j + 1] = R[j];
			j--;
			EchoArray(R, n, i);
		}
		R[j + 1] = tmp;

		EchoArray(R, n, i);
	}
}

// 折半插入排序 (这个有问题)
void InsertSort1(char name[], int R[], int n)	// 对于R[0,....,n-1]按照递增顺序进行折半插入排序
{
	std::cout << name << " begin " << std::endl;
	int i, j, low, high, mid;
	int tmp;
	for (i = 1; i < n; i++)
	{
		tmp = R[i];
		low = 0; high = i - 1;
		while (low <= high)		// 在R[low...high]中折半查找有序插入的位置
		{
			mid = (low + high) / 2;		//取中间位置
			if (tmp < R[mid])
			{
				high = mid - 1;		// 插入点在左边
			}
			else
			{
				low = mid + 1;		// 插入点在右边
			}
		}

		for (j = i - 1; j >= high + 1; j--)	// 元素后移
		{
			R[j + 1] = R[j];
			EchoArray(R, n, i);
		}

		R[high + i] = tmp;		// 插入元素
		EchoArray(R, n, i);
	}
}

// 希尔排序
void ShellSort(char name[], int R[], int n)
{
	std::cout << name << " begin " << std::endl;
	int i, j, gap;
	int tmp;
	gap = n / 2;	//增量初值
	while (gap > 0)
	{
		for (i = gap; i < n; i++)	//对所有像个gap位置的元素组采用直接插入排序
		{
			tmp = R[i];
			j = i - gap;
			while(j >= 0 && tmp < R[j])	// 对相隔gap位置的元素组进行排序
			{ 
				R[j + gap] = R[j];
				j = j - gap;
			}
			R[j + gap] = tmp;
			EchoArray(R, n, i);
		}
		gap = gap / 2;	// 减下增量
	}
}

// 冒泡排序
void BubbleSort(char name[], int R[], int n)
{
	int i, j;
	int tmp;
	for (i = 0; i < n - 1; i++)
	{
		for (j = n - 1; j > i; j--)
		{
			if (R[j] < R[j - 1])	// 比较，找出本趟关键词的最小元素
			{
				tmp = R[j];			// R[j]与R[j-1]进行交换，将关键词最小的元素前移
				R[j] = R[j - 1];
				R[j - 1] = tmp;
			}
			EchoArray(R, n, i);
		}

		EchoArray(R, n, i);
	}
}

// 快速排序
void QuickSort(char name[], int R[], int s, int t) // 对 R[s] 到R[t]的元素进行排序
{
	int i = s, j = t;
	int tmp;
	if (s < t)
	{
		tmp = R[s];
		while (i != j)
		{
			while (j > i && R[j] >= tmp)
			{
				j -- ;
			}
			R[i] = R[j];

			EchoArray(R, 9, i);

			while (i < j && R[i] <= tmp)
			{
				i ++;
			}
			R[j] = R[i];
			EchoArray(R, 9, i);
		}
		R[i] = tmp;
		EchoArray(R, 9, i);

		QuickSort(name, R, s, i - 1);			// 对左区间递归排序
		QuickSort(name, R, i + 1, t);			// 对右区间递归排序
	}
}

// 选择排序
void SelectSort(char name[], int R[], int n)
{
	int i, j, k;
	int tmp;
	for (i = 0; i < n - 1; i++)			// 做第i趟排序
	{
		k = i;

		for (j = i + 1; j < n; j++)		// 在当前无序区R[i, ... ，n-1]中选最小的R[k]
		{
			if (R[j] < R[k])
			{
				k = j;					// K记录目前找到的最小关键字所在的位置
			}
		}

		std::cout << "当前找到的最小K为" << k << "  ";
		EchoArray(R, n, i);

		if (k != i)						// 交换R[i]和R[K]
		{
			tmp = R[i];
			R[i] = R[k];
			R[k] = tmp;
		}
		std::cout << "交换之后  ";
		EchoArray(R, n, i);
	}
}

int main()
{
	int ay[] = { 5, 4, 2, 1, 3, 6, 9, 8, 7 };
	// 插入排序
	char* name = "插入排序";
	InsertSort(name, ay, 9);
	EchoArray(name ,ay, 9);
	
	// 
	int ay1[] = { 5, 4, 2, 1, 3, 6, 9, 8, 7 };
	char name1[] = "折半排序";
	InsertSort1(name1, ay1, 9);
	EchoArray(name1, ay1, 9);
	
	// 希尔排序
	int ay2[] = { 5, 4, 2, 1, 3, 6, 9, 8, 7 };
	char name2[] = "希尔排序";
	ShellSort(name2, ay2, 9);
	EchoArray(name2, ay2, 9);

	// 冒泡排序
	int ay3[] = { 5, 4, 2, 1, 3, 6, 9, 8, 7 };
	char name3[] = "冒泡排序";
	BubbleSort(name3, ay3, 9);
	EchoArray(name3, ay3, 9);

	// 快速排序
	int ay4[] = { 5, 4, 2, 1, 3, 6, 9, 8, 7 };
	char name4[] = "快速排序";
	QuickSort(name4, ay4, 0, 8);
	EchoArray(name4, ay4, 9);

	// 选择排序
	int ay5[] = { 5, 4, 2, 1, 3, 6, 9, 8, 7 };
	char name5[] = "选择排序";
	SelectSort(name5, ay5, 9);
	EchoArray(name5, ay5, 9);
    return 0;
}


