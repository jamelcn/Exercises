/*-----------------------------------------------------------------------------
 *  查找最小的 k 个元素
 *  题目:输入 n 个整数,输出其中最小的 k 个。
 *  例如输入 1,2,3,4,5,6,7 和 8 这 8 个数字,则最小的 4 个数字为 1,2,3 和 4。
 *-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

// Using Heap sort


void siftup(int a[], int i, int n)
{
    while (i > 0) {
	int j = (i & 1 == 0 ? i-1 : i+1);
	int p = (i-1)>>1;
	if (j < n && a[j] < a[i]) 
	    i = j;
	if (a[i] < a[p]) swap(a,i , p);
	i = p;
    }
}

void siftdown(int a[], int i, int n)
{
    while (2*i+1 < n) {
	int l = 2*i+1;
	if (l+1 < n && a[l+1] < a[l]) 
	    l++;
	if (a[l] < a[i]) swap(a, i, l);
	i = l;
    }
}

void heapSort(int a[], ...)
{
    // ...
}
