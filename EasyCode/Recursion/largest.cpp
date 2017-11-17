#include <iostream>
using namespace std;

int largest(const int lins[], int lowerindex, int upperindex)
{
	int max;
	if (lowerindex == upperindex)
		return lins[lowerindex];
	else
	{
		max = largest(lins, lowerindex + 1, upperindex);
		if (max <= lins[lowerindex])
			return lins[lowerindex];
		else
			return max;
	}
}
int main()
{
	int a[5]={ 1,2,5,6,9 };
	cout<<largest(a, 0, 4);
	system("pause");
	return 0;
}
