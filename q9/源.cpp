#include<iostream>
#include"graph.h"
using namespace std;
int main()
{
	//���񽻽ӵ������
	int N = 0;
	//���������
	int M = 0;
	//ͼ
	cout << "��������ͻ��" << endl;
	cin >> N >> M;
	Graph Paths(N,M);
	cout << "������㣬�յ��ʱ��" << endl;
	for (int i = 1; i <= M; i++) {
		//������ʼ�㣬��ֹ���ʱ��
		int start_node = 0, end_node = 0, time_span = 0;
		cin >> start_node >> end_node >> time_span;
		Paths.append(start_node, end_node, time_span);
	}
	Paths.findCriticalPaths();
	system("pause");
}