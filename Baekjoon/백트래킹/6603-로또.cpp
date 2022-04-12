// Date	 : 2022-04-12
// BOJ	 : 
// Genre : 
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#define endl "\n"
#define MAX 50
using namespace std;

int N;
bool visited[MAX];
vector<int> number;

void dfs(int idx, int cnt)
{
	if (cnt == 6)
	{
		for (int i = 0; i < MAX; i++)
		{
			if (visited[i]) cout << number[i] << " ";
		}
		cout << "\n";
		return;
	}
	if (idx >= N) return;
	if (visited[idx]) return;

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

	while (true)
	{
		memset(visited, false, sizeof(visited));
		number.clear();

		cin >> N;
		if (N == 0) return 0;

		for(int i = 0 ; i < N ; i++)
		{
			int temp;
			cin >> temp;
			number.push_back(temp);
		}
		dfs(0, 0);
		cout << endl;
	}
}