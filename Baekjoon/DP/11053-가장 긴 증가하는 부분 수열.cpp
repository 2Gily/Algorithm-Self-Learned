/*
���� A = {10, 20, 10, 30, 20, 50}

10 20 30 50

1. �����ϴ� ������ ��.
2. n-1, n, n+1�� ���� ���� ū ��.

������ ���ذ� �� �ȵǴµ�...

������ n+d �� ������������ d�� ū ���� ã����� ������...

d�� ���� ������ ������ �κ� �������� ���� �� ������ ã����� ������?

�Ʒ� ������ �� ����.
*/

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#define MAX 1001

using namespace std;

int main()
{
	int N; 
	int number[MAX];
	int dp[MAX];

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> number[i];
	}

	for (int i = 0; i < N; i++)
	{
		dp[i] = 1;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (number[j] < number[i] && dp[j] >= dp[i])
			{
				dp[i] = dp[j] + 1;
			}
		}
	} 
	
	int max = -1;

	for (int i = 0; i < N; i++)
	{
		if (max < dp[i]) max = dp[i];
	}

	cout << max;

	return 0;
}

