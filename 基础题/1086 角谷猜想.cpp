#include <stdio.h>
/*
	角谷猜想，是指对于任意一个正整数，如果是奇数，则乘3加1，如果是偶数，则除以2，得到的结果再按照上述规则重复处理，最终总能够得到1。
	如，假定初始整数为5，计算过程分别为16、8、4、2、1。
	程序要求输入一个整数，将经过处理得到1的过程输出来。
	【输入】一个正整数n(n≤2,000,000)。
	【输出】从输入整数到1的步骤，每一步为一行，每一部中描述计算过程。最后一行输出"End"。如果输入为1，直接输出"End"。
*/
int main() {
	int n;
	printf("角谷猜想 请输入一个正整数：");
	scanf("%d", &n);

	printf("%d  ", n); // 先打印初始的n值

	//如果大于1继续循环
	while (n > 1) {
		if (n % 2 == 1) {
			n = n * 3 + 1;
		} else {
			n = n / 2;
		}
		printf("%d  ", n);
	}

	return 0;
}
