#include <stdio.h>
//班上有学生若干名，给出每名学生的年龄（整数），求班上所有学生的平均年龄，保留到小数点后两位。
int main() {
	int numStudents;
	printf("请输入学生人数: ");
	scanf("%d", &numStudents);
	
	int totalAge = 0; // 用于存储所有学生年龄的总和
	
	printf("请输入每名学生的年龄，用空格分开: ");

	for (int i = 0; i < numStudents; i++) {
		int age;
		scanf("%d", &age);
		totalAge += age; // 将输入的年龄累加到总和中
	}
	
	double averageAge = (double)totalAge / numStudents; // 使用强制类型转换将 totalAge 转换为 double 类型，然后计算平均年龄
	printf("班上所有学生的平均年龄为:%.2f\n", averageAge);//，设置小数点后两位的精度

	return 0;
}
