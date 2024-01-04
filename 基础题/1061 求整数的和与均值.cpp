#include <stdio.h>
//求整数的和与均值 读入n(1≤n≤10000)个整数，求它们的和与均值。
int main() {
	int num;
	printf("请输入学生人数: ");
	scanf("%d", &num);

	int data[num]; // 声明一个大小为n的数组来存放样本数据
	int sum = 0;
	for (int i = 0; i < num; i++) {
		printf("请输入第 %d 个数据", i + 1);
		scanf("%d", &data[i]);
		sum += data[i];
	}

	printf("整数的和：%d,均值：%.4lf\n", sum, double(sum) / num); //，计算均值精确到小数点后4位

	return 0;
}
