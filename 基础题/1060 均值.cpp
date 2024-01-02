#include<bits/stdc++.h>
using namespace std;
//均值 给出一组样本数据，包含n个浮点数，计算其均值，精确到小数点后4位。
int main() {
	int num;
	cout << "给出一组样本个数: ";
	cin >> num;
	
	double data[num]; // 声明一个大小为n的数组来存放样本数据
	double sum = 0;
	for (int i = 0; i < num; i++) {
		cout << "请输入第" << i+1 << "个数据：";
		cin >> data[i];
		sum += data[i];
	}
	
	double mean = sum/num; // 计算均值
	
	cout << "本组样本均值: " << fixed << setprecision(4) << mean << endl; // 使用 cout 输出结果并设置小数点后的精度
	
	return 0;
}
