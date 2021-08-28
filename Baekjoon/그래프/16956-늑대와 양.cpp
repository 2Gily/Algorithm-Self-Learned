// Date	 : 2021-08-28
// BOJ	 : 16956
// Title : 늑대와 양
// Genre : BFS, DFS, 그래프 탐색
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#define endl "\n"
#define MAX 501
using namespace std;

int R, C; // 행, 열
char map[MAX][MAX];
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main(void)
{
	init();
	cin >> R >> C;
	queue<pair<int, int>> q;

	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'W') q.push({ i,j });
		}
	}

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny <= 0 || ny > R || nx <= 0 || nx > C) continue;

			if (map[ny][nx] == '.') map[ny][nx] = 'D';
			else if (map[ny][nx] == 'S')
			{
				cout << 0 << endl;
				return 0;
			}
		}
	}

	cout << 1 << endl;
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			cout << map[i][j];
		}
		cout << endl;
	}

	return 0;
}