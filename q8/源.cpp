#include<iostream>
#include"graph.h"
using namespace std;
void progress_control(char  choise, wholemaps& PrimMap);
int main() {
	wholemaps PrimMap;
	char choise='0';
	cout << "------------------------------\n"
		"**\t\t �������ģ��ϵͳ \t\t**\n"
		"------------------------------\n"
		"**\t\tA����������������\t\t**\n"
		"**\t\tB������ӵ����ı�\t\t**\n"
		"**\t\tC����������С������\t\t**\n"
		"**\t\tD������ʾ��С������\t\t**\n"
		"**\t\tE�����˳�����\t\t\t**\n"
		"------------------------------\n";
	
	while (true) {
		cout << "��ѡ�����";
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