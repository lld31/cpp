#include <stdio.h>

//给定k(1<k<100)个正整数，其中每个数都是大于等于1，小于等于10的数。写程序计算给定的k个正整数中，1，5和10出现的次数。

int main() {
	int k;

	printf("你要输入的正整数个数（1<k<100）: ");
	scanf("%d", &k);

	int sum1 = 0, sum5 = 0, sum10 = 0;

	for (int i = 0; i <= k; i++) {

		int data;

		printf("请输入第 %d 个数（大于等于1，小于等于10）：", i + 1);
		scanf("%d", &data);

		if (data == 1)
			sum1++;
		else if (data == 5)
			sum5++;
		else if (data == 10)
			sum10++;

	}

	printf("1出现 %d 次数、5出现 %d 次数、10出现 %d 次数", sum1, sum5, sum10);

	return 0;
}
