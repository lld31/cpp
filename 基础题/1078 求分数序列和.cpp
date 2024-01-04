#include <stdio.h>
#include <math.h>
/*
求分数序列和
	有一个分数序列 q1/p1，q2/p2，q3/p3，q4/p4，q5/p5，.... ,其中qi+1=qi+pi， pi+1=qi，p1=1，q1=2。
	比如这个序列前6项分别是2/1,3/2,5/3,8/5,13/8,21/13。求这个分数序列的前n项之和。
【输入】输入有一行，包含一个正整数n(n≤30)。
【输出】输出有一行，包含一个浮点数，表示分数序列前n项的和，精确到小数点后4位。
*/
int main() {
	int n = 0; 
	printf("输入n的值(n≤30)："); 
	scanf("%d", &n);
	
	int p=1,q=2,tmp;
	
	double sum=0;
	
	for (int i = 1; i <= n; i++) {
		sum+=q/p;//使用指数，也可以使用符号运算
		
		tmp=p;
		p=q;
		q=tmp+q;
			
	}
	printf("分数序列前 %d 项的和: %.4lf",n,sum);//精确到小数点后4位
	return 0;
}
