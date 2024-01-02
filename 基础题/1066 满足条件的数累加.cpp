#include<bits/stdc++.h>

using namespace std;

//满足条件的数累加 将正整数m和n之间(包括m和n)能被17整除的数累加，其中，0<m<n<1000。

int main() {
	int m,n;
	cout << "分别输入两个非负整数m和n（且0<m<n<1000,空格分开）:";
	cin >>m>>n;
	int sum=0;
	
	//处理开始的第一个数，是否为17的倍数，没有必要一个个的判断每个数是否被17整除
	if (m%17> 0) {
		m+=(17-m%17);//判断出最小的17的倍数，从这个数开始
	}
	
	//每步17
	for (int i = m; i <= n; i+=17) {
		sum+=i;
		
		cout<<i<<endl;
	}
	
	cout << "正整数m和n之间(包括m和n)能被17整除的数累加和："<<sum<<endl;
	
	return 0;
}
