#include<iostream>
#include"step.h"
using namespace std;
int main()
{
	Maze solution;
	cout << "�Թ���ͼ:" << endl;
	cout << "		0��		1��		2��		3��		4��		5��		6��" << endl;
	for (int i = 0; i <= 6; i++) {
		cout << i << "��" << "		";
		for (int j = 0; j <= 6; j++) {
			cout << solution.mys_array[i][j] << "		";
		}
		cout << endl;
	}
	solution.findPath({ 1,1 });
	cout << "�Թ�·��:"<<endl;
	solution.printPath();
	cout << "�߷�ͼʾ:" << endl;
	cout << "		0��		1��		2��		3��		4��		5��		6��" << endl;
	for (int i = 0; i <= 6; i++) {
		cout << i << "��" << "		";
		for (int j = 0; j <= 6; j++) {
			cout << solution.mys_array[i][j] << "		";
		}
		cout << endl;
	}
	system("pause");
}