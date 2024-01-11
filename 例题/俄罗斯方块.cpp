/*********************************************************************
  《俄罗斯方块》（Tetris， 俄文：Тетрис）是一款由俄罗斯人阿列克谢·帕基特诺夫
  于1984年6月发明的休闲游戏。基本规则是移动、旋转和摆放游戏自动输出的各种方块，
  使之排列成完整的一行或多行并且消除得分。
  
  版本2：定义结构体，设定结构体数组保存初值
 *********************************************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
using namespace std;

//定义全局变量
const int HT = 18, WD = 10; //游戏容器的高度(Height)和宽度(Width)。
char map[HT + 4][WD + 2] = {0};   //表示游戏容器的二维字符数组
char C0 = ' ', CW = '#', CB = '$', CF = '*'; //字符常量：空白、器壁、方格和满行
const int X0 = 10, Y0 = 1;   //绘制游戏容器时左上角的坐标(X0, Y0)

void gotoxy(short x, short y) {  //控制台窗口光标定位
    static COORD crd;  //定义 COORD 类型(窗口坐标)的静态局部变量 crd
    crd.X = x;
    crd.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), crd);
    return;
}

void showcursor(bool visible) { //显示或隐藏光标
    CONSOLE_CURSOR_INFO cursor = {20, visible};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

void drawBoard(int level, int score, int speed) {	//绘制游戏界面
	gotoxy(X0 + 4, Y0 - 1);
	cout << "俄 罗 斯 方 块"; //打印游戏名称
	for (int iy = 2, ix = 0; iy < HT + 4; iy++) {	//行号为 2 -- HT+4
		gotoxy(X0, Y0 + iy - 2);
		for (ix = 0; ix < WD + 2; ix ++)
			if (iy == 2 || map[iy][ix] == CW)
				cout << "█" ;    //器壁
		else if (map[iy][ix] == C0)
			cout << "  ";    //空白
		else if (map[iy][ix] == CB)
			cout << "□";    //方格
		else if (map[iy][ix] == CF)
			cout << "**";    //满行
		cout << "\n";
	}
	//打印输出游戏信息：关卡，得分，速度）
	gotoxy(X0 + 2 * WD + 6, Y0 + 1);
	cout << "级别: " <<  level;
	gotoxy(X0 + 2 * WD + 6, Y0 + 3);
	cout << "得分: "  <<  score;
	gotoxy(X0 + 2 * WD + 6, Y0 + 5);
	cout << "速度: " << speed << " ms";
	//打印输出操作帮助信息
	gotoxy(X0 + 2 * WD + 6, Y0 + 7);
	cout << "下一个方块：";
	gotoxy(X0 + 2 * WD + 6, Y0 + 14);
	cout << "  ↑  ：变形";
	gotoxy(X0 + 2 * WD + 6, Y0 + 15);
	cout << "← → ：移动";
	gotoxy(X0 + 2 * WD + 6, Y0 + 16);
	cout <<  "空格：暂停/继续";
	gotoxy(X0 + 2 * WD + 6, Y0 + 17);
	cout << "Esc ：退出";
}

typedef struct Tetromino {
	int type, x, y;	//方块变体，基准方格的坐标(x, y)
	int x2, y2, x3, y3, x4, y4;  //方块中其它三个方格的相对坐标
} Tetromino;

Tetromino tetro[19] = { {1, 0, 0, 0, +1, +1, 0, +1, +1},	//O
	{2, 0, 0, 0, -1, 0, +1, 0, +2}, {3, 0, 0, -1, 0, +1, 0, +2, 0},	  //I, I*90
	{4, 0, 0, 0, +1, -1, +1, +1, 0}, {5, 0, 0, -1, -1, -1, 0, 0, +1}, //S, S*90
	{6, 0, 0, -1, 0, 0, +1, +1, +1}, {7, 0, 0, 0, -1, -1, 0, -1, +1}, //Z, Z*90
	{8, 0, 0, 0, -1, 0, +1, +1, +1}, {9, 0, 0, -1, 0, +1, 0, -1, +1},   //L, L*90
	{10, 0, 0, -1, -1, 0, -1, 0, +1}, {11, 0, 0, +1, -1, -1, 0, +1, 0}, //L*180, L*270
	{12, 0, 0, 0, -1, -1, +1, 0, +1}, {13, 0, 0, -1, -1, -1, 0, +1, 0}, //J, J*90
	{14, 0, 0, 0, -1, +1, -1, 0, +1}, {15, 0, 0, -1, 0, +1, 0, +1, +1}, //J*180, J*270
	{16, 0, 0, -1, 0, +1, 0, 0, +1}, {17, 0, 0, 0, -1, -1, 0, 0, +1},   //T, T*90
	{18, 0, 0, 0, -1, -1, 0, +1, 0}, {19, 0, 0, 0, -1, +1, 0, 0, +1}    //T*180, T*270
};

bool movable(Tetromino t) {	//测试在容器中某个是否可以放置方块
	//方块的所有四个方格位置上都为空时，即可移动，否则不可移动。
	return (map[t.y][t.x] == C0 && map[t.y + t.y2][t.x + t.x2] == C0
		&& map[t.y + t.y3][t.x + t.x3] == C0 && map[t.y + t.y4][t.x + t.x4] == C0);
}


void fillTetro(Tetromino t) {	//在容器中填入俄罗斯方块
	//在方块的四个方格的位置写入字符 CB
	map[t.y][t.x] = map[t.y + t.y2][t.x + t.x2] = CB;
	map[t.y + t.y3][t.x + t.x3] =  map[t.y + t.y4][t.x + t.x4] = CB;
}

void drawxy(int x, int y, const char *ss) {	//对容器坐标(x, y)处输出字符串
	if (y > 2) {
		gotoxy(X0 + x * 2, Y0 + y - 2);
		cout << ss;
	}
}

void drawTetro(Tetromino t, bool show) {	//打印或擦除俄罗斯方块
	char ss[3];
	strcpy(ss, (show ? "□" : "  ")); //根据show值设定输出内容
	drawxy(t.x, t.y, ss);
	drawxy(t.x + t.x2, t.y + t.y2, ss);
	drawxy(t.x + t.x3, t.y + t.y3, ss);
	drawxy(t.x + t.x4, t.y + t.y4, ss);
}

void chkLines(int &level, int &score, int &speed) { //检查各行是否填满并处理
	int iy = HT + 2, ix, full;
	while (iy >= 1) {	//行
		full = 1;	//检查本行是否已填满
		for (ix = 1; ix <= WD; ix++) { //列
			if (map[iy][ix] == C0) { 	//有空块
				full = 0;
				break;
			}
		}
		if (full == 0) {	//此行未填满，检查另一行
			iy--;
		} else {	//此行已填满
			for (ix = 1; ix <= WD; ix++)
				map[iy][ix] = CF;	//用满行标志填充此行
			drawBoard(level, score, speed); //重绘游戏界面（填满的位置额外显示）
			Sleep(500);
			for (int iy2 = iy; iy2 > 1; iy2--)      //逐行下落
				for (ix = 1; ix <= WD; ix++)
					map[iy2][ix] = map[iy2 - 1][ix];
			score += 10;	//每删除一行，得10分
			if (score > 0 && score % 100 == 0) {	//每累计删除10行
				level ++;	//等级升高
				speed -= 50;	//游戏速度加快
			}
			drawBoard(level, score, speed);	//重绘游戏界面
		}
	}
}

void updateTetro(Tetromino &cur, Tetromino &next) {
	cur = next; 	//把next赋值给cur
	cur.x = WD / 2;	//设定当前方块的基准格坐标
	cur.y = 1;
	next = tetro[rand() % 19]; //随机生成方块变体号，并从数组 tetro[] 复制相应元素
	next.x = WD + 5;	//设定下一个方块的基准格坐标
	next.y = 12;
}

int main() {
	const int LEFT = 75, UP = 72, RIGHT = 77, DOWN = 80;	//键值常量
	const int SPACE = 32, ESC = 27;	//键值常量
	Tetromino cur, tmp, next;	//当前、暂存当前、下一个方块变体
	
	int level = 1, score = 0, speed = 200; //游戏等级、得分和方块移动速度(ms)
	int key;     //接收用户键盘输入字符
	
	//初始化容器
	for (int iy = 0, ix; iy <= HT + 3; iy++)
		for (ix = 0; ix <= WD + 1; ix ++)
			if (iy == HT + 3 || ix == 0 || ix == WD + 1)	//容器左列、右列和底行
				map[iy][ix] = CW;    //器壁
	else
		map[iy][ix] = C0;    //空白
	
	srand(time(0));  //初始化随机数种子
	next = tetro[rand() % 19]; //随机生成方块变体号，并从数组 tetro[] 复制相应元素
	updateTetro(cur, next); 	//更新方块
	
	showcursor(false);
	drawBoard(level, score, speed);  //绘制游戏界面
	drawTetro(next, 1);		//绘制(1)下一个方块
	
	while (1) {	//游戏主循环：不断生成新方块供玩家操纵，直至游戏结束
		drawTetro(cur, 1); //绘制(1)当前方块
		Sleep(speed);   //延缓时间
		key = '\0';		//赋值为无效操作键值
		while (kbhit()) //用户连续按键时，读取所有字符
			key = getch();
		tmp = cur;  //暂存当前方块
		if (key == UP && cur.type > 1) { //上：非O型方块变形，顺时针转90度
			drawTetro(cur, 0); //擦除(0)当前方块
			tmp.type++;
			if (tmp.type <= 8 && tmp.type % 2 == 0) //I: 2-3, S: 4-5, Z: 6-7
				tmp.type -= 2;	//I S Z 以2为倍数循环
			if (tmp.type > 8 && tmp.type % 4 == 0)	//L: 8-11, J: 12-15, T: 16-19
				tmp.type -= 4;	//L J T 以4为倍数循环
			tmp = tetro[tmp.type - 1];	//从tetro[]中复制相应元素（下标为变体号减1）
			tmp.x = cur.x;
			tmp.y = cur.y;
			if (movable(tmp))  //若新变体可以摆放，则更新
				cur = tmp;
		} else if (key == DOWN ) {	//下：连续下降
			drawTetro(cur, 0); //擦除(0)当前方块
			do {
				tmp = cur;
				cur.y++;
			} while (movable(cur));
			cur = tmp;	//恢复到最后一个 tmp
		} else if (key == LEFT ) { //左
			drawTetro(cur, 0); //擦除(0)当前方块
			cur.x--;
			if (!movable(cur))	//新坐标不可摆放，则恢复原坐标
				cur.x++;
		} else if (key == RIGHT ) {//右
			drawTetro(cur, 0); //擦除(0)当前方块
			cur.x++;
			if (!movable(cur))	//新坐标不可摆放，则恢复原坐标
				cur.x--;
		} else if (key == SPACE) {	//空格键暂停
			while ((key = getch()) != ' ') //空格键继续
				;
		} else if (key == ESC) {	//ESC
			showcursor(true);//显示光标
			gotoxy(X0 + 2 * WD + 6, Y0 + 19);
			cout << "退出游戏(Y/N)?";
			if ((key = toupper(getch())) == 'Y') {
				break;	//return 0;
			} else	{
				showcursor(false);
				gotoxy(X0 + 2 * WD + 6, Y0 + 19);
				cout << "               "; //擦除此行字符
			}
		} else { //无效操作键或无按键
			cur.y++;
			if (movable(cur))	//方块可以下移
				drawTetro(tmp, 0); //擦除(0)当前方块
			else {	//无效操作键或无按键，且方块不可下移（落下固定）
				cur.y--;
				fillTetro(cur);		//填入方块到容器
				chkLines(level, score, speed);	//检查各行，计算得分
				if (cur.y <= 2) 	//游戏结束条件：方块触到框顶位置
					break;
				else {	//产生新方块
					drawTetro(next, 0);	//擦除原有的下一个方块
					updateTetro(cur, next); 	//更新方块
					drawTetro(next, 1);	//绘制下一个方块
				}
			}
		}
	}//while
	
	gotoxy(X0, Y0 + HT + 2);
	cout << ("游戏结束，谢谢使用！");
	return 0;
}

