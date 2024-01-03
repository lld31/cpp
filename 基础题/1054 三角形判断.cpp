#include <stdio.h>
//三角形判断 给定三个正整数，分别表示三条线段的长度，判断这三条线段能否构成一个三角形。如果能构成三角形，则输出“yes”，否则输出“no”
int main()
{
	int side1, side2, side3;
	printf("请输入三条线段的长度，用空格分开: ");
	scanf("%d %d %d", &side1, &side2, &side3);
	
	//任意两边之和大于第三边
	if (side1 + side2 > side3 && side1 + side3 > side2 && side2 + side3 > side1) {
		printf("yes");
	} else {
		printf("no");
	}

	return 0;
}

