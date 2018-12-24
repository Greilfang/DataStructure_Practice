#pragma once
#include<iostream>
#include<map>
#include<list>
#include<stack>
#include<vector>
#include<queue>
using namespace std;
class Edge {
public:
	int bg_point=0;
	int ed_point=0;
	int length=0;
	Edge(int _bg, int _ed, int _lg) :bg_point(_bg), ed_point(_ed), length(_lg) {};
};
class NodeRear {
private:
	int dest = 0;
	int span = 0;
public:
	NodeRear(int _dest, int _span) :dest(_dest), span(_span) {};
	int bkdest() { return dest; };
	int bkspan() { return span; };
};
class Graph {
private:
	int edge = 0;
	int vertex = 0;
	map<int, list<NodeRear>> links;
	vector<int> InCounts;//入度对照
	vector<int> SortResults;//拓扑排序结果储存
	stack<int> InZeroPoints;//存储入度为0的边的栈

public:
	Graph(int n,int m);
	void append(int _start, int _end, int _span);
	void findZero();
	void findCriticalPaths();
	void TopologicalSort();
};
void Graph::append(int _start, int _end, int _span) {
	links[_start].push_back(NodeRear(_end, _span));
	InCounts[_end]++;
}
Graph::Graph(int n,int m) {
	vertex = n; edge = m;
	InCounts.push_back(0);
	SortResults.push_back(-1);//挤掉第一个下标
	for (int i = 1; i <= n; i++) {
		list<NodeRear> temp;
		links[i] = temp;
		InCounts.push_back(0);
	}
}
void Graph::findZero() {
	for (int i = 1; i < InCounts.size(); i++) {
		//把入度为0的顶点全部压入栈中
		if (InCounts[i] == 0) {
			InZeroPoints.push(i);
			InCounts[i]--;
		}
	}
}
void Graph::TopologicalSort() {
	Graph::findZero();
	int count = 0;
	while (!InZeroPoints.empty()) {
		int temp = InZeroPoints.top();
		InZeroPoints.pop();
		SortResults.push_back(temp);
		count++;
		if (!links[temp].empty()) {
			for (auto t = links[temp].begin(); t != links[temp].end(); t++) {
					InCounts[t->bkdest()]--;
			}
		}
		Graph::findZero();
	}
}

void Graph::findCriticalPaths(){
	//逆拓扑有序
	Graph::TopologicalSort();
	int *Ve = new int[vertex + 1];
	memset(Ve, 0, sizeof(int)*(vertex + 1));
	int *Vl = new int[vertex + 1];
	for (int i = 1; i < SortResults.size(); i++) {
		int anc = SortResults[i];
		for (auto t = links[anc].begin(); t != links[anc].end(); t++) {
			if (Ve[anc] + t->bkspan() > Ve[t->bkdest()]) {
				Ve[t->bkdest()] = t->bkspan() + Ve[anc];
			}
		}
	}
	//初始化
	for (int i = 0; i < vertex + 1; i++) {
		Vl[i] = INT_MAX;
	}
	int *Vo = new int[vertex + 1];
	memset(Vo, 0, sizeof(int)*(vertex + 1));
	Vl[SortResults[SortResults.size()-1]] = Ve[SortResults[SortResults.size() - 1]];
	//一一遍历
	for (int i = SortResults.size() - 1; i > 0; i--) {
		int anc = SortResults[i];//开始的点的序号
		for (auto t = links.begin(); t != links.end(); t++) {
			for (auto k = t->second.begin(); k != t->second.end(); k++) {
				//如果能找到入anc的点
				if (k->bkdest() == anc) {
					if (Vo[anc] + k->bkspan() > Vo[t->first]) {
						Vo[t->first] = Vo[anc] + k->bkspan();
						Vl[t->first] = Vl[SortResults[SortResults.size() - 1]] - Vo[t->first];
					}
				}
			}
		}
	}
	int * Ae = new int[edge + 1];
	memset(Ae, 0, sizeof(int)*(edge + 1));
	int * Al = new int[edge + 1];
	memset(Ae, 0, sizeof(int)*(edge + 1));
	//扫描领接表
	queue<Edge> StepsDisplay;
	for (int i = 1; i < SortResults.size(); i++) {
		for (auto t = links[SortResults[i]].begin(); t != links[SortResults[i]].end(); t++) {
			int ae = Ve[SortResults[i]];
			int al = Vl[t->bkdest()] - t->bkspan();
			if (ae == al) {
				StepsDisplay.push(Edge(SortResults[i], t->bkdest(), t->bkspan()));
			} 
		}
	}
	if (SortResults.size() > 1) {
		cout << Ve[SortResults[SortResults.size() - 1]] << endl;
	}
	else {
		cout << 0 << endl;
	}
	while (!StepsDisplay.empty()) {
		Edge temp = StepsDisplay.front();
		StepsDisplay.pop();
		cout << temp.bg_point << "-->" << temp.ed_point << endl;
	}
	delete[]Vl,Vo,Ve,Ae,Al;
}

