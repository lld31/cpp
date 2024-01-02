#include<bits/stdc++.h>
using namespace std;
//奇数求和 计算非负整数m到n(包括m和n)之间的所有奇数的和，其中，m 不大于 n，且n 不大于300。例如 m=3,n=12, 其和则为：3+5+7+9+11=35。
int main() {
	int m,n;
	cout << "分别输入两个非负整数m和n（且m<n,空格分开）:";
	cin >>m>>n;
	int sum=0;
	
	//处理头部，而没有必要一个个的判断每个数
	if (m % 2 == 0) {
		m++;  // 如果m是偶数，就从下一个奇数开始
	}
	
	//每2位一步，全是奇数
	for (int i = m; i <= n; i+=2) {
		sum+=i;
	}
	
	cout << "非负整数m到n(包括m和n)之间的所有奇数的和："<<sum<<endl;
	
	return 0;
}
