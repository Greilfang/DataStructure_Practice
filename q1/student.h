#pragma once
#include<iostream>
#include<list>
#include<string>
using namespace std;
class student {
private:
	string index;   //����
	string name;   //����
	string sex;
	int age;   //����
	string subject; //�������
public:
	void operator=(student &st);
	student() { ; };
	string Index() { return index; };
	friend istream & operator >> (istream & is, student & st);
	friend ostream & operator << (ostream & os, student & st);
};

istream & operator >> (istream & is, student & st) {
	string index_;
	string name_;
	string sex_;
	int age_;
	string subject_;
	is >> index_ >> name_ >> sex_ >> age_ >> subject_;
	if (is) {
		st.index = index_;
		st.name = name_;
		st.sex = sex_;
		st.age = age_;
		st.subject = subject_;
	}
	else {
		cout << "cin in bug!" << endl;
	}
	return is;
}
ostream & operator <<(ostream &os, student &st) {
	os << st.index << "     " << st.name << "  " << st.sex << "    " << st.age << "    " << st.subject << endl;
	return os;
}

void student::operator=(student &st) {
	index = st.index;
	name = st.name;
	sex = st.sex;
	age = st.age;
	subject = st.subject;
}






/*
�������ݲ�������
*/
class ctl_part {
private:
	list<student> Student_Chart; //���
public:
	ctl_part() { ; };
	void build(int _maxStudent); //����
	void insert(int position);//����
	void rubber(string erase_index);//ɾ��
	void search(string search_index);//����
	void change(string change_index);//�޸�
	void display();
	/*
	void sum();   //ͳ��
	*/
};
void ctl_part::display() {
	cout << "����" << "  " << "����" << "  " << "�Ա�" << "  " << "����" << "  " << "�������" << endl;
	for (list<student>::iterator iter = Student_Chart.begin(); iter != Student_Chart.end(); iter++) {
		cout << (*iter);
	}
}
void ctl_part::build(int _maxStudent) {
	for (int i = 1; i <= _maxStudent; i++) {
		student temp;
		cin >> temp;
		Student_Chart.push_back(temp);
	}
}

void ctl_part::insert(int position) {
	cout << "���������뿼���Ŀ���,����,�Ա�,����,�Լ��������" << endl;
	student temp;
	cin >> temp;
	if (Student_Chart.empty()) {
		Student_Chart.push_back(temp);
	}
	else if(position!=1){
		list<student>::iterator iter = Student_Chart.begin();
		for (int i = 1; i < position&&iter != Student_Chart.end(); i++) {
			iter++;
		}
		Student_Chart.insert(iter, temp);
	}
	else if (position == 1) {
		Student_Chart.push_front(temp);
	}
}

void ctl_part::rubber(string erase_index) {
	for (list<student>::iterator iter = Student_Chart.begin(); iter != Student_Chart.end(); iter++) {
		if (iter->Index() == erase_index) {
			cout << "��Ҫɾ���Ŀ�����ϢΪ:" << endl;
			cout << (*iter);
			Student_Chart.erase(iter);
			return;
		}
	}
	cout << "δ�ҵ���Ҫɾ���Ŀ�����Ϣ" << endl;
	return;

}

void ctl_part::search(string search_index) {
	for (list<student>::iterator iter = Student_Chart.begin(); iter != Student_Chart.end(); iter++) {
		if (iter->Index() == search_index) {
			cout << "�ҵ���" << endl;
			cout << "������Ϣ:" << endl;
			cout << (*iter);
			return;
		}
	}
	cout << "���ź�,û�ҵ�" << endl;
	return;
}
void ctl_part::change(string change_index) {
	for (list<student>::iterator iter = Student_Chart.begin(); iter != Student_Chart.end(); iter++) {
		if (iter->Index() == change_index) {
			cout << "��Ҫ�޸ĵĿ�����ϢĿǰΪ:" << endl;
			cout << (*iter);
			student temp;
			cout << "��������Ҫ�޸ĵ�����:" << endl;
			cin >> temp;
			(*iter) = temp;
		}
	}
}



/*
���ڴ��ݲ�������Ⱦ��
*/
class render_part {
private:
	string string_bar;
	int num_bar;
public:
	render_part() { ; };

	int build_picture() {
		cout << "�����뽨��������Ϣϵͳ" << endl;
		cout << "�����뿼������" << endl;
		cin >> num_bar;
		cout << "���������뿼���Ŀ���,����,�Ա�,����,�Լ��������" << endl;
		return num_bar;
	}
	int ask_requirement() {
		cout << "����������Ҫ���еĲ���(1�ǲ���,2��ɾ��,3�ǲ���,4���޸�,5��ͳ��,0Ϊȡ������)";
		int choise = 0;
		cin >> choise;
		return choise;
	}
	int insert_picture() {
		cout << "����������Ҫ�����λ��:";
		int position = 0;
		cin >> position;
		return position;
	}
	string rubber_picture() {
		cout << "����������Ҫɾ���Ŀ������:";
		string erase_index;
		cin >> erase_index;
		return erase_index;
	}
	string search_picture() {
		cout << "����������Ҫ���ҵĿ����ı��";
		string search_index;
		cin >> search_index;
		return search_index;
	}
	string change_picture() {
		cout << "����������Ҫ�޸ĵĿ�������";
		string change_index;
		cin >> change_index;
		return change_index;
	}
};

class whole_system {
private:
	ctl_part control_panal;
	render_part render_panal;
public:
	whole_system() { cout << "��ӭ����ѧ����Ϣ����ϵͳ" << endl; };
	void display_statistics() { control_panal.display(); };
	void start_to_build();
	int require();
	void excute_requirement(int order);
	void start_to_insert();
	void start_to_rubber();
	void start_to_search();
	void start_to_change();

};

void whole_system::start_to_build() {
	/*�õ�Ҫ�����ѧ����*/
	int maxStudent = render_panal.build_picture();
	control_panal.build(maxStudent);
}
void whole_system::start_to_insert() {
	int position = render_panal.insert_picture();
	control_panal.insert(position);
}
void whole_system::start_to_rubber() {
	string erase_index = render_panal.rubber_picture();
	control_panal.rubber(erase_index);

}

void whole_system::start_to_search() {
	string search_index = render_panal.search_picture();
	control_panal.search(search_index);
}

void whole_system::start_to_change() {
	string change_index = render_panal.change_picture();
	control_panal.change(change_index);
}

int whole_system::require() {
	int choise = render_panal.ask_requirement();
	return choise;
}
void whole_system::excute_requirement(int order) {
	switch (order) {
	case 1:
		start_to_insert();break;
	case 2:
		start_to_rubber(); break;
	case 3:
		start_to_search(); break;
	case 4:
		start_to_change(); break;
	case 5:
		break;
	}

}