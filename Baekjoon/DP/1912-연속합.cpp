#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#define MAX 100000

using namespace std;

int number[MAX] = { 0, };
int dp[MAX] = { 0, };

int main(void)
{
	int n, i;

	cin >> n;

	for (i = 0; i < n; i++) 
	{
		cin >> number[i];
		dp[i] = number[i];
	}

	int maxSum = dp[0];

	for (i = 1; i < n; i++) 
	{
		dp[i] = max(dp[i], dp[i - 1] + number[i]); // dp[i]�� 0 ~ (i-1)������ max(�ִ��� dp[i]�� ����Ǿ� �ִ� ��, dp[i-1] + number[i]�� ��)

		if (dp[i] > maxSum) 
		{
			maxSum = dp[i];
		}
	}

	cout << maxSum << endl;

	return 0;
}