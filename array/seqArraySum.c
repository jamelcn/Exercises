
/*-----------------------------------------------------------------------------
 *  求子数组的最大和
 *  题目:
 *  输入一个整形数组,数组里有正数也有负数。 数组中连续的一个或多个整数组成一个子数组,每个子数组都有一个和。 求所有子数组的和的最大值。要求时间复杂度为 O(n)。
 *  例如输入的数组为 1, -2, 3, 10, -4, 7, 2, -5,和最大的子数组为 3, 10, -4, 7, 2, 因此输出为该子数组的和 18。
 *-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int maxSubarray(int a[], int size)
{
    if (size <= 0) printf("error array size");
    int sum = 0;
    int max = - (1 << 31);         /* Attention!! not zero */
    int cur = 0;
    while (cur < size) {
    	sum += a[cur++];
	if (sum > max) {
		max = sum;
	} else if (sum < 0) {                   /* presumed to have positive No */
		sum = 0;
	}
    }
    return  max;
}

int main(int argc, const char *argv[])
{
    int ia[10] = {0};
    int i = 0;
    while((scanf("%d", &ia[i++]) != -1) && i < 10);
    printf("value of ia:\n");
    for (i = 0; i < 10; i++) {
    	printf("%d\t", ia[i]);
    }
    printf("\n");
    printf("Max Subarray value of ia: %d", maxSubarray(ia, 10));
    

    printf("\n");
    return 0;
}
