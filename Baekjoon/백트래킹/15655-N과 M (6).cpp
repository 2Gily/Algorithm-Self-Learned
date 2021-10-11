// Date	 : 2021-10-11
// BOJ	 : 15655-N°ú M (6)
// Genre : BackTracking
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"
#define MAX 9

using namespace std;

int N, M;
int visited[MAX];
vector<int> number;

void dfs(int idx, int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < N; i++)
		{
			if (visited[i]) cout << number[i] << " ";
		}
		cout << endl;
		return;
	}
	if (idx >= N || visited[idx]) return;
	visited[idx] = true;
	dfs(idx + 1, cnt + 1);
	visited[idx] = false;
	dfs(idx + 1, cnt);
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
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		number.push_back(temp);
	}
	sort(number.begin(), number.end());
	dfs(0,0);

	return 0;
}