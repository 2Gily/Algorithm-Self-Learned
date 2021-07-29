#include <iostream>
#include <cstdio>
#include <string>
#include <stack>

using namespace std;

string str1, str2;

int lcs[1001][1001];

int main()
{
	string temp1, temp2;
	cin >> temp1 >> temp2;

	// LCS �˰����� ���� �տ� '0'�� �ٿ��ش�.
	str1 = '0' + temp1;
	str2 = '0' + temp2;

	int len1 = str1.size();
	int len2 = str2.size();

	for (int i = 0; i < len1; i++)
	{
		for (int j = 0; j < len2; j++)
		{
			if (i == 0 || j == 0)
			{
				lcs[i][j] = 0;
				continue;
			}

			if (str1[i] == str2[j]) // ���� ���ϴ� ���� ���� ���ٸ�, lcs�� + 1
			{
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			}
			else // ���� �ٸ��ٸ� LCS�� ���� ���� Ȥ�� ������ �����´�.
			{
				if (lcs[i - 1][j] > lcs[i][j - 1])
				{
					lcs[i][j] = lcs[i - 1][j];
				}
				else
				{
					lcs[i][j] = lcs[i][j - 1];
				}
			}// lcs[i][j] = min(lcs[i-1][j], lcs[i][j-1]; �� �ٷ� ���� �� ����.
		}
	}

	/*
	// ���� �ڵ�
	for (int i = 0; i < len1; i++)
	{
		for (int j = 0; j < len2; j++)
			cout << lcs[i][j] << " ";
		cout << endl;
	}
	*/


	int i = len1 - 1;
	int j = len2 - 1;
	stack<int> st; // �Ųٷ� ���� stack�� �̿�

	while (lcs[i][j] != 0)
	{
		// ��� ����
		// cout << " i :: " << i << " j :: " << j << endl;

		// ���̺��� ���� �ѹ����̶��
		if (lcs[i][j] == lcs[i][j - 1]) // �������� �̵�
		{
			j--;
		}
		else if (lcs[i][j] == lcs[i - 1][j]) // �������� �̵�
		{
			i--;
		}
		else if (lcs[i][j] - 1 == lcs[i - 1][j - 1]) // ���� ���� ��� �ٸ� �ѹ����̶�� �밢�� �������� �̵�
		{
			st.push(i);
			i--;
			j--;
		}
	}

	// ���� ���
	cout << lcs[len1 - 1][len2 - 1] << endl;

	// �ܾ� ���
	while (!st.empty())
	{
		cout << str1[st.top()];
		st.pop();
	}
	return 0;
}