#include<iostream>
#include<string>
#include"fmy.h"
using namespace std;
int main()
{
	familyTree OneFamily;
	cout << "**              ���׹���ϵͳ               **" << endl;
	cout << "=============================================" << endl;
	cout << "**          ��ѡ��Ҫִ�еĲ���:            **" << endl;
	cout << "**             A--���Ƽ�ͥ                 **" << endl;
	cout << "**             B--��Ӽ�ͥ��Ա             **" << endl;
	cout << "**             C--��ɢ�ֲ���ͥ             **" << endl;
	cout << "**             D--���ļ�ͥ��Ա����         **" << endl;
	cout << "**             E--�˳�����                 **" << endl;
	cout << "=============================================" << endl;
	cout << "���Ƚ���һ������" << endl << "��������һ�����ȵ����� ";
	member * ancestor = new member;
	cin >> (*ancestor);
	OneFamily.buildTree(ancestor);
	char choise;
	while (true) {
		cout << "��������Ҫִ�еĲ��� " ;
		cin >> choise;
		if (choise == 'A') {
			cout << "������Ҫ������ͥ���˵����� ";
			member target;
			cin >> target;
			OneFamily.buildFamily(target);
		}
		else if (choise == 'B') {
			cout << "����������Ҫ���Ƽ�ͥ���˵����� ";
			member target;
			cin >> target;
			OneFamily.perfectFamily(target);
		}
		else if (choise == 'C') {
			cout << "��������Ҫ��ɢ��ͥ���˵����� ";
			member target;
			cin >> target;
			OneFamily.disbandFamily(target);
		}
		else if (choise == 'D') {
			cout << "����������Ҫ�ı���˵����� ";
			member target;
			cin >> target;
			OneFamily.replaceMember(target);
		}
		else if (choise == 'E') {
			cout << "�˳�";
			break;
		}
	}
	system("pause");
}