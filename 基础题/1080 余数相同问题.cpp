#include <stdio.h>
#include <math.h>
/*
	已知三个正整数a，b，c。
	现有一个大于1的整数x，将其作为除数分别除a，b，c，得到的余数相同。 
	请问满足上述条件的x的最小值是多少？数据保证x有解。
*/
int main() {
	int a,b,c,x; 
	printf("输入三个正整数："); 
	scanf("%d %d %d", &a,&b,&c);
	
	for (x = 2; ; x++) {
		
		printf("计算中%d\n",x);
		system("cls") ;//清屏函数
		
		if(a%x==b%x && b%x==c%x){
			printf("满足条件的x的最小值为：%d\n", x);
			break;
		}
		
		if (x > a || x > b || x > c) {
			printf("不存在满足条件的x值\n");
			break;
		}

	}
	return 0;
}
