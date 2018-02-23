/*	String.cpp
*	���������洢��
*	ʵ���ַ����Ļ�������
*/
#include <iostream>

const int MAXSIZE = 50;
using namespace std;

int length = 0;
//�󴮳�
int Strlength(char  *p)
{
	int i = 0;
	while (p[i++] != '\0')
	{
		length++;
	}
	return length;
}
//����ֵ����
void StrAssign(char *s1,char *s2)
{
	for (int i = 0; i < strlen(s2); i++)
	{
		s1[i] = s2[i];
	}
	cout << s1 << endl;
}
//�����Ӻ���
int StrConnect(char *s1, char *s2,char *s)
{
	if (strlen(s1) + strlen(s2) > MAXSIZE)
	{
		cout << "���ȳ���" << endl;
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
//���Ӵ�����
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
//���ȽϺ���
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
//�Ӵ���λ����
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
//�����뺯��
int Strinsert(char *s1, int i, char *t)
{
	if (i<0 || i>strlen(s1))
	{
		cout << "����" << endl;
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
//��ɾ���������ӵ�i���ַ���ʼ��len�����ȵ��ַ�
int StrDlelete(char *s1,int i,int len)
{
	if (i > strlen(s1))
	{
		cout << "�ַ������ȳ���" << endl;
		return -1;
	}
	//��i+len�����Ԫ����ǰ�ƶ�lenλ
	for (int index = i +len , m =i;index<strlen(s1); index++, m++)
	{
		s1[m] = s1[index];
	}
	//���ƶ�������len��Ԫ���ÿ�
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

	cout << "����s1" << endl;
	cout << Strlength(sString1) << endl;

	//	cout << "����ֵs2 to s1" << endl;
	//	StrAssign(sString1, sString2);

	cout << "���Ӻ� "<<endl;
	StrConnect(sString1, sString2,strconnect);

	
	cout << "��s1���Ӵ�" << endl;
	int first, end;
	cout << "��ʼλ��   " << "�Ӵ���" << endl;
	cin >> first >> end;
	SubStr(sString1,subString, first, end);	
	//	cout << subString << endl;
	
	cout << "s1��s2�Ƚ�" << endl;
	cout << StrCmp(sString1, sString2) << endl;

	
	cout << "��String2�Ӵ���λ" << endl;
	cout << "����Ҫ��ѯ�Ӵ�" << endl;
	char subT2[MAXSIZE]="\0";
	cin >> subT2;
	cout << Strindex(sString2, subT2) << endl;
	
	
	cout << "�����Ӵ�" << endl;
	cout << "�������Ĳ����Ӵ�" << endl;
	int t = 0;
	cin >> t;
	cout << "��String2��λ��"<<t<<"������subT ��"<< endl;
	Strinsert(sString2, t, subT);
	

	cout << "�Դ�String2ɾ������" << endl;
	cout << "����Ҫɾ����λ��	   " << "Ҫɾ���ĳ���" << endl;
	int weizhi = 0, chang = 0;
	cin >> weizhi >> chang;
	StrDlelete(sString2, weizhi, chang);

	system("pause");
	return 0;
}