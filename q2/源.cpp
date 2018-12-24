/*
求两个有序链表的交际
*/

#include<iostream>
#include<list>
#include"item.h"
using namespace std;
int main() {
	//链表头
	node *l1 = new node();
	node *l2 = new node();
	int input = 0;
	while (cin >> input && input != -1) {
		l1->add_value_with_order(input);
	}
	while (cin >> input && input != -1) {
		l2->add_value_with_order(input);
	}
	node * l3 = get_intersection(l1, l2);
	l3->printAll();


	system("pause");
}