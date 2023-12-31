#include <stdio.h>
#include<math.h>
/*
数1的个数 给定一个十进制正整数n(1≤n≤10000)，写下从1到n的所有整数，然后数一下其中出现的数字“1”的个数。
例如当n=2时，写下1,2。这样只出现了1个“1”；当n=12时，写下1，2，3，4，5，6，7，8，9，10，11，12。这样出现了5个“1”。
【输入】正整数n。1 ≤ n ≤ 10000。【输出】一个正整数，即“1”的个数。
【输入样例】12【输出样例】5

*/
int main() {
	int n,c=0;
	printf("请输入一个正整数(1≤n ≤10000)：");
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i) {
		//计数
		int count=0,temp=i;
		
		while (temp > 0) {
			if(temp%10==1){
				count++;
			}
			temp/=10;
		}
		c+=count;
	}

	printf("%d", c);

	return 0;
}
