#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#define MAX 1002
#pragma warning(disable:4996)
using namespace std;

int dp[MAX][MAX];
/*
Ǯ�̳��� ������.
<�⺻���� LIS(Longest Increasing Subsequence) ���� ���� LIS�� DP�� ��ǥ����>
2���� �迭�� ���·� ���ʿ��� ���δ� str1 ���ڿ�, ���δ� str2 ���ڿ��� �������� �Ѵ�.
������ ǥ�� ������ ���� ���ذ� ���� �������� ���� ���ϸ� ������ ����� ���� +1�� �ϸ鼭 ���� lcs���� ���Ѵ�.
*/
int main(void)
{
	freopen("input.txt", "r", stdin);
	
	int i, j;
	string str1, str2;

	cin >> str1 >> str2;

	for (i = 1; i <= str2.size(); i++)
	{
		for (j = 1; j <= str1.size(); j++)
		{
			if (str1.at(j - 1) == str2.at(i - 1))
			{
				dp[i][j] += dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	cout << dp[i - 1][j - 1] << endl;

	return 0;
}