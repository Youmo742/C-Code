#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define time 5.9
void total()
{
	int n = 0;
	int i = 0,t=0;
	double totime[33] = { 0 };
	int index1 = 0,index2=0;
	int a[33];
	while(scanf("%d",&n))
	{
		if (n == 0)
			break;
		a[0] = 0;
			for (index1 = 1;index1 <= n;index1++)
			{
				scanf("%d", &a[index1]);
			}
			for (index2 = 1;index2 <= n;index2++)
			{
				totime[i] += ((abs((a[index2] - a[index2 - 1])))*time);
			}
			i++;
	}
	while(t<i)
	printf("%.2f\n", totime[t++]);
}
int main()
{
	total();
	system("pause");
	return 0;
}