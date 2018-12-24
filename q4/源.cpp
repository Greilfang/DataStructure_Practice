#include<iostream>
#include<string>
#include<stack>
#include<map>
using namespace std;
string resolve(string _inString);
void generate_priority(map<char, int> & _prior_list);
bool is_num(char c);
bool is_subadd(char c);
bool is_multidiv(char c);
string& trim(string &s);
//char outputPriorityAbove(stack<char> & _signals, map<char, int> & prior_list, int _prior);
int main()
{
	string inInpression, outInpression;
	while (1)
	{
		getline(std::cin,inInpression);
		outInpression = resolve(inInpression);
		cout << "结果是" << endl;
		cout << outInpression;
	}
	system("pause");
}
string resolve(string _inString_sp)
{
	//用于存放运算符号的栈
	map<char, int> prior_list;
	generate_priority(prior_list);
	stack<char> signals;
	string _inString(_inString_sp.length(), ' ');
	int ck = 0;
	for (int i = 0; i < _inString_sp.length(); i++) {
		if (_inString_sp[i] == ' ') {
			continue;
		}
		else {
			_inString[ck++] = _inString_sp[i];
		}
	}
	string _outString(2*_inString.length(),' ');
	int index = 0;
	for (int i = 0; i < _inString.length(); i++) {
		if (_inString[i] == ' ') {
			continue;
		}
		else if (is_num(_inString[i])||_inString[i]=='.') {
			_outString[index++] = _inString[i];
		}
		else if (is_subadd(_inString[i])) {
			//正负号
			if (i - 1 < 0 || (!is_num(_inString[i - 1])&&_inString[i-1]!=')')) {
				_outString[index++] = _inString[i];
			}
			//渐渐好
			else {
				while (!signals.empty()
					&& prior_list[signals.top()] >= prior_list[_inString[i]]
					&& signals.top() != '(') {
					_outString[index++] = ' ';
					_outString[index++] = signals.top();
					signals.pop();
				}
				_outString[index++] = ' ';
				signals.push(_inString[i]);
			}
		}
		else if (is_multidiv(_inString[i])) {
			while (!signals.empty() 
				&& prior_list[signals.top()] >= prior_list[_inString[i]]
				&& signals.top()!='(') {
				_outString[index++] = ' ';
				_outString[index++] = signals.top();
				signals.pop();
			}
			_outString[index++] = ' ';
			signals.push(_inString[i]);
		}
		else if (_inString[i] == '(') {
			signals.push(_inString[i]);
		}
		else if (_inString[i] == ')') {
			while (signals.top() != '(') {
				_outString[index++] = ' ';
				_outString[index++] = signals.top();
				signals.pop();
			}
			signals.pop();
		}
	}
	while (!signals.empty()) {
		_outString[index++] = ' ';
		_outString[index++] = signals.top();
		signals.pop();
	}
	_outString = trim(_outString);
	return _outString;
}
void generate_priority(map<char, int> & _prior_list) {
	//数字优先级
	for (int i = 0; i <= 9; i++) {
		_prior_list['0' + i] = 1;
	}
	//加减优先级
	_prior_list['+'] = 2;
	_prior_list['-'] = 2;
	//乘除优先级
	_prior_list['*'] = 3;
	_prior_list['/'] = 3;
	//括号优先级
	_prior_list['('] = 4;
	_prior_list[')'] = 4;
}
bool is_num(char c) {
	if (c >= '0'&&c <= '9') {
		return true;
	}
	else {
		return false;
	}
}

bool is_subadd(char c) {
	if (c == '-' || c == '+') {
		return true;
	}
	else {
		return false;
	}
}

bool is_multidiv(char c) {
	if (c == '*' || c == '/') {
		return true;
	}
	else {
		return false;
	}
}
string& trim(string &s)
{
	if (s.empty())
	{
		return s;
	}
	s.erase(0, s.find_first_not_of(" "));
	s.erase(s.find_last_not_of(" ") + 1);
	return s;
}
