#include <stdio.h>
#include <math.h>
/*
	输入一个正整数n，求第n小的质数。
	【输入】一个不超过10000的正整数n。
	【输出】第n小的质数。
	【输入样例】10【输出样例】29
*/
int main() {
	int n;
	printf("请输入一个不超过10000的正整数：");
	scanf("%d", &n);
	int count = 0;

	for (int i = 2;; ++i) {

		int is_prime = 1; // 假设当前数i是质数

		//判断i是否为质数
		for (int j = 2; j <= sqrt(i); ++j) {
			if (i % j == 0) { //找到被整除的
				is_prime = 0; // 如果找到被整除的数，则标记i不是质数
				break;
			}
		}

		//is_prime=0等价于假值
		if (is_prime) {
			//如果是质数，开始计数
			count++;
			if (count == n) {
				printf("第 %d 小的质数为 %d\n", count, i);
				return 0; // 直接返回以结束程序
			}
		}
	}
	return 0;
}
