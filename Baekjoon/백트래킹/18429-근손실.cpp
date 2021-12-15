// Date	 : 2021-11-04
// BOJ	 : 18429-±Ù¼Õ½Ç
// Genre : 
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"

using namespace std;

int N, K;
int weight[8];
bool visited[8];
int answer;

void dfs(int cnt, int nowWeight)
{
	if (cnt == N)
	{
		answer++;
		return;
	}
	for (int i = 0; i < N; i++)
	{
		if (visited[i]) continue;

		int tempSum = nowWeight + weight[i] - K;
		if (tempSum < 500) continue;

		visited[i] = true;
		dfs(cnt + 1, tempSum);
		visited[i] = false;
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
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> weight[i];
	}
	dfs(0, 500);
	cout << answer << endl;

	return 0;
}