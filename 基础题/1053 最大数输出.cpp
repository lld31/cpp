#include <bits/stdc++.h>
using namespace std;
//输入三个整数，数与数之间以一个空格分开。 输出一个整数，即最大的整数。
//刻意的使用switch
int main()
{
	int num1,num2,num3;
	
	cout << "请输入三个整数，用空格分开: ";
	cin >> num1 >> num2 >> num3;

	
	//这里使用switch,结合三目运算嵌套
	int maxNum;
	switch (num1>num2?(num1>num3?1:3):(num2>num3?2:3)) {
	case 1:
		maxNum=num1;
		break;
	case 2:
		maxNum=num2;
		break;
	default:
		maxNum=num3;
		break;
	}
	
	//可以使用最效率的方法max()函数
	//max是C++标准库中的一个函数，它接受一个参数列表，并返回参数中的最大值
	//int maxNum = max({num1, num2, num3});
	

	cout << "最大的整数是: " << maxNum << endl;

 
	return 0;
}

