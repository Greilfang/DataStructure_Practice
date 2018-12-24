#pragma once
#include<iostream>
#include<list>
#include<string>
using namespace std;
class student {
private:
	string index;   //考号
	string name;   //姓名
	string sex;
	int age;   //年龄
	string subject; //报考类别
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
用于数据操作的类
*/
class ctl_part {
private:
	list<student> Student_Chart; //表格
public:
	ctl_part() { ; };
	void build(int _maxStudent); //建立
	void insert(int position);//插入
	void rubber(string erase_index);//删除
	void search(string search_index);//搜索
	void change(string change_index);//修改
	void display();
	/*
	void sum();   //统计
	*/
};
void ctl_part::display() {
	cout << "考号" << "  " << "姓名" << "  " << "性别" << "  " << "年龄" << "  " << "考试类别" << endl;
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
	cout << "请依次输入考生的考号,姓名,性别,年龄,以及报考类别" << endl;
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
			cout << "你要删除的考生信息为:" << endl;
			cout << (*iter);
			Student_Chart.erase(iter);
			return;
		}
	}
	cout << "未找到你要删除的考生信息" << endl;
	return;

}

void ctl_part::search(string search_index) {
	for (list<student>::iterator iter = Student_Chart.begin(); iter != Student_Chart.end(); iter++) {
		if (iter->Index() == search_index) {
			cout << "找到了" << endl;
			cout << "考生信息:" << endl;
			cout << (*iter);
			return;
		}
	}
	cout << "很遗憾,没找到" << endl;
	return;
}
void ctl_part::change(string change_index) {
	for (list<student>::iterator iter = Student_Chart.begin(); iter != Student_Chart.end(); iter++) {
		if (iter->Index() == change_index) {
			cout << "你要修改的考生信息目前为:" << endl;
			cout << (*iter);
			student temp;
			cout << "请输入你要修改的内容:" << endl;
			cin >> temp;
			(*iter) = temp;
		}
	}
}



/*
用于传递参数的渲染类
*/
class render_part {
private:
	string string_bar;
	int num_bar;
public:
	render_part() { ; };

	int build_picture() {
		cout << "首先请建立考生信息系统" << endl;
		cout << "请输入考生人数" << endl;
		cin >> num_bar;
		cout << "请依次输入考生的考号,姓名,性别,年龄,以及报考类别" << endl;
		return num_bar;
	}
	int ask_requirement() {
		cout << "请输入你想要进行的操作(1是插入,2是删除,3是查找,4是修改,5是统计,0为取消操作)";
		int choise = 0;
		cin >> choise;
		return choise;
	}
	int insert_picture() {
		cout << "请输入你想要插入的位置:";
		int position = 0;
		cin >> position;
		return position;
	}
	string rubber_picture() {
		cout << "请输入你想要删除的考生编号:";
		string erase_index;
		cin >> erase_index;
		return erase_index;
	}
	string search_picture() {
		cout << "请输入你想要查找的考生的编号";
		string search_index;
		cin >> search_index;
		return search_index;
	}
	string change_picture() {
		cout << "请输入你想要修改的考生考号";
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
	whole_system() { cout << "欢迎进入学生信息管理系统" << endl; };
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
	/*得到要输入的学生数*/
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