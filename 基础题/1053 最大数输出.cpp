#include <stdio.h>
//输入三个整数，数与数之间以一个空格分开。 输出一个整数，即最大的整数。
int main() {
	int num1, num2, num3;
	printf("请输入三个整数，用空格分开: ");
	scanf("%d %d %d", &num1, &num2, &num3);
	
	int maxNum = (num1 > num2) ? ((num1 > num3) ? num1 : num3) : ((num2 > num3) ? num2 : num3);
	
	printf("最大的整数是: %d\n", maxNum);
	
	return 0;
}

