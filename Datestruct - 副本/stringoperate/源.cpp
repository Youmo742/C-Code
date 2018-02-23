/*	String.cpp
*	用数组来存储串
*	实现字符串的基本操作
*/
#include <iostream>

const int MAXSIZE = 50;
using namespace std;

int length = 0;
//求串长
int Strlength(char  *p)
{
	int i = 0;
	while (p[i++] != '\0')
	{
		length++;
	}
	return length;
}
//串赋值函数
void StrAssign(char *s1,char *s2)
{
	for (int i = 0; i < strlen(s2); i++)
	{
		s1[i] = s2[i];
	}
	cout << s1 << endl;
}
//串连接函数
int StrConnect(char *s1, char *s2,char *s)
{
	if (strlen(s1) + strlen(s2) > MAXSIZE)
	{
		cout << "长度超限" << endl;
		return -1;
	}
	for (int i = 0; i < strlen(s1); i++)
	{
		s[i] = s1[i];
	}
	for (int i = strlen(s1),j=0;j<strlen(s2); i++,j++)
	{
		s[i] = s2[j];
	}
	cout << s << endl;
	return 1;
}
//求子串函数
int SubStr(const char *s1,char *s2, int i, int len)
{
	if (i < 0 || (i > strlen(s1)))
	{
		s2 = "\0";
		return 0;
	}
	else
	for (int t = i,j=0; (t < i + len)&&(s1[i]!='\0'); t++,j++)
	{
		s2[j] = s1[t];
	}
	cout << s2 << endl;
	return 1;
}
//串比较函数
int StrCmp(char *s1, char *s2)
{
	if (strlen(s1) == strlen(s2))
	{
		for (int i = 0; i < strlen(s1); i++)
		{
			if (s1[i] != s2[i])
				return 0;
		}
	}
	else if (strlen(s1) > strlen(s2))
		return 1;
	else
		return -1;
}
//子串定位函数
int Strindex(char *s1, char *t)
{
	if (strlen(t) > strlen(s1))
		return -1;
	else
	{
		int index = 0;
		for (int i = 0,j=0;(j<strlen(s1))&& (i < strlen(t));)
		{
			if (s1[j] == t[i])
			{
				i++;
				j++;
				if (i == strlen(t))
					return index+1;
			}
			else
			{
				i = 0;
				j=index+1;
				index++;
			}
		}
		return -1;
	}
}
//串插入函数
int Strinsert(char *s1, int i, char *t)
{
	if (i<0 || i>strlen(s1))
	{
		cout << "有误" << endl;
		return -1;
	}
	else if (i == strlen(s1))
	{
		for (int i = strlen(s1),j=0; i < strlen(s1) + strlen(t); i++,j++)
		{
			s1[i] = t[j];
		}
	}
	else
	{
		for (int index = strlen(s1) + strlen(t), m = strlen(s1); (m - i) >= 0; index--, m--)
		{
			s1[index] = s1[m];
		}
		for (int index = i, j = 0; index <= strlen(t); index++, j++)
		{
			s1[index] = t[j];
		}
	}
	cout << s1 << endl;
	return 1;
}
//串删除函数，从第i个字符开始的len个长度的字符
int StrDlelete(char *s1,int i,int len)
{
	if (i > strlen(s1))
	{
		cout << "字符串长度超出" << endl;
		return -1;
	}
	//将i+len后面的元素向前移动len位
	for (int index = i +len , m =i;index<strlen(s1); index++, m++)
	{
		s1[m] = s1[index];
	}
	//将移动后最后的len个元素置空
	for (int index = strlen(s1)-len; index < strlen(s1); index++)
	{
		s1[index] = '\0';
	}
	cout << s1 << endl;
	return 1;
}
int main()
{
	char sString1[MAXSIZE]="scscd";
	char sString2[MAXSIZE]="kjnsdv";
	char subT[MAXSIZE] = "fsd";
	char strconnect[2 * MAXSIZE]="\0";
	char subString[MAXSIZE] = "\0";
	cout << "s1=" << sString1 << endl;
	cout << "s2=" << sString2 << endl;
	cout << "subS=" << subT << endl;

	cout << "串长s1" << endl;
	cout << Strlength(sString1) << endl;

	//	cout << "串赋值s2 to s1" << endl;
	//	StrAssign(sString1, sString2);

	cout << "连接后 "<<endl;
	StrConnect(sString1, sString2,strconnect);

	
	cout << "对s1求子串" << endl;
	int first, end;
	cout << "起始位置   " << "子串长" << endl;
	cin >> first >> end;
	SubStr(sString1,subString, first, end);	
	//	cout << subString << endl;
	
	cout << "s1和s2比较" << endl;
	cout << StrCmp(sString1, sString2) << endl;

	
	cout << "对String2子串定位" << endl;
	cout << "输入要查询子串" << endl;
	char subT2[MAXSIZE]="\0";
	cin >> subT2;
	cout << Strindex(sString2, subT2) << endl;
	
	
	cout << "插入子串" << endl;
	cout << "输入在哪插入子串" << endl;
	int t = 0;
	cin >> t;
	cout << "在String2的位置"<<t<<"处插入subT 串"<< endl;
	Strinsert(sString2, t, subT);
	

	cout << "对串String2删除操作" << endl;
	cout << "输入要删除的位置	   " << "要删除的长度" << endl;
	int weizhi = 0, chang = 0;
	cin >> weizhi >> chang;
	StrDlelete(sString2, weizhi, chang);

	system("pause");
	return 0;
}