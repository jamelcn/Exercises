/*
 *
 *【面试题】找出字符串中连续出现次数最多的子串
 *分类： 【笔试面试】 【算法】 2012-07-28 23:43 741人阅读 评论(9) 收藏 举报
 *
 *微软的一道面试题：
 *
 *如：abcbcbcabc,这个连续出现次数最多的字串是bc
 *
 *一，考虑边界问题。
 *二，实现优化笛卡尔积组合，
 *总体我是这样想的：就是纵向切出字符串的连续组合集合，在横向一对一跳跃比较集合元素。
 *例如：abcbcabc 
 *一，纵向切：
 *得到所有字符串组合，注意：这里要求的是最多连续子字符串，其实就是优化笛卡尔积的原则，也是边界。
 *  字符串共8位，以子串的长度为1，从字符串第一位开始切，且称为切：
 *1----从a开始切：(字符串为abcbcabc )
 *第一次切出a子字符串，得到： a和bcbcabc，
 *第二次切出ab子字符串，得到： ab和cbcabc，
 *第三次切出abc子字符串，得到： abc和bcabc，
 *第四次切出abcb子字符串，得到： abcb和cabc，
 *第五次切出abcbc子字符串，得到： abcbc和abc，
 *第六次切出abcbca子字符串，得到： abcbca和bc，
 *第七次切出abcbcab子字符串，得到： abcbcab和c，
 *第八次切出abcbcabc子字符串，得到： abcbcabc，
 *得到a1集合数组（且为数组吧）
 *元素为：a, ab, abc, ......
 *
 *2---再从b开始切：：(字符串为abcbcabc )
 *第一次切出b子字符串，得到： b和cbcabc，
 *第二次切出bc子字符串，得到： bc和bcabc，
 *第三次切出bcb子字符串，得到： bcb和cabc，
 *第四次切出bcbc子字符串，得到： bcbc和abc，
 *第五次切出bcbca子字符串，得到： bcbca和bc，
 *第六次切出bcbcab子字符串，得到： bcbcab和c，
 *第七次切出bcbcabc子字符串，得到： bcbcabc
 *得到b2集合数组（且为数组吧）
 *元素为：b, bc, bcb ,......
 *
 *3---再从c开始切： (字符串为abcbcabc )
 *第一次切出c子字符串，得到： c和bcabc，
 *第二次切出cb子字符串，得到： cb和cabc，
 *第三次切出cbc子字符串，得到： cbc和abc，
 *第四次切出cbca子字符串，得到： cbca和bc，
 *第五次切出cbcab子字符串，得到： cbcab和c，
 *第六次切出cbcabc子字符串，得到： cbcabc
 *得到b3集合数组（且为数组吧）
 *元素为：c, cb, cbc ,......
 *
 *4----再从b开始切： (字符串为abcbcabc )
 *第一次切出b子字符串，得到： b和cabc，
 *第二次切出bc子字符串，得到： bc和abc， 
 *第三次切出bca子字符串，得到： bca和bc，
 *第四次切出bcab子字符串，得到： bcab和c，
 *第五次切出bcabc子字符串，得到： bcabc
 *得到b4集合数组（且为数组吧）
 *元素为：b, bc, bca ,......
 *
 *5----再从c开始切： (字符串为abcbcabc )
 *第一次切出c子字符串，得到： c和abc，
 *第二次切出ca子字符串，得到： ca和bc， 
 *第三次切出cab子字符串，得到： cab和c，
 *第四次切出cabc子字符串，得到： cabc
 *得到c5集合数组（且为数组吧）
 *元素为：c, ca, cab ,......
 *
 *6----再从a开始切： (字符串为abcbcabc )
 *第一次切出a子字符串，得到： a和bc，
 *第二次切出ab子字符串，得到： ab和c， 
 *第三次切出abc子字符串，得到： abc，
 *得到a6集合数组（且为数组吧）
 *元素为：a, ab, abc 
 *
 *7----再从b开始切： (字符串为abcbcabc )
 *第一次切出b子字符串，得到： b和c，
 *第二次切出bc子字符串，得到： bc, 
 *得到b7集合数组（且为数组吧）
 *元素为：b, bc
 *
 *8----再从c开始切： (字符串为abcbcabc )
 *第一次切出c子字符串，得到： c
 *
 *得到c8集合数组（且为数组吧）
 *元素为：c
 *
 *2，横向比：
 *将a的所有切点按切的顺序保存到称为a1集合数组中（且为数组吧）
 *将b的所有切点按切的顺序保存到称为b2集合数组中（且为数组吧）
 *。。。依次类推到完。
 *得到如下8个集合：（字符串为abcbcabc ）
 *行数/列数 1 2 3 4 5 6 7 8
 *  1 a1: a, ab, abc, abcb, abcbc, abcbca , abcbcab, abcbcabc;
 *  2 b2: b, bc, bcb , bcbc, bcbca, bcbcab, bcbcabc;
 *  3 c3: c, cb, cbc , cbca, cbcab, cbcabc ;
 *  4 b4: b, bc, bca , bcab, bcabc;
 *  5 c5: c, ca, cab , cabc;
 *  6 a6: a, ab, abc ;
 *  7 b7: b, bc;
 *  8 c8: c;
 *将a1集合，b2集合。。。等全部集合横向比较:
 *即将列1比较,列2比较跳跃1行比较，列3跳跃2行比较，列3跳跃3行比较。。。。到完；因为要求的是最多连续子字符串，所以要跳跃！
 *得到相同字符串记数最大值，即求出出现次数最多的子串。
 *比较方式：
 *正于前面所说，要求的是最多连续子字符串。其实就是优化笛卡尔积的原则，也是边界。所以我们要做的是将所有集合一对一比较，不是多对多或其他（更简单的理由：位数不同，无需比较）。
 *多位子字符串一对一比较时候，例如 ab属于a集合和b集合的bc比较，显然没有意义。需要跳跃比较（且这样说吧，呵呵）。跳跃是有规律的。很显然就不说了。
 *之所以纵切，是为了解决横比较带来的优化问题
 */
#include <stdio.h>
#include <string.h>

int count = 0;
char sub_str[256];

void find_str(char* str)
{
	int str_len = strlen(str);
	int i, j, k;
	int tmp_cnt = 0;

	for (i = 0; i < str_len; i++) {
		for (j = i + 1; j < str_len; j++) {
			tmp_cnt = 1;
			int n = j - i;
			if (strncmp(&str[i], &str[j], n) == 0) {
				++tmp_cnt;
				for (k = j+n; k < str_len; k += n) {
					if (strncmp(&str[i], &str[k], n) == 0) {
						++tmp_cnt;
					}
					else
						break;
				}
				if (count < tmp_cnt) {
					count = tmp_cnt;
					memcpy(sub_str, &str[i], n);    /* record the sub string */
				}
			}
		}
	}
}

int main(int argc, const char *argv[])
{
	char str[100] = "abcbcbcabc";
	/*fgets(str, sizeof(str), stdin);*/
	find_str(str);
	printf("%d, %s\n", count, sub_str);
	return 0;
}
