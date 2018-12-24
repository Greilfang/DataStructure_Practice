#include<iostream>
#include"step.h"
using namespace std;
int main()
{
	Maze solution;
	cout << "迷宫地图:" << endl;
	cout << "		0列		1列		2列		3列		4列		5列		6列" << endl;
	for (int i = 0; i <= 6; i++) {
		cout << i << "行" << "		";
		for (int j = 0; j <= 6; j++) {
			cout << solution.mys_array[i][j] << "		";
		}
		cout << endl;
	}
	solution.findPath({ 1,1 });
	cout << "迷宫路径:"<<endl;
	solution.printPath();
	cout << "走法图示:" << endl;
	cout << "		0列		1列		2列		3列		4列		5列		6列" << endl;
	for (int i = 0; i <= 6; i++) {
		cout << i << "行" << "		";
		for (int j = 0; j <= 6; j++) {
			cout << solution.mys_array[i][j] << "		";
		}
		cout << endl;
	}
	system("pause");
}