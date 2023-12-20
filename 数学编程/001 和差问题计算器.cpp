#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

int main()
{
	//头部提示
	cout<<"和差问题计算器v1.0  作者：李冻冻"<<endl;
	string separator(50, '-');//分隔线
	cout<<separator<<endl;
	cout<<separator<<endl;
	
	
	//输入 提示词
	string object1,object2,unit;
	cout<<"请输入第一个对象名称（少的）：";
	cin>>object1;
	cout<<"请输入第二个对象名称（多的）：";
	cin>>object2;
	cout<<"请输入对象的单位：";
	cin>>unit;
	
	//输入 计算数据
	int h,c,a,b;
	cout<<"请输入 和：";
	cin>>h;
	cout<<"请输入 差：";
	cin>>c;
	
	
	//计算
	cout<<separator<<endl;
	cout<<"开始计算…………"<<endl;
	a=(h-c)/2;
	b=h-a;
	
	//输出
	cout<<separator<<endl;
	cout<<"结果"<<endl;
	cout<<object1<<"："<<a<<unit<<endl;
	cout<<object2<<"："<<b<<unit<<endl;	
	
	
	cout<<separator<<endl;
	cout << "按任意键结束..." << endl;
	_getch();  // 等待用户按下键盘
	return 0;
}

