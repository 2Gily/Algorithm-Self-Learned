// Date	 : 2021-09-27
// BOJ	 : 21609
// Title : 상어중학교
// Genre : 구현
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>
#define endl "\n"
#define MAX 21
#define INF -2

using namespace std;

typedef struct INFO {
	int y;
	int x;
	int rainbow;
	int total;
};

struct cmp {
	bool operator()(INFO &A, INFO &B)
	{
		if (A.total == B.total)
		{
			if (A.rainbow == B.rainbow)
			{
				if (A.y == B.y)
				{
					return A.x < B.x;
				}
				return A.y < B.y;
			}
			return A.rainbow < B.rainbow;
		}
		return A.total < B.total;
	}
};

int N, M;
int score;
int board[MAX][MAX];
int visited[MAX][MAX];
priority_queue<INFO, vector<INFO>, cmp> pq;
int dy[4] = { -1,  0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

void reset_visited(int visited[MAX][MAX])
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (board[i][j] == 0 && visited[i][j] == 1) visited[i][j] = 0;
			else if (board[i][j] == -1 || board[i][j] == INF) visited[i][j] = -1;
		}
	}
}

void find_group(void)
{
	queue<pair<int, int>> q;
	memset(visited, 0, sizeof(visited));

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			reset_visited(visited);
			if (visited[i][j] == 1 || visited[i][j] == -1) continue; // 검은색 블록, 방문했던적 있는 블록, 빈 블록 패스
			if (board[i][j] == 0) continue; // 무지개 블록 패스
			int total = 1;
			int rainbow = 0;
			visited[i][j] = 1;
			q.push({ i,j });

			while (!q.empty())
			{
				int y = q.front().first;
				int x = q.front().second;
				q.pop();

				for (int dir = 0; dir < 4; dir++)
				{
					int ny = y + dy[dir];
					int nx = x + dx[dir];

					if (ny <= 0 || ny > N || nx <= 0 || nx > N) continue;
					if (visited[ny][nx] == 1 || visited[ny][nx] == -1) continue;
					if (board[ny][nx] != board[i][j] && board[ny][nx] != 0) continue;
					if (board[ny][nx] == 0) rainbow++;
					visited[ny][nx] = 1;
					total++;
					q.push({ ny,nx });
				}
			}

			if (total >= 2) pq.push({ i,j,rainbow,total });
		}
	}
}

void sum_score(int y, int x)
{
	queue<pair<int, int>> q;
	queue<pair<int, int>> tq;
	memset(visited, 0, sizeof(visited));
	reset_visited(visited);
	int total = 1;
	visited[y][x] = 1;
	q.push({ y,x });
	tq.push({ y,x });

	while (!q.empty())
	{
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];

			if (ny <= 0 || ny > N || nx <= 0 || nx > N) continue;
			if (visited[ny][nx] == 1 || visited[ny][nx] == -1) continue;
			if (board[ny][nx] != board[y][x] && board[ny][nx] != 0) continue;
			visited[ny][nx] = 1;
			total++;
			q.push({ ny,nx });
			tq.push({ ny,nx });
		}
	}

	while (!tq.empty())
	{
		int ny = tq.front().first;
		int nx = tq.front().second;
		board[ny][nx] = INF;
		tq.pop();
	}

	score += (total * total);
}

void gravity(void)
{
	for (int i = N - 1; i >= 1; i--)
	{
		for (int j = 1; j <= N; j++)
		{
			if (board[i][j] >= 0)
			{
				int now = i;
				int next = now + 1;
				while (true)
				{
					if (board[next][j] == INF && next <= N)
					{
						board[next][j] = board[now][j];
						board[now][j] = INF;
						now++;
						next++;
					}
					else break;
				}
			}
		}
	}
}

void rotate_counter(void)
{
	queue<int> tq;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			tq.push(board[i][j]);
		}
	}
	for (int j = 1; j <= N; j++)
	{
		for (int i = N; i >= 1; i--)
		{
			int temp = tq.front();
			tq.pop();
			board[i][j] = temp;
		}
	}
}


void print_debug(int n)
{
	if (n == 1)
	{
		cout << "TEST 1" << endl;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				cout.width(3);
				if (board[i][j] == INF) cout << "X" << " ";
				else cout << board[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	else if (n == 2)
	{
		cout << "TEST 2" << endl;
		while (!pq.empty())
		{
			cout << pq.top().total << " " << pq.top().rainbow << " " << pq.top().y << " " << pq.top().x << endl;
			pq.pop();
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
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> board[i][j];
		}
	}

	while (true)
	{
		while (!pq.empty()) pq.pop();
		// 1. 가장 큰 블록그룹 찾기
		find_group();
		if (pq.empty()) break;
		// 2. 블록그룹 제거하고 B^2 점수
		sum_score(pq.top().y, pq.top().x);
		// 3. 중력
		gravity();
		// 4. 반시계방향
		rotate_counter();
		// 5. 중력
		gravity();
	}

	cout << score << endl;

	return 0;
}