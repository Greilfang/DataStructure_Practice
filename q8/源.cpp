#include<iostream>
#include"graph.h"
using namespace std;
void progress_control(char  choise, wholemaps& PrimMap);
int main() {
	wholemaps PrimMap;
	char choise='0';
	cout << "------------------------------\n"
		"**\t\t 电网造价模拟系统 \t\t**\n"
		"------------------------------\n"
		"**\t\tA——创建电网顶点\t\t**\n"
		"**\t\tB——添加电网的边\t\t**\n"
		"**\t\tC——构造最小生成树\t\t**\n"
		"**\t\tD——显示最小生成树\t\t**\n"
		"**\t\tE——退出程序\t\t\t**\n"
		"------------------------------\n";
	
	while (true) {
		cout << "请选择操作";
		cin >> choise;
		if (choise != 'E') {
			progress_control(choise, PrimMap);
		}
		else {
			break;
		}
	}
	system("pause");
}

void progress_control(char  choise, wholemaps& PrimMap) {
	switch (choise) {
	case 'A':PrimMap.buildNodes(); break;
	case 'B':PrimMap.appendLines(); break;
	case 'C':PrimMap.setupPrim(); break;
	case 'D':PrimMap.displayPrim(); break;
	}
}