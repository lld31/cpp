#include <stdio.h>
#include <math.h>
/*
	鸡尾酒疗法，指“高效抗逆转录病毒治疗”。人们在鸡尾酒疗法的基础上又提出了很多种改进的疗法。
	为了验证这些治疗方法是否在疗效上比鸡尾酒疗法更好，可用通过临床对照实验的方式进行。
	假设鸡尾酒疗法的有效率为x，新疗法的有效率为y，如果y-x大于5%，则效果更好，如果x-y大于5%，则效果更差，否则称为效果差不多。
	下面给出n组临床对照实验，其中第一组采用鸡尾酒疗法，其他n-1组为各种不同的改进疗法。请写程序判定各种改进疗法效果如何。
*/

int main() {

	int n, t, e;//t：病例总数 e：疗效有效病例数
	
	printf("输入数据总组数: ");
	scanf("%d",&n);
	
	printf("输入第1组采用鸡尾酒疗法病例总数: ");
	scanf("%d",&t);
	
	printf("输入第1组采用鸡尾酒疗法疗效有效病例数: ");
	scanf("%d",&e);
	
	double x = (double)e / t, y;//x:鸡尾酒疗法治愈率 y:其它疗法治愈率
	
	for(int i = 1; i < n; ++i)//输入n-1组数据
	{

		printf("输入第 %d 组改进疗法病例总数: ",i+1);
		scanf("%d",&t);
		
		printf("输入第 %d 组改进疗法疗效有效病例数: ",i+1);
		scanf("%d",&e);
		
		y = (double)e / t;
		if(y - x > 0.05)
			printf("效果更好better\n");
		else if(x - y > 0.05)
			printf("效果更差worse\n");
		else
			printf("效果差不多same\n");
	}

	
	return 0;
}
