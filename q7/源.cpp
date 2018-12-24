#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

deque<int> huf_order;
int sum, total;

int main()
{
	int n;
	sum  = 0;
	cin>>n;
	for (int i = 1; i <= n; i++)
	{
		int branch_length;
		cin >> branch_length;
		huf_order.push_back(branch_length);
	}
	sort(huf_order.begin(), huf_order.end());
	while (huf_order.size() > 1)
	{
		int temp;
		temp = huf_order.front();
		huf_order.pop_front();
		temp += huf_order.front();
		sum += temp;
		huf_order.pop_front();
		//		de.push_front(t);
		bool flag = true;
		for (int i = 0; i < huf_order.size(); ++i) {
			if (huf_order[i] >= temp)
			{
				//因为基本有序,所以没有快排
				huf_order.insert(huf_order.begin() + i, temp);
				flag = false;
				break;
			}
		}
		if (flag) {
			//插到队尾
			huf_order.push_back(temp);
		}
	}
	cout << "总价格为" << endl;
	cout<<sum<<endl;
	system("pause");
}