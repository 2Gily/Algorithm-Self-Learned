#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

/*
3�� �������� ���� �� ����.
��� ���� �� ���� �ڸ��� ���־���

3�ܴ����� ������

0 1 1+ MAX(1 0 1 or 0 1 1)

1 0 1 + MAX(1 0 1 or 0 1 1)

1 1 0 + MAX(1 1 0 or 1 0 1 or 0 1 1)

=>

N��° dp[N]�� �ش� ��ġ������ ���� ū ������ �����ϸ� �޸����̼� �ϴ� �迭
*/
int main(void)
{
	int N = 0;

	cin >> N;

	vector<int> wine(N + 1, 0);
	vector<int> dp(N + 1, 0);

	for (int i = 1; i <= N; i++)
	{
		int temp = 0;

		cin >> wine[i];
	}

	dp[1] = wine[1];
	dp[2] = wine[1] + wine[2];

	for (int i = 3; i <= N; i++)
	{
		dp[i] = wine[i] + max(dp[i - 2], wine[i - 1] + dp[i - 3]);
		dp[i] = max(dp[i], dp[i - 1]);
	}

	cout << dp[N] << endl;

	return 0;
}