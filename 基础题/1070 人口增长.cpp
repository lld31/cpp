#include <stdio.h>

//我国现有x亿人口，按照每年0.1%的增长速度，n年后将有多少人？保留小数点后四位。

int main() {
	int n;
	double x;


	printf("输入几年后（年）: ");
	scanf("%d", &n);
	printf("输入现有人口（亿）: ");
	scanf("%lf", &x);

	//指数增长，也可以直接使用 x*(1+0.001)^n，本单习题才使用for

	for (int i = 0; i < n; i++) {
		x *= 1 + 0.001;
	}

	printf("年后将有 %.4lf 亿人 ", x);
	return 0;
}
