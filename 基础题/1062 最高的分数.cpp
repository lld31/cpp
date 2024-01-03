#include <stdio.h>
//最高的分数 孙老师讲授的《计算概论》这门课期中考试刚刚结束，他想知道考试中取得的最高分数。
//因为人数比较多，他觉得这件事情交给计算机来做比较方便。你能帮孙老师解决这个问题吗？
int main() {
	int num;
	printf("请输入学生个数: ");
	scanf("%d", &num);
	
	//设置临时最大值变量mx，mx的初始值应该小于等于所有参与比较的数字
	//循环n次读入数据，如果读入的数据a比mx大，那么把a赋值给mx
	//循环结束后，mx就是n个数字中的最大值
	
	int data,mx = 0;
	for (int i = 0; i < num; i++) {
		printf("请输入第 %d 个人的成绩",i+1);
		scanf("%d", &data);
		if (data>mx)
			mx=data;
	}
	
 	printf("最大值：%d\n", mx);
	
	return 0;
}
