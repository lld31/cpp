#include <bits/stdc++.h>
using namespace std;
//点和正方形的关系 有一个正方形，四个角的坐标（x,y)分别是(1，-1)，(1，1)，(-1，-1)，(-1，1)，x是横轴，y是纵轴。
//写一个程序，判断一个给定的点是否在这个正方形内(包括正方形边界)。如果点在正方形内，则输出yes，否则输出no。

int main()
{
	int x,y;
	
	cout << "请输坐标点，用空格分开: ";
	cin>>x>>y;
	cout<<(x >= -1 && x <= 1 && y >= -1 && y <= 1 ? "yes" : "no");
	
	return 0;
}

