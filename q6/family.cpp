#include<iostream>
#include<string>
#include"fmy.h"
using namespace std;
int main()
{
	familyTree OneFamily;
	cout << "**              家谱管理系统               **" << endl;
	cout << "=============================================" << endl;
	cout << "**          请选择要执行的操作:            **" << endl;
	cout << "**             A--完善家庭                 **" << endl;
	cout << "**             B--添加家庭成员             **" << endl;
	cout << "**             C--解散局部家庭             **" << endl;
	cout << "**             D--更改家庭成员姓名         **" << endl;
	cout << "**             E--退出程序                 **" << endl;
	cout << "=============================================" << endl;
	cout << "首先建立一个家谱" << endl << "请先输入一个祖先的名字 ";
	member * ancestor = new member;
	cin >> (*ancestor);
	OneFamily.buildTree(ancestor);
	char choise;
	while (true) {
		cout << "请输入你要执行的操作 " ;
		cin >> choise;
		if (choise == 'A') {
			cout << "请输入要建立家庭的人的名称 ";
			member target;
			cin >> target;
			OneFamily.buildFamily(target);
		}
		else if (choise == 'B') {
			cout << "请输入你想要完善家庭的人的名称 ";
			member target;
			cin >> target;
			OneFamily.perfectFamily(target);
		}
		else if (choise == 'C') {
			cout << "请输入你要解散家庭的人的名称 ";
			member target;
			cin >> target;
			OneFamily.disbandFamily(target);
		}
		else if (choise == 'D') {
			cout << "请输入你想要改变的人的名字 ";
			member target;
			cin >> target;
			OneFamily.replaceMember(target);
		}
		else if (choise == 'E') {
			cout << "退出";
			break;
		}
	}
	system("pause");
}