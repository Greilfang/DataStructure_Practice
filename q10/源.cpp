#include<iostream>
#include<time.h>
#include<string>
#include"mySorts.h"
using namespace std;
int main()
{
	srand((int)time(NULL));
	cout << "**                               �����㷨�Ƚ�                               **" << endl;
	cout << "==============================================================================" << endl;
	cout << "**                              1 --- ð������                              **" << endl;
	cout << "**                              2 --- ѡ������                              **" << endl;
	cout << "**                              3 --- ֱ�Ӳ�������                          **" << endl;
	cout << "**                              4 --- ϣ������                              **" << endl;
	cout << "**                              5 --- ��������                              **" << endl;
	cout << "**                              6 --- ������                                **" << endl;
	cout << "**                              7 --- �鲢����                              **" << endl;
	cout << "**                              8 --- ��������                              **" << endl;
	cout << "**                              9 --- �˳�����                              **" << endl;
	cout << "==============================================================================" << endl;
	int  sort_size = 0;
	cout << "��������Ҫ��������ĸ���" << endl;;
	cin >> sort_size;
	int order = 0;
	cout << "��ѡ�������㷨" << endl;
	cin >> order;
	int * sort_array = new int[sort_size];
	//�����ʼ��
	for (int i = 0; i < sort_size; i++) {
		sort_array[i] = rand();
	}
	while (true && order != 9) {
		
		switch (order) {
		case 1:
			bubbleSort(sort_array, sort_size);
			break;
		case 2:
			selectionSort(sort_array, sort_size);
			break;
		case 3:
			insertSort(sort_array, sort_size);
			break;
		case 4:
			shellSort(sort_array, sort_size);
			break;
		case 5:
			quickSortHelp(sort_array, sort_size);
			break;
		case 6:
			heapSort(sort_array, sort_size);
			break;
		case 7:
			mergeSortHelp(sort_array, sort_size);
			break;
		case 8:
			radixSort(sort_array, sort_size);
			break;
		default:
			cout << "���뷢������!" << endl;
		}
		cout<< "��ѡ�������㷨:"<<endl;
		cin >> order;

	}




	system("pause");
}