#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>

#pragma warning(disable:4996)

using namespace std;

int main(void)
{
	freopen("input.txt", "r", stdin);
	string str;
	cin >> str;

	int sum = 0;
	int temp = 0;
	bool flag = false;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '-' || str[i] == '+')
		{
			if (flag)sum -= temp;  // '-' �� �ѹ��̶� ���� �Ŀ��� ���� ���ֱ�
			else sum += temp;        // '-' �� ������ �������� �����ֱ�

			temp = 0;       // temp���� �ٽ� ����
			if (str[i] == '-')flag = true;  // '-'�� ������ flag�� true
		}
		else  //���ڰ� �����ؼ� �����µ����� �� ���� ���̱�
		{
			temp *= 10;
			temp += str[i] - '0';
		}
	}

	//������ ���� ����
	if (flag)sum -= temp;
	else sum += temp;

	cout << sum << endl;

	return 0;
}