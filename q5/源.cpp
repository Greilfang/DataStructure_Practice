#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<stdlib.h>
using namespace std;

int main(void)
{
	int A[1001];/*����������ģ����������*/
	int B[1001];
	int all_guests, number, j = 0, k = 0;
	cin >> all_guests;
	cout << "���Ϊ:";
	for (int i = 0; i < all_guests; i++)
	{
		//���ֲ�ͬ���д���Ĺ˿����
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
	//J��K�Ǵ�������
	int J = 0, K = 0;
	while (j > 0 && k > 0){
		//��Ϊ���ȴ���A,��A��ѭ���ŵ�ǰ��
		for (int i = 0; i < 2; i++) {
			cout << A[J++];
			//��ǰ����˲������һ���˾�����ո�
			if (all_guests != 1) {
				cout << " ";
			}
			j--; all_guests--;/*A��������������-1*/
		}

		for (int i = 0; i < 1; i++){
			printf("%d", B[K++]);
			//��ǰ����˲������һ���˾�����ո�
			if (all_guests != 1){
				printf(" ");
			}
			k--; all_guests--;/*B��������������-1*/
		}
	}

	while (j>0)/*��A��ʣ�µ������*/
	{
		cout<<A[J++];
		if (j != 1){
			cout << " ";
		}
		j--;
	}
	while (k>0)/*��B��ʣ�µ������*/
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