// Date	 : 2021-10-07
// BOJ	 : 13460
// Title : 구슬 탈출2
// Genre : 구현
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#define endl "\n"
#define MAX 11

using namespace std;

typedef struct Coordinate {
	int y, x;
}Coor;

typedef struct Status {
	int ry, rx; // 빨간 구슬 좌표
	int by, bx; // 파란 구슬 좌표
	int cnt; // 이동한 거리
};

int N, M; // 세로,가로
Coor red, blue;
char board[MAX][MAX]; 
bool  visited[MAX][MAX][MAX][MAX]; // [redY][redX][blueY][blueX] 방문처리
queue<Status> q;
int dy[4] = {-1,0,1, 0}; // 0 : Up, 1 : Right, 2 : Down, 3 : Left
int dx[4] = { 0,1,0,-1};

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void gravity(int &y, int &x, int &dist, int &dir)
{
	while (board[y][x] != 'O' && board[y + dy[dir]][x + dx[dir]] != '#')
	{
		y += dy[dir];
		x += dx[dir];
		dist += 1;
	}
}

void search_hole(void)
{
	visited[red.y][red.x][blue.y][blue.x] = true;
	q.push({ red.y,red.x,blue.y,blue.x,0 });

	while (!q.empty())
	{
		int ry = q.front().ry;
		int rx = q.front().rx;
		int by = q.front().by;
		int bx = q.front().bx;
		int cnt = q.front().cnt;
		q.pop();

		if (cnt >= 10) break;

		for (int dir = 0; dir < 4; dir++)
		{
			int nry = ry , nrx = rx ;
			int nby = by , nbx = bx ;
			int rDist = 0, bDist = 0, ncnt = cnt + 1;

			gravity(nry, nrx, rDist, dir);
			gravity(nby, nbx, bDist, dir);

			if (board[nby][nbx] == 'O') continue;
			if (board[nry][nrx] == 'O')
			{
				cout << ncnt << endl;
				return;
			}

			// 구슬이 같은 위치에 놓여지게 되는 경우 거리로 판별해준다. (지금 위치 - 이전 위치 = 거리)
			if (nry == nby && nrx == nbx)
			{
				// 더 많이 움직인 구슬의 위치를 한 칸만큼 뒤로 움직인다.
				if (rDist > bDist)
				{
					nry -= dy[dir];
					nrx -= dx[dir];
				}
				else
				{
					nby -= dy[dir];
					nbx -= dx[dir];
				}
			}

			if (visited[nry][nrx][nby][nbx]) continue;
			visited[nry][nrx][nby][nbx] = true;
			q.push({ nry, nrx, nby, nbx, ncnt });
		}
	}

	cout << -1 << endl;
}

int main(void)
{
	// '.'은 빈 칸을 의미하고, 
	// '#'은 공이 이동할 수 없는 장애물 또는 벽을 의미하며,
	// 'O'는 구멍의 위치를 의미한다.
	// 'R'은 빨간 구슬의 위치, 'B'는 파란 구슬의 위치이다.
	// 파란 구슬, 빨간 구슬 어떤게 처음 시작 점이 더 이동하는 방향의 벽에 가까운지 체크해야함
	init();
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;
		for (int j = 0; j < M; j++)
		{
			board[i][j] = temp[j];

			if (temp[j] == 'R') red.y = i, red.x = j;
			else if(temp[j] =='B') blue.y = i, blue.x = j;
		}
	}

	search_hole();

	return 0;
}