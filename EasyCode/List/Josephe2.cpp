#include <iostream>
#include <stdlib.h>
using namespace std;
int main() {
	int queue[100];
	int n, m;
	int flag = 1;
	int count = 0;
	cout << "please input the n:" << endl;
	cin >> n;
	cout << "please  input the m" << endl;
	cin >> m;
	int a[7];
	int t = 0;
	for (int j = 0;j <7;j++)
	{
		cin >> a[j];
	}
	queue[0] = 0;
	for (int i = 1;i <= n;i++)
		queue[i] = i;//编号

	for (int j = 1;j <= m;j++)
	{
		if (queue[flag] == 0)
			j--;
		if (j == m)
		{
			if (m == 0)
				cout << "出队序列：" << endl;
			cout << queue[flag];
			cout << " ";
			count++;
			queue[flag] = 0;
			j = 0;
			if(t<7)
				m = a[t++];
		}
		if (flag >= n)
			flag = flag%n;
		if (count == n)
		{
			cout << endl;
			break;
		}
		flag++;
	}
	system("pause");
	return 0;

}
