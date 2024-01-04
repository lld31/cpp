#include <stdio.h>
/*
	含k个3的数
	输入两个正整数m和k，其中1<m<100000，1<k<5 ，
	判断m 能否被19整除，且恰好含有k个3，如果满足条件，则输出YES，否则，输出NO。
	例如，输入：43833 3，满足条件，输出YES。如果输入：39331 3，尽管有3个3，但不能被19整除，也不满足条件，应输出NO。
*/
int main() {
	int m, k, count = 0;
	printf("请输入两个正整数（m和k，其中1<m<100000，1<k<5）：");
	scanf("%d %d", &m, &k);

	//是否为19的倍数
	if (m % 19 == 0) {
		//是否含有k个3
		while (m > 0) {
			if (m % 10 == 3) {
				count++;
			}
			m /= 10;
		}

		if (count == k) {
			printf("YES");
		} else {
			printf("NO");
		}
	} else {
		printf("NO");
	}

	return 0;
}
