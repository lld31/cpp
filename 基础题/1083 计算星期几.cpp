#include <stdio.h>
/*
	计算星期几
	假设今天是星期日，那么过a^b天之后是星期几
	【输入】两个正整数a，b，中间用单个空格隔开。0<a≤100,0<b≤10000。
	【输出】一个字符串，代表过a^b天之后是星期几。
	其中，Monday是星期一，Tuesday是星期二，Wednesday是星期三，Thursday是星期四，Friday是星期五，Saturday是星期六，Sunday是星期日。
*/
int main() {

	int day;
	printf("请输入今天是星期（数字）：");
	scanf("%d", &day);


	int a, b, s;
	printf("请输入过了多少天（两个正整数 0<a≤100,0<b≤10000）：");
	scanf("%d %d", &a, &b);


	//使用循环计算幂,也可以直接使用pow函数
	for (int i = 0; i < b; ++i)
		s = (s * a) % 7;


	switch ((s + day) % 7) {
		case 0:
			printf("Sunday");
			break;
		case 1:
			printf("Monday");
			break;
		case 2:
			printf("Tuesday");
			break;
		case 3:
			printf("Wednesday");
			break;
		case 4:
			printf("Thursday");
			break;
		case 5:
			printf("Friday");
			break;
		case 6:
			printf("Saturday");
			break;
	}

	return 0;
}
