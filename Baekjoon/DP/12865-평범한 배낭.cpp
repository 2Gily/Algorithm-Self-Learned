/*
<knapsack �̶�� ������ dp������ ����>


Val(i, w) -> [1 ~ i]��°���� ���ǿ� ����, w���Ա��� ������ ���� �ִ� ��ġ(VALUE)

Val(i, w) = Val(i-1, w-weight[i]) + value[i] -> i��° ��(ITEM)�� ��� �� ���¿��� i��° ����(ITEM)�� ���� ��


[����]
w >= weight[i] // ���� ��밡���� ������ ����

[��ȭ��]
Val(i, w) = (w >= weight[i]) ? max( Val(i-1,w), Val(i-1,w-weight[i])+value[i] ) : Val(i-1,w)
*/
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#define MAX 101
#pragma warning(disable:4996)

using namespace std;

int w[101]; // ����
int v[101]; // ��ġ
int dp[101][100001];

int main(void)
{
	freopen("input.txt", "r", stdin);

	int N, K; // ��ǰ�� �� N, �ؼ��� ��ƿ �� �ִ� ���� K

	cin >> N >> K;
	for (int i = 1; i <= N; i++) 
	{
		cin >> w[i] >> v[i];
	}

	for (int i = 1; i <= N; i++) 
	{
		for (int j = 1; j <= K; j++) 
		{
			if (j - w[i] >= 0) // i��° ������ ���� �� �ִٸ�?
			{ 
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]); // max(���� ���� ��, ���� ���� ��)
				
			}
			else // i��° ������ ���� �� ���ٸ�, �賶 �뷮�� ���� ���� �ʾ��� ���� ������ �ʱ�ȭ
			{ 
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	cout << dp[N][K];

	return 0;
}