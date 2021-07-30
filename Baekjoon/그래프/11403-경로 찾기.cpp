#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#define endl "\n"
#define MAX 101
using namespace std;

int g[MAX][MAX];
bool visit[MAX][MAX];
int N;

void floyd(void)
{
	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (g[i][k] == 0 || g[k][j] == 0) continue;
				g[i][j] = 1;
			}
		}
	}
}

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main(void)
{
	init();
	cin >> N;
	for (int start = 0; start < N; start++)
	{
		for (int end = 0; end < N; end++)
		{
			cin >> g[start][end]; // 그래프 g는 방향이 있는 그래프.
		}
	}

	floyd();

	for (int start = 0; start < N; start++)
	{
		for (int end = 0; end < N; end++)
		{
			cout << g[start][end] << " "; // 그래프 g는 방향이 있는 그래프.
		}
		cout << endl;
	}


	return 0;
}