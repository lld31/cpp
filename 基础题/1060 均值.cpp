#include <stdio.h>
//均值 给出一组样本数据，包含n个浮点数，计算其均值，精确到小数点后4位。
int main() {
	int num;
	printf("给出一组样本个数: ");
	scanf("%d", &num);
	
	double data[num]; // 声明一个大小为n的数组来存放样本数据
	double sum = 0;
	for (int i = 0; i < num; i++) {

		printf("请输入第 %d 个数据",i+1);
		scanf("%lf", &data[i]);

		sum += data[i];
	}
	
	printf("本组样本均值:%.4lf\n", sum/num);//，计算均值精确到小数点后4位
	
	return 0;
}
