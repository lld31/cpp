#include <stdio.h>
//判断闰年 判断某年是否是闰年。如果公元a年是闰年输出Y，否则输出N。
int main()
{
	int year;

	printf("请输年份: ");
	scanf("%d", &year);
	
	// 能被400整除 或 能被4整除且不能被100整除。
	if (year % 400 == 0  || (year % 4 == 0 && year % 100 != 0) ) {
		printf("Y");
	} else {
		printf("N");
	}
	
	return 0;
}

