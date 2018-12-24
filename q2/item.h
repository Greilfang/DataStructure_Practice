#pragma once
#pragma once
#include<iostream>
using namespace std;
class node {
private:
	int value;
	node * link = NULL;
public:
	node() { value = -1; link = NULL; }
	node(int _input) { value = _input; link = NULL; };
	void printAll();
	void add_value_with_order(int _input);
	friend node* get_intersection(node *l1, node *l2);
};

void node::add_value_with_order(int _input) {
	node * scanner = NULL;
	if (link == NULL) {
		link = new node(_input);
		return;
	}
	else if (_input <= link->value) {
		node * temp = new node(_input);
		temp->link = link;
		link = temp;
		return;
	}
	else {
		scanner = link;
		while (scanner->link != NULL) {
			if (scanner->value <= _input&&scanner->link->value >= _input) {
				node * temp = new node(_input);
				temp->link = scanner->link;
				scanner->link = temp;
				return;
			}
			scanner = scanner->link;
		}

	}
	if (scanner->link == NULL) {
		scanner->link = new node(_input);
	}
}
node* get_intersection(node *l1, node*l2) {
	node * l3 = new node();
	if (l1->link == NULL || l2->link == NULL) {
		return l3;
	}
	else {
		node * s1 = l1->link;
		node * s2 = l2->link;
		node * s3 = l3;
		while (s1 != NULL&&s2 != NULL) {
			if (s1->value <s2->value) {
				s1 = s1->link;
			}
			else if (s1->value > s2->value) {
				s2 = s2->link;
			}
			else {
				s3->link = new node(s1->value);
				s3 = s3->link;
				s1 = s1->link;
				s2 = s2->link;
			}
		}
	}
	return l3;
}
void node::printAll() {
	if (link == NULL) {
		cout << "NULL";
	}
	else {
		cout << link->value;
		node * scan = link->link;
		while (scan != NULL) {
			cout <<" "<< scan->value ;
			scan = scan->link;
		}
	}
	cout << endl;
}
