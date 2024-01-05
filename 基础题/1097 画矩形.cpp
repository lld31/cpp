#include <stdio.h>
#include <math.h>
/*
画矩形：根据参数，画出矩形。
输入四个参数：前两个参数为整数，依次代表矩形的高和宽（高不少于3行不多于10行，宽不少于5列不多于10列）；
第三个参数是一个字符，表示用来画图的矩形符号；
第四个参数为1或0，0代表空心，1代表实心。
*/
int main() {
	int h, b;
	printf("请输入矩形的高和宽(空格隔开)：");
	scanf("%d %d", &h, &b);

	getchar(); // 吃掉换行符，防止影响下一个字符的读取

	char ch;
	printf("请输入画图的矩形符号：");
	scanf("%c", &ch);

	int d = 0;
	printf("请输入是空心还是实心（1或0）：");
	scanf("%d", &d);

	if (d == 1) {
		//实心
		for (int i = 1; i <= h; ++i) {
			for (int j = 1; j <= b; ++j) {
				printf("%c", ch);
			}
			printf("\n");
		}
	} else {
		//空心
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= b; j++) {
				// 四条边均按条件输出
				if ((i == 1) || (i == h) || (j == 1) || (j == b)) 
					printf("%c", ch);
				else
					printf(" ");
			}
			printf("\n"); // 使用printf替换cout以输出换行符
		}
	}

	return 0;
}
