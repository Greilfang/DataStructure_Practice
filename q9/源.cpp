#include<iostream>
#include"graph.h"
using namespace std;
int main()
{
	//任务交接点的数量
	int N = 0;
	//任务的数量
	int M = 0;
	//图
	cout << "输入点数和活动数" << endl;
	cin >> N >> M;
	Graph Paths(N,M);
	cout << "输入起点，终点和时长" << endl;
	for (int i = 1; i <= M; i++) {
		//任务起始点，终止点和时常
		int start_node = 0, end_node = 0, time_span = 0;
		cin >> start_node >> end_node >> time_span;
		Paths.append(start_node, end_node, time_span);
	}
	Paths.findCriticalPaths();
	system("pause");
}