#include <stdio.h>
/*
	给定若干个四位数，求出其中满足以下条件的数的个数：个位数上的数字减去千位数上的数字，再减去百位数上的数字，再减去十位数上的数字的结果大于零。
*/
int main() {
	int n = 0, count = 0;
	printf("给定若干个四位数：");
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {

		int num;
		printf("请输入第 %d 个四位数：", i);
		scanf("%d", &num);

		//个位数字
		int n1 = num % 10;
		//十位数字
		int n2 = (num / 10) % 10;
		//百位数字
		int n3 = (num / 100) % 10;
		//千位数字
		int n4 = (num / 1000) % 10;

		if (n1 - n4 - n3 - n2 > 0) {
			count++;
		}

	}
	printf("满足以下条件的数的个数: %d", count);

	return 0;
}
