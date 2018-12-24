#pragma once
#include<iostream>
#include<stack>
using namespace std;
class step {
private:
public:
	int x;
	int y;
	step(int _x, int _y) :x(_x), y(_y) { ; };
	step(const step &_s) :x(_s.x), y(_s.y) { ; };
	step() { x = 0; y = 0; };
	bool operator!=(const step &_s){
		if (_s.x != x || _s.y != y) {
			return true;
		}
		else {
			return false;
		}
	};
};
class Maze {
private:
	stack<step> pathContainer;
	step current{ 0,0 };
	step previous{ 0,0 };
public:
	char mys_array[7][7] = {
		'#','#','#','#','#','#','#',
		'#','o','#','o','o','o','#',
		'#','o','#','o','#','#','#',
		'#','o','o','o','#','o','#',
		'#','o','#','o','o','o','#',
		'#','o','#','o','#','o','#',
		'#','#','#','#','#','#','#'
	};
	int MaxLength = 5; int MaxHeight = 5;
	bool findPath(step nowstep);
	void printPath();
	void printMaze();
};

bool Maze::findPath(step nowstep) {
	if (nowstep.x == MaxHeight) {
		pathContainer.push(nowstep);
		return true;
	}
	if (nowstep.y + 1 <= MaxHeight&&mys_array[nowstep.x][nowstep.y + 1] == 'o'&&previous != step{ nowstep.x ,nowstep.y + 1 }) {
		previous = nowstep;
		if (findPath({ nowstep.x,nowstep.y + 1 })) {
			pathContainer.push(nowstep);
			return true;
		};
	}
	if (nowstep.y - 1 >= 1 && mys_array[nowstep.x][nowstep.y - 1] == 'o'&&previous != step{ nowstep.x ,nowstep.y - 1 }) {
		previous = nowstep;
		if (findPath({ nowstep.x,nowstep.y - 1 })) {
			pathContainer.push(nowstep);
			return true;
		};
	}
	
	if (nowstep.x + 1 <= MaxLength&&mys_array[nowstep.x + 1][nowstep.y] == 'o'&&previous != step{ nowstep.x + 1,nowstep.y }) {
		previous = nowstep;
		if (findPath({ nowstep.x + 1,nowstep.y })) {
			pathContainer.push(nowstep);
			return true;
		};
	}
	if (nowstep.x - 1 >= 1 && mys_array[nowstep.x - 1][nowstep.y] == 'o'&&previous != step{nowstep.x-1,nowstep.y}) {
		previous = nowstep;
		if (findPath({ nowstep.x - 1 ,nowstep.y })) {
			pathContainer.push(nowstep);
			return true;
		};
	}
	else {
		previous = nowstep;
		return false;
	}
	return true;
}
void Maze::printPath() {
	if (!pathContainer.empty()) {
		cout << "(" << pathContainer.top().x <<","<<pathContainer.top().y << ")";
		mys_array[pathContainer.top().x][pathContainer.top().y] = 'x';
		pathContainer.pop();
	}
	while (!pathContainer.empty()) {
		cout << "-->" << "(" << pathContainer.top().x << "," << pathContainer.top().y << ")";
		mys_array[pathContainer.top().x][pathContainer.top().y] = 'x';
		pathContainer.pop();
	}
	cout << endl << endl;
}
