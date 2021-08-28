// Date	 : 2021-08-28
// BOJ	 : 4963
// Title : ¼¶ÀÇ °³¼ö
// Genre : BFS/DFS, ±×·¡ÇÁ Å½»ö
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>
#define endl "\n"
#define MAX 51
using namespace std;

int X, Y;
int cnt;
int map[MAX][MAX];
int visited[MAX][MAX];
int dy[] = { -1,-1, 0, 1, 1, 1, 0,-1 };
int dx[] = { 0, 1, 1, 1, 0,-1,-1,-1 };

void BFS(int y, int x)
{
	queue<pair<int, int>> q;
	visited[y][x] = true;
	q.push({ y,x });

	while (!q.empty())
	{
		int nowy = q.front().first;
		int nowx = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int ny = nowy + dy[i];
			int nx = nowx + dx[i];

			if (ny <= 0 || ny > Y || nx <= 0 || nx > X) continue;
			if (map[ny][nx] == 0) continue;
			if (visited[ny][nx]) continue;

			visited[ny][nx] = true;
			q.push({ ny,nx });
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
	while (true)
	{
		cnt = 0;
		memset(map, 0, sizeof(map));
		memset(visited, false, sizeof(visited));
		cin >> X >> Y;
		if (X == 0 && Y == 0) break;

		for (int i = 1; i <= Y; i++)
		{
			for (int j = 1; j <= X; j++)
			{
				cin >> map[i][j];
			}
		}

		for (int i = 1; i <= Y; i++)
		{
			for (int j = 1; j <= X; j++)
			{
				if (visited[i][j] || map[i][j] == 0) continue;
				++cnt;
				BFS(i, j);
			}
		}
		cout << cnt << endl;
	}


	return 0;
}