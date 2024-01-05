#include <stdio.h>
#include <math.h>
/*
	计算多项式的值 假定多项式的形式为x^n+x^(n−1)+…+x^2+x+1，请计算给定单精度浮点数x和正整数n值的情况下这个多项式的值。
	x在double范围内，n≤1000000。多项式的值精确到小数点后两位，保证最终结果在double范围内。
【输入】输入仅一行，包括x和n，用单个空格隔开。x在float范围内，n ≤ 1000000。
【输出】输出一个实数，即多项式的值，精确到小数点后两位。保证最终结果在float范围内。
*/
int main() {
	float x,temp, sum = 1;
	int n;
	printf("请输入单精度浮点数x 一个正整数n：");
	scanf("%f %d", &x, &n);

	for (int i = 1; i <= n; i++) {

		//使用指数幂函数，也可以直接使用循环
		//sum += pow(x, i);x
		temp=1;
		for(int j=1;j<=i;++j){
			temp*=x;
		}
		sum +=temp;
	}

	printf("多项式的值：%.2f", sum);

	return 0;
}
