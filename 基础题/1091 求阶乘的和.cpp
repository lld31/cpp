#include <stdio.h>
/*
	给定正整数n，求不大于n的正整数的阶乘的和（即求1!+2!+3!+...+n!），输出阶乘的和。。
*/
int main() {
	int n, count = 1, sum = 0, j = 1;
	printf("请输入一个正整数：");
	scanf("%d", &n);

	while (n >= count) {
		for (int i = 1; i <= count; i++) {
			j *= i;
		}
		sum += j;
		printf("%d %d %d\n", count, j, sum);
		count++;
	}

	printf("阶乘的和：%d", sum);

	return 0;
}
