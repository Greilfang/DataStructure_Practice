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
	cout << bkName() << "�ĺ����� ";
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
	member * master=nullptr; //Ĭ�ϵļ���������
public:
	void buildTree(member * ancestor);//��������
	void buildFamily(member & target);//������ͥ
	void perfectFamily(member & target );//���Ƽ�ͥ
	void disbandFamily(member & target);//��ɢ��ͥ
	void replaceMember(member & target);//���ļ�ͥ��Ա����
};
void familyTree::buildTree(member * ancestor) {
	master = ancestor;
}
void familyTree::buildFamily(member & target) {
	if (master == nullptr) {
		cout << "���Ƚ�����ļ���" << endl;
	}
	else {
		member *p = master->search(target);
		if (p == nullptr) {
			cout << "û���ҵ�������ͥ�Ķ���" << endl;
			return;
		}
		else if (p->noChildren() == false) {
			cout << "��������Ѿ��м�ͥ��,���ܽ���" << endl;
		}
		else {
			cout << "������" << p->bkName() << "����Ů��" ;
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
		cout << "���Ƚ�����ļ���" << endl;
	}
	else {
		member * p = master->search(target);
		if (p == nullptr) {
			cout << "û���ҵ���Ҫ�ҵĶ���" << endl;
		}
		else if (p->noChildren() == true) {
			cout << "�������û�м�ͥ,�����Ƚ���һ����ͥ.";
		}
		else {
			cout << "��������Ҫ����Ķ���(Ů��)������ ";
			member * temp = new member;
			cin >> (*temp);
			p->addChild(temp);
			p->printChildren();
			//cout << "����ɹ�!����֧�������Ů!" << endl;
		}
		
	}
}
void familyTree::disbandFamily(member & target) {
	if (master == nullptr) {
		cout << "���Ƚ�����ļ���" << endl;
	}
	else {
		member * p = master->search(target);
		if (p == nullptr) {
			cout << "û���ҵ���Ҫɾ����ͥ�Ķ���" << endl;
		}
		else {
			cout << "ɾ����ͥ����" << p->bkName() << endl;
			p->eliminate();
		}
	}

}
void familyTree::replaceMember(member & target) {
	if (master == nullptr) {
		cout << "���Ƚ�����ļ���" << endl;
	}
	else {
		member * p = master->search(target);
		if (p == nullptr) {
			cout << "û���ҵ���Ҫ�޸ļ�ͥ�Ķ���" << endl;
		}
		else {
			cout << "��������Ҫ�������� ";
			member * temp = new member;
			cin >> (*temp);
			p->changeName(*temp);
		}
	}
}