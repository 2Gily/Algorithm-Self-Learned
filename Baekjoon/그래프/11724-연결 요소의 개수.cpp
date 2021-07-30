#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"
#define MAX 1001
using namespace std;

vector<int> vertex[MAX];
bool visit[MAX];
int cnt;

void dfs(int node)
{
	if (visit[node]) return;
	visit[node] = true;

	for (int i = 0; i < vertex[node].size(); i++)
	{
		if (visit[vertex[node][i]]) continue;
		dfs(vertex[node][i]);
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
	int V, E;
	cin >> V >> E;

	for (int i = 0; i < E; i++)
	{
		int end, start;
		cin >> start >> end;
		vertex[end].push_back(start);
		vertex[start].push_back(end);
	}

	for (int i = 1; i <= V; i++)
	{
		if (visit[i]) continue;
		cnt++;
		dfs(i);
	}

	cout << cnt << endl;

	return 0;
}