#include <stdio.h>
#include <math.h>
/*
级数求和 已知：Sn=1＋1/2＋1/3＋…＋1/n。
显然对于任意一个整数k，当n足够大的时候，Sn大于k。
现给出一个整数k（1<=k<=15），要求计算出一个最小的n，使得Sn＞k。

*/
int main() {
	int k, n = 1;
	printf("级数求和 请输入一个正整数：");
	scanf("%d", &k);

	double sum = 1; //定义这个级数的和，并默认第一项为1

	while (sum < k) {
		n++;
		sum += 1.0 / n;
//		printf("%d %.4lf\n",n,sum);
		printf("计算中%d\n", n);
		system("cls") ;//清屏函数
	}

	printf("这个最小的级数项：%d", n);
	return 0;
}
