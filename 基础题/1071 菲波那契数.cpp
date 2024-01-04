#include <stdio.h>
#include <math.h>

//菲波那契数列是指这样的数列: 数列的第一个和第二个数都为1，接下来每个数都等于前面2个数之和。给出一个正整数k，要求菲波那契数列中第k个数是多少。

int main() {
	int k, a = 1, b = 1, fibonacci;

	printf("输入你要的第几个菲波那契数: ");
	scanf("%d", &k);

	switch (k) {
		case 1:
			fibonacci = 1;
			break;
		case 2:
			fibonacci = 1;
			break;
		default:
			for (int i = 3; i <= k; i++) {
				fibonacci = a + b;
				a = b;
				b = fibonacci;
				if (fibonacci < 0) {
					printf("斐波那契数列第 %d 项已经超过了int类型的最大值\n", i);
					break;
				}
			}
			break;
	}

	//可以使用 菲波那契数列通项公式

//	double s=(1+sqrt(5))/2;
//	double r=(1-sqrt(5))/2;
//
//	fibonacci=(int)(1 / sqrt(5) * (pow(s, k) - pow(r, k)));
//
	if (fibonacci > 0) {
		printf("斐波那契数列第 %d 项的值为: %d\n", k, fibonacci);
	}

	return 0;
}
