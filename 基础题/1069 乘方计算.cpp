#include <stdio.h>
#include <math.h> //数学函数库
//给出一个整数a和一个正整数n(−1000000≤a≤1000000，1≤n≤10000)，求乘方a^n，即乘方结果。最终结果的绝对值不超过1000000。

int main() {
	int a, n;

	printf("输入底数(-1000000≤a≤1000000): ");
	scanf("%d", &a);
	printf("输入指数(1≤n≤10000): ");
	scanf("%d", &n);

	//如果是效率使用，可以直接使用函数 pow(a, n);

	int result  = 1;
	for (int i = 0; i < n; i++) {
		result *= a;
		if (abs(result) > 1000000) {
			printf("乘方结果超过1000000\n");
			break;
		}
	}

	if (abs(result) <= 1000000) {
		printf("%d^%d乘方结果为：%d\n", a, n, result);
	}

	return 0;
}
