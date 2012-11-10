/* 
 * 问题描述：
 * 
 * 有五只猴子摘了一些桃子，打算隔天早上起来分了吃。 
 * 晚上的时候，第一只猴子偷偷起来把桃子分成五堆，还多了一个，就把多了的那个吃掉，并拿走了一堆。
 * 第二只猴子也偷偷起来将桃子分成了五堆，还是又多了一个，同样吃掉了这一颗桃子，并拿走了其中一堆。第三只、第四只、第五只猴子都做了同样的事情。请问这堆桃子最少有多少个？
 * 每只猴子每次的动作都一样，因此这个问题是一个典型的递归问题，C语言描述如下：
 */

#include <stdio.h>

/*
 *功  能：根据初始桃子数计算能够完成分配任务的猴子数
 *参  数：num-初始桃子数 monkeyNum-能够完成分配任务的猴子数
 *返回值：能够完成分配任务的猴子数
 */

int Peach(int num, int monkeyNum)
{
    if ((num-1) % 5 != 0) {
	return monkeyNum;
    }
    num = (num - 1) / 5 * 4;
    return Peach(num, monkeyNum+1);
}

int main(int argc, const char *argv[])
{
    int peachNum = 1;
    /*如果有5个猴子能完成分配任务，则满足题目要求*/
    while (Peach(peachNum, 0) != 5)
	peachNum++;
    printf("Peach Num = %d\n", peachNum);
    return 0;
}
