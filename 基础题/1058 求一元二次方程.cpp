#include <iostream> // 包含输入输出流库
#include <cmath> // 包含数学函数库
#include <iomanip> // 包含设置输出精度的库
using namespace std;
// 求一元二次方程 
//利用公式x1=$\frac{−b+\sqrt{b2−4ac}}{2a}$，x2=$\frac{−b+\sqrt{b2+4ac}}{2a}$，
// 求一元二次方程ax2+bx+c=0的根，其中a不等于0。结果要求精确到小数点后5位。

int main()
{
	double a, b, c;
	cout << "请输入一元二次方程的系数 a, b, c，用空格分开: ";
	cin >> a >> b >> c;
	
	double discriminant = b * b - 4 * a * c;
	if (discriminant > 0) {
		double root1 = (-b + sqrt(discriminant)) / (2 * a);
		double root2 = (-b - sqrt(discriminant)) / (2 * a);
		if (fabs(root1) < 0.00001) root1 = 0;
		if (fabs(root2) < 0.00001) root2 = 0;
		printf("方程的两个实根分别为: x1=%.5f 和 x2=%.5f\n", root1, root2);
		
	} else if (discriminant == 0) {
		double root = -b / (2 * a);
		if (fabs(root) < 0.00001) root = 0;
		printf("方程有一个实根: x1=x2=%.5f\n", root);
		
	} else {
		double realPart = -b / (2 * a);
		double imaginaryPart = sqrt(-discriminant) / (2 * a);
		if (fabs(realPart) < 0.00001) realPart = 0;
		printf("方程的两个虚根分别为: x1=%.5f+%.5fi 和 x2=%.5f-%.5fi\n", realPart, imaginaryPart, realPart, imaginaryPart);
		
	}
	
	return 0;
}

