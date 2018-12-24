#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<stdlib.h>
using namespace std;

int main(void)
{
	int A[1001];/*用两个数组模拟两个队列*/
	int B[1001];
	int all_guests, number, j = 0, k = 0;
	cin >> all_guests;
	cout << "结果为:";
	for (int i = 0; i < all_guests; i++)
	{
		//划分不同银行处理的顾客序号
		cin >> number;
		if (number % 2 != 0)
		{
			A[j++] = number;
		}
		else
		{
			B[k++] = number;
		}
	}
	//J和K是处理序列
	int J = 0, K = 0;
	while (j > 0 && k > 0){
		//因为优先处理A,把A的循环放到前面
		for (int i = 0; i < 2; i++) {
			cout << A[J++];
			//当前这个人不是最后一个人就输出空格
			if (all_guests != 1) {
				cout << " ";
			}
			j--; all_guests--;/*A中人数和总人数-1*/
		}

		for (int i = 0; i < 1; i++){
			printf("%d", B[K++]);
			//当前这个人不是最后一个人就输出空格
			if (all_guests != 1){
				printf(" ");
			}
			k--; all_guests--;/*B中人数和总人数-1*/
		}
	}

	while (j>0)/*将A中剩下的人输出*/
	{
		cout<<A[J++];
		if (j != 1){
			cout << " ";
		}
		j--;
	}
	while (k>0)/*将B中剩下的人输出*/
	{
		cout<<B[K++];
		if (k != 1)
		{
			cout << " ";
		}
		k--;
	}
	cout << endl;
	system("pause");
}