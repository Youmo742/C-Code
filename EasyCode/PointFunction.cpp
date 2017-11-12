#include <iostream>
 using namespace std;

int arr(const int *arr,  int n)
{
	int sum = 0;
	for (int i = 0;i < n;i++)
	{
		cout << " " << *arr;
		sum += *(arr++);
		
	}
	return sum;
}
int main1()
{
	const int n = 5;
	int a[n] = { 1,2,3,4,5 };
	cout << ' '<<(arr(a, n));
	cin.get();
	return 0;
}
