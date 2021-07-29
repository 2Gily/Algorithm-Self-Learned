#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"

using namespace std;

int dp[50];

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void fibo(int n)
{
	dp[1] = 1;
	dp[2] = 1;

	for (int i = 3; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
}

int main(void)
{
	init();
	int n;
	cin >> n;
	fibo(n);

	cout << dp[n] << endl;

	return 0;
}