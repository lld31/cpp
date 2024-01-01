#include <bits/stdc++.h>
using namespace std;
//简单计算器 一个最简单的计算器，支持+, -, *, / 四种运算。
//仅需考虑输入输出为整数的情况，数据和运算结果不会超过int表示的范围。
//然而：1. 如果出现除数为0的情况，则输出：Divided by zero! 
//2. 如果出现无效的操作符(即不为 +, -, *, / 之一），则输出：Invalid operator!
int main()
{
	int x, y;//声明两个整型变量，表示参与运算的数字
	char c;//声明字符型变量，表示运算符
	cout << "两个变量和计算符号（空格分开）: ";
	cin >> x >> y >> c;//输入变量
	switch(c)//switch选择语句，看变量c与哪个case后面的常量相等
	{
		case '+'://如果c是'+'
		cout << x + y;//输出x+y的结果
		break;
		case '-'://如果c是'-'
		cout << x - y;//输出x-y的结果
		break;
		case '*'://如果c是'*'
		cout << x * y;//输出x*y的结果
		break;
		case '/'://如果c是'/'
		if (y == 0)//如果除数是0
			cout << "Divided by zero!";//输出：除0，这是非法运算
		else
			cout << x / y;//输出x/y的结果
		break;
		default://如果运算符不是 + - * /
		cout << "Invalid operator!";//输出"非法运算符"
	}
	
	return 0;
}

