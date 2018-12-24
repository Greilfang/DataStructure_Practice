#include<iostream>
#include<time.h>
#include<string>
#include"mySorts.h"
using namespace std;
int main()
{
	srand((int)time(NULL));
	cout << "**                               排序算法比较                               **" << endl;
	cout << "==============================================================================" << endl;
	cout << "**                              1 --- 冒泡排序                              **" << endl;
	cout << "**                              2 --- 选择排序                              **" << endl;
	cout << "**                              3 --- 直接插入排序                          **" << endl;
	cout << "**                              4 --- 希尔排序                              **" << endl;
	cout << "**                              5 --- 快速排序                              **" << endl;
	cout << "**                              6 --- 堆排序                                **" << endl;
	cout << "**                              7 --- 归并排序                              **" << endl;
	cout << "**                              8 --- 基数排序                              **" << endl;
	cout << "**                              9 --- 退出程序                              **" << endl;
	cout << "==============================================================================" << endl;
	int  sort_size = 0;
	cout << "请输入你要排序的数的个数" << endl;;
	cin >> sort_size;
	int order = 0;
	cout << "请选择排序算法" << endl;
	cin >> order;
	int * sort_array = new int[sort_size];
	//数组初始化
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
			cout << "输入发生错误!" << endl;
		}
		cout<< "请选择排序算法:"<<endl;
		cin >> order;

	}




	system("pause");
}