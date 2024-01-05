#include <stdio.h>
/*
利用公式e=1+1/1!+1/2!+1/3!+...+1/n! ，求e的值，要求保留小数点后10位。
【输入】输入只有一行，该行包含一个整数n（2≤n≤15），表示计算e时累加到1/n!
【输出】输出只有一行，该行包含计算出来的e的值，要求打印小数点后10位。
*/
int main() {
	int n;
	printf("请输入一个正整数（2≤n≤15）：");
	scanf("%d", &n);

	double sum = 1;

	for (int count = 1; count <= n; count++) {

		//计算阶乘
		double factorial  = 1; // 重置j为1
		for (int i = 1; i <= count; i++) {
			factorial *= i;
		}

		sum += 1.0 / factorial ;//转成double类型
	}

	printf("e的值：%.10lf", sum);

	return 0;
}
