// Date	 : 2022-04-12
// BOJ	 : 2644-촌수계산
// Genre : DFS, BFS
#include <vector>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#define endl "\n"
#define MAX 101
using namespace std;

int n, m;
int me, you;
int visited[MAX];
vector<vector<int>> fam;


void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int BFS()
{
	queue<pair<int, int>> q; // 부모, 거리
	visited[me] = true;		//
	q.push({ me,0 });

	while (!q.empty())
	{
		int cur = q.front().first;
		int curDist = q.front().second;
		int size = fam[cur].size();
		if (cur == you) return curDist;
		q.pop();

		if (size > 0)
		{
			for (auto next : fam[cur])
			{
				if (visited[next] ) continue;
				q.push({ next,curDist + 1 });
				visited[next] = true;
			}
		}
	}
	return -1;
}

int main(void)
{
	init();

	memset(visited, false, sizeof(visited));

	cin >> n;
	cin >> me >> you;
	cin >> m;

	fam.resize(n + 1);

	for (int j = 0; j < m; j++)
	{
		int p, c;
		cin >> p >> c;
		fam[c].push_back(p);
		fam[p].push_back(c);
	}

	cout << BFS() << endl;

	return 0;
}