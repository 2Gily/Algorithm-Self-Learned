#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#define MAX 18
#define endl "\n"
using namespace std;

typedef pair<int, int> PAIR;

int dp[MAX];
vector<PAIR> day(MAX); // { �ҿ�ð�, ����}

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main()
{
	init();
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> day[i].first >> day[i].second;

	for (int i = n; i > 0; i--)
	{
		if (i + day[i].first > n + 1) // ���� �� + �ҿ� �ϼ��� ������� �Ѿ������ ���
		{
			dp[i] = dp[i + 1]; // day[i] ����� ����
		}
		else
		{
			dp[i] = max(dp[i + 1], dp[i + day[i].first] + day[i].second);
		}
	}

	cout << dp[1] << '\n';

	return 0;
}
