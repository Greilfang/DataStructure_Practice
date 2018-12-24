#pragma once
#include<iostream>
#include<list>
#include<map>
#include<vector>
#include <string>
#define MAX_LENGTH 100000
using namespace std;
class graphnode {
private:
	int destination;
	int cost;
public:
	int bkdest() { return destination; };
	int bkcost() { return cost; };
	graphnode(int _dest, int _cost) :destination(_dest), cost(_cost) {};
};
class edge {
public:
	char start_point;
	int length;
	char end_point;
	edge(char a, int b, char c) :start_point(a), length(b), end_point(c) {};
};

class wholemaps {
private:
	map<char, list<graphnode>> all_nodes;
	map<char, int> symbol_to_index;
	map<int, char>index_to_symbol;
	vector<edge> routine;
public:
	void buildNodes();
	void appendLines();
	void setupPrim();
	void displayPrim();
	int wholemaps::edgeDistance(int scaner, int i);
};
void wholemaps::displayPrim() {
	cout << "生成最小生成树的顶点和边为:" << endl;
	for (int i = 0; i < routine.size(); i++) {
		cout << routine[i].start_point << "-(" << routine[i].length << ")->" << routine[i].end_point<<"  ";
	}
	cout << endl;
}
void wholemaps::buildNodes() {
	cout << "请输入你想插入的节点数?" << endl;
	int nums=0;
	cin >> nums;
	for (int i = 0; i < nums; i++) {
		char input;
		cin >> input;
		//建立映射关系
		symbol_to_index[input] = i;
		index_to_symbol[i] = input;
		
		list<graphnode> expr;
		all_nodes[input] = expr;
	}
}
void wholemaps::appendLines() {
	char nd1='1', nd2='1'; int lg=1;
	while (true) {
		cout << "请输入两个顶点和边";
		cin >> nd1 >> nd2 >> lg;
		if (nd1 == '?') {
			break;
		}
		auto r = graphnode(symbol_to_index[nd2],lg);
		all_nodes[nd1].push_back(r);
		auto k = graphnode(symbol_to_index[nd1], lg);
		all_nodes[nd2].push_back(k);
	}
}
int wholemaps::edgeDistance(int scaner, int i) {
	for (auto ptr = all_nodes[index_to_symbol[scaner]].begin(); ptr != all_nodes[index_to_symbol[scaner]].end(); ptr ++ ) {
		if (ptr->bkdest() == i) {
			return ptr->bkcost();
		}	
	}
	return MAX_LENGTH;
}
void wholemaps::setupPrim() {
	cout << "请输入起始顶点";
	char start_line;
	cin >> start_line;
	const int nodeLength = all_nodes.size();
	int * lowcost = new int[all_nodes.size()];
	int * nearvex = new int[all_nodes.size()];
	//lowcost初始化
	memset(lowcost, 0, nodeLength * sizeof(int));
	auto scanner = all_nodes[start_line];
	for (auto t = scanner.begin(); t != scanner.end(); t++) {
		lowcost[t->bkdest()] = t->bkcost();
	}
	for (int i = 0; i < all_nodes.size(); i++) {
		if (lowcost[i] == 0) {
			lowcost[i] = MAX_LENGTH;
		}
	}

		lowcost[symbol_to_index[start_line]] = 0;
		//nearvex初始化
		memset(nearvex, 0, nodeLength * sizeof(int));
		nearvex[symbol_to_index[start_line]] = -1;


		for (int n = 1; n < all_nodes.size(); n++) {
			int ancher_index = symbol_to_index[start_line];
			int min_distance = MAX_LENGTH; int scaner = 0;
			for (int i = 0; i < nodeLength; i++) {
				if (nearvex[i] != -1 && lowcost[i] < min_distance) {
					scaner = i;
					min_distance = lowcost[i];
				}
			}
			edge temp(index_to_symbol[nearvex[scaner]], min_distance, index_to_symbol[scaner]);
			routine.push_back(temp);
			nearvex[scaner] = -1;
		

			for (int i = 0; i < nodeLength; i++) {
				if (nearvex[i] != -1 && edgeDistance(scaner, i) < lowcost[i]) {
					nearvex[i] = scaner;
					lowcost[i] = edgeDistance(scaner, i);
				}
			}
		}
		cout << "生成prim最小生成树!" << endl;
}

int min(int a,int b) {
	return a < b ? a : b;
}