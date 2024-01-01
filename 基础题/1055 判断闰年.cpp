#include <bits/stdc++.h>
using namespace std;
//判断闰年 判断某年是否是闰年。如果公元a年是闰年输出Y，否则输出N。

int main()
{
	int year;
	cout << "请输年份（回车结束）: ";
	cin >> year;
	
	// ①年份能被4整除；②如果年份能被100整除，则年份必须能被400整除；
	// 能被4整除，且不能被100整除，或能被400整除。
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		cout << "Y";
	} else {
		cout << "N";
	}
	
	return 0;
}

