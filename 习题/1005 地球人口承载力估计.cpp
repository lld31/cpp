#include <bits/stdc++.h>
using namespace std;
int main()
{
	double x,y,a,b;
	scanf("%lf %lf %lf %lf", &x, &a, &y, &b);
	printf("%.2f", (x*a - y*b)/(a-b)); 
	return 0;
}

