#include<bits/stdc++.h>
using namespace std;
//奥运奖牌计数 2008年北京奥运会，A国的运动员参与了n天的决赛项目(1≤n≤17)。
//现在要统计一下A国所获得的金、银、铜牌数目及总奖牌数。输入第1行是A国参与决赛项目的天数n，其后n行，
//每一行是该国某一天获得的金、银、铜牌数目。输出4个整数，为A国所获得的金、银、铜牌总数及总奖牌数。
int main() {
	int n;
	cout << "A国参与决赛项目的天数:";
	cin >> n;
	
	
	int sum_g=0,sum_s=0,sum_c=0;
	
	for (int i = 0; i < n; i++) {
		int g,s,c;
		
		cout << "请输入第" << i+1 << "天金银铜牌数量用空格分开：";
		cin >>g>>s>>c;
		
		sum_g+=g;
		sum_s+=s;
		sum_c+=c;
		
	}
	
	
	cout << "A国所获得的金牌"<<sum_g<<"个、银牌"<<sum_s<<"个、铜牌"<<sum_c<<"个，总奖牌数: " <<sum_g+sum_c+sum_s<<"个"<<endl;
	
	return 0;
}
