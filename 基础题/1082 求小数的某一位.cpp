#include <stdio.h>
/*
	求小数的某一位
	分数a/b化为小数后，小数点后第n位的数字是多少？
	0<a<b<100，1≤n≤10000。
*/
int main() {

	int a, b, n, t;
	printf("请分别输入分数的分子与分母（空格分开）：");
	scanf("%d %d", &a, &b);

	printf("请输入取的第几位数字：");
	scanf("%d", &n);

	//把小数升一位就是乘以10
	//效率上可以直接使用函数(a*pow(10,n)/b)%10;，本次使用循环。
	for (int i = 1; i <= n; i++) {
		a *= 10;
		t = (a / b) % 10;
	}

	printf("小数点后第n位的数字是 %d \n", t);

	return 0;
}
