#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class member {
private:
	string Name;
	vector<member *> Children;
public:
	member() { ; };
	member(string _Name) :Name(_Name) { ; };
	void addChild(member * _child);
	void eliminate();
	void changeName(member &target);
	bool equal(member & target) ;
	bool member::noChildren();
	string bkName() { return Name; };
	void printChildren();
	member * search(member &target);
	friend istream& operator >> (istream & is, member & _person);
};
void member::printChildren() {
	cout << bkName() << "的孩子是 ";
	if (!Children.empty()) {
		for (int i = 0; i < Children.size(); i++) {
			cout << Children[i]->bkName() << " ";
		}
	}
	cout << endl;
}
bool member::equal(member & target) {
	return Name == target.Name;
}
member * member::search(member &target) {
	member * p = this;
	if (p->Name == target.Name) {
		return p;
	}
	else {
		if (p->Children.empty()) {
			return nullptr;
		}
		for (int i = 0; i < p->Children.size(); i++) {
			member * temp = (p->Children)[i]->search(target);
			if (temp != nullptr) {
				return temp;
			}
		}
		return nullptr;
	}

}

bool member::noChildren() {
	if (Children.size() == 0) {
		return true;
	}
	else {
		return false;
	}
}
istream & operator >> (istream &is, member &person) {
	string _Name;
	is >> _Name;
	if (is) {
		person.Name = _Name;
	}
	else {
		cout << "fail to cin>>";
	}
	return is;
}
void member::addChild(member * _child) {
	Children.push_back(_child);
}
void member::eliminate() {
	if (Children.size() == 0) {
		return;
	}
	else {
		for (int i = 0; i < Children.size(); i++) {
			(Children[i])->eliminate();
			delete Children[i];
		}
		Children.clear();
		Children.shrink_to_fit();
	}
}
void member::changeName(member &target) {
	Name = target.Name;
}
class familyTree {
private:
	member * master=nullptr; //默认的家族树首领
public:
	void buildTree(member * ancestor);//建立家谱
	void buildFamily(member & target);//建立家庭
	void perfectFamily(member & target );//完善家庭
	void disbandFamily(member & target);//解散家庭
	void replaceMember(member & target);//更改家庭成员姓名
};
void familyTree::buildTree(member * ancestor) {
	master = ancestor;
}
void familyTree::buildFamily(member & target) {
	if (master == nullptr) {
		cout << "请先建立你的家谱" << endl;
	}
	else {
		member *p = master->search(target);
		if (p == nullptr) {
			cout << "没有找到建立家庭的对象" << endl;
			return;
		}
		else if (p->noChildren() == false) {
			cout << "这个对象已经有家庭了,不能建立" << endl;
		}
		else {
			cout << "请输入" << p->bkName() << "的子女数" ;
			int childrenMax = 0;
			cin >> childrenMax;
			for (int i = 1; i <= childrenMax; i++) {
				member * temp = new member;
				cin >> (*temp);
				p->addChild(temp);
			}
			p->printChildren();
		}
	}
}
	
void familyTree::perfectFamily(member & target) {
	if (master == nullptr) {
		cout << "请先建立你的家谱" << endl;
	}
	else {
		member * p = master->search(target);
		if (p == nullptr) {
			cout << "没有找到你要找的对象" << endl;
		}
		else if (p->noChildren() == true) {
			cout << "这个对象还没有家庭,必须先建立一个家庭.";
		}
		else {
			cout << "请输入想要插入的儿子(女儿)的名字 ";
			member * temp = new member;
			cin >> (*temp);
			p->addChild(temp);
			p->printChildren();
			//cout << "输入成功!现在支持添加子女!" << endl;
		}
		
	}
}
void familyTree::disbandFamily(member & target) {
	if (master == nullptr) {
		cout << "请先建立你的家谱" << endl;
	}
	else {
		member * p = master->search(target);
		if (p == nullptr) {
			cout << "没有找到你要删除家庭的对象" << endl;
		}
		else {
			cout << "删除家庭的人" << p->bkName() << endl;
			p->eliminate();
		}
	}

}
void familyTree::replaceMember(member & target) {
	if (master == nullptr) {
		cout << "请先建立你的家谱" << endl;
	}
	else {
		member * p = master->search(target);
		if (p == nullptr) {
			cout << "没有找到你要修改家庭的对象" << endl;
		}
		else {
			cout << "请输入想要的新名字 ";
			member * temp = new member;
			cin >> (*temp);
			p->changeName(*temp);
		}
	}
}