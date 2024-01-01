#include<bits/stdc++.h>
using namespace std;
//班上有学生若干名，给出每名学生的年龄（整数），求班上所有学生的平均年龄，保留到小数点后两位。
int main() {
	int numStudents;
	cout << "请输入学生人数: ";
	cin >> numStudents;
	
	int totalAge = 0; // 用于存储所有学生年龄的总和
	
	cout << "请输入每名学生的年龄，用空格分开: ";
	for (int i = 0; i < numStudents; i++) {
		int age;
		cin >> age;
		totalAge += age; // 将输入的年龄累加到总和中
	}
	
	double averageAge = (double)totalAge / numStudents; // 使用强制类型转换将 totalAge 转换为 double 类型，然后计算平均年龄
	cout << "班上所有学生的平均年龄为: " << fixed << setprecision(2) << averageAge << endl; // 使用 cout 输出结果，设置小数点后两位的精度

	return 0;
}
