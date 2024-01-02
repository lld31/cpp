#include<bits/stdc++.h>
using namespace std;
//求整数的和与均值 读入n(1≤n≤10000)个整数，求它们的和与均值。
int main() {
	int num;
	cout << "请输入整数个数(1≤n≤10000):";
	cin >> num;
	
	double data[num]; // 声明一个大小为n的数组来存放样本数据
	double sum = 0;
	for (int i = 0; i < num; i++) {
		cout << "请输入第" << i+1 << "个数据：";
		cin >> data[i];
		sum += data[i];
	}
	
	double mean = sum/num; // 计算均值
	
	cout << "整数的和: " <<sum<<",均值："<< fixed << setprecision(4) << mean << endl; // 使用 cout 输出结果并设置小数点后的精度
	
	return 0;
}
