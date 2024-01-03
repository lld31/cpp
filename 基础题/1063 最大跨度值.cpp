#include <stdio.h>
#include <limits.h> //使用 INT_MAX 和 INT_MIN 宏定义

// 最大跨度值 给定一个长度为n的非负整数序列，请计算序列的最大跨度值(最大跨度值 = 最大值减去最小值)。

int main() {
	int num;
	printf("请输入非负整数长度序列数量: ");
	scanf("%d", &num);
	
	//设置临时最大值mx,最小值mi
	int data,mi=INT_MAX,mx=INT_MIN;//INT_MAX是一个宏，表示int类型的最大值。头文件<climits>中，其值2^31 - 1。表示int类型能够表示的最大正数值。
	

	for (int i = 0; i < num; i++) {
		printf("请输入第%d个长度：", i+1);
		scanf("%d", &data);
		
			//也可以使用 max(mx, data) 可以更高效
		if (data > mx) mx = data;
		if (data < mi) mi = data;
	}
	
	printf("最大跨度值: %d\n", mx - mi);
	
	return 0;
}
