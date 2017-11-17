#include <iostream>
using namespace std;

int Fibonacci(int n)
{
	if (n == 1)
		return 1;
	else if (n == 2)
		return 1;
	else
		return Fibonacci(n - 1) + Fibonacci(n - 2);
}
int main()
{
	int num;
	cin >> num;
	cout << Fibonacci(num);
	system("pause");
}
