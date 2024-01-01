#include <bits/stdc++.h>
using namespace std;
//三角形判断 给定三个正整数，分别表示三条线段的长度，判断这三条线段能否构成一个三角形。如果能构成三角形，则输出“yes”，否则输出“no”
int main()
{
	int side1, side2, side3;
	cout << "请输入三条线段的长度，用空格分开: ";
	cin >> side1 >> side2 >> side3;
	
	//任意两边之和大于第三边
	if (side1 + side2 > side3 && side1 + side3 > side2 && side2 + side3 > side1) {
		cout << "yes" << endl;
	} else {
		cout << "no" << endl;
	}

	
	return 0;
}

