#include <graphics.h>
using namespace std;
int main()
{
	//新建一个宽600 高500的窗体
	initgraph(600, 500);
	//窗体标题
	setcaption("李冷冷的第一个窗体!");
	//设置背景颜色
	setbkcolor(EGERGB(0xFF, 0xFF, 0xFF)); //白色
	
	
	getch();//等待按键
	closegraph();//关闭窗体
	return 0;
}
