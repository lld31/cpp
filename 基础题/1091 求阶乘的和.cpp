#include <stdio.h>
/*
	给定正整数n，求不大于n的正整数的阶乘的和（即求1!+2!+3!+...+n!），输出阶乘的和。
	【输入】输入有一行，包含一个正整数n（1 < n < 12）。
	【输出】输出有一行：阶乘的和。
*/
int main() {
	int n, count = 1, sum = 0;
	printf("请输入一个正整数：");
	scanf("%d", &n);

	while (n >= count) {
		int j = 1; // 重置j为1
		for (int i = 1; i <= count; i++) {
			j *= i;
		}
		sum += j;
		count++;
	}

	printf("阶乘的和：%d", sum);

	return 0;
}
