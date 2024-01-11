#include <stdio.h>
/*
	国王将金币作为工资，发放给忠诚的骑士。
	第1天，骑士收到一枚金币；
	之后两天(第2天和第3天)里，每天收到两枚金币；
	之后三天(第4、5、6天)里，每天收到三枚金币；
	之后四天(第7、8、9、10天)里，每天收到四枚金币……
	这种工资发放模式会一直这样延续下去：当连续 n 天每天收到 n 枚金币后，骑士会在之后的连续n+1天里，每天收到n+1枚金币(n为任意正整数)。
	你需要编写一个程序，确定从第一天开始的给定天数内，骑士一共获得了多少金币。 
【输入】一个整数（范围1到10000），表示天数
【输出】骑士获得的金币数。
【输入样例】6
【输出样例】14
*/
int main() {
	
	int day;
	printf("请输入一个整数 天数（范围1到10000）：");
	scanf("%d", &day);
	
	int sum = 0; // 骑士获得的总金币数
	int current_coins = 1; // 当前获取的金币数
	int days_left = day; // 剩余天数
	
	for (int i = 1; days_left > 0; ++i) {
		int coins_to_receive = (i <= days_left) ? i : days_left; // 计算当前这段时间内应该收到的金币数
		sum += coins_to_receive * current_coins; // 更新总金币数
		days_left -= i; // 减去已经计算过的天数
		current_coins++; // 更新当前获取的金币数
	}
	
	printf("%d",sum);
	
	return 0;
}
