#include<bits/stdc++.h>

using namespace std;

//给出一个整数a和一个正整数n(−1000000≤a≤1000000，1≤n≤10000)，求乘方a^n，即乘方结果。最终结果的绝对值不超过1000000。

int main() {
	int a,n;
	cout << "输入底数(-1000000≤a≤1000000)和指数(1≤n≤10000)(空格分开):";
	cin >>a>>n;
	
	//如果是效率使用，可以直接使用函数 pow(a, n);
	
	int result  = 1;
	for (int i = 0; i < n; i++) {
		result*=a;
		if (abs(result) > 1000000) {
			cout << "乘方结果超过1000000" << endl;
			break;
		}
	}
	
	if (abs(result) <= 1000000) {
		cout << "乘方结果为: " << result << endl;
	}
	
	return 0;
}
