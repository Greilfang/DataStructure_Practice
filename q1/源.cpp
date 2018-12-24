#include<iostream>
#include<list>
#include<string>
#include"student.h"
using namespace std;
int main() {
	whole_system stu_system;
	stu_system.start_to_build();
	while (true) {
		stu_system.display_statistics();
		int client_requiremnt = stu_system.require();
		if (client_requiremnt == 0) {
			break;
		}
		else {
			stu_system.excute_requirement(client_requiremnt);
		}
	}
	system("pause");
}