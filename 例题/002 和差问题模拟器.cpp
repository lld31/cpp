#include <graphics.h>
#include <math.h>
int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, ""); // 初始化图形窗口
	
	int x = 200, y = 200; // 矩形的中心坐标
	int length = 100; // 矩形的长度
	int width = 20; // 矩形的宽度
	float angle = 0; // 初始角度
	
	while (true) { // 当没有键盘输入时循环
		cleardevice(); // 清空窗口
		
		// 画矩形
		bar(x - length/2, y - width/2, x + length/2, y + width/2);
		
		delay(50); // 延迟50毫秒
		angle += 0.1; // 每次旋转的角度增加0.1
		
		if (angle >= 2 * M_PI) { // 如果角度大于等于2π
			angle = 0; // 重置角度
		}
		
		// 旋转矩形
		setcolor(WHITE);
		rotate(x, y, x - length/2, y - width/2, angle);
	}
	
	closegraph(); // 关闭图形窗口
	return 0;
}
