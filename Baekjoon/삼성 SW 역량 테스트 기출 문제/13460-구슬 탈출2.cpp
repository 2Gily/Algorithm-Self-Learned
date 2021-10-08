// Date	 : 2021-10-07
// BOJ	 : 13460
// Title : ���� Ż��2
// Genre : ����
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
	int ry, rx; // ���� ���� ��ǥ
	int by, bx; // �Ķ� ���� ��ǥ
	int cnt; // �̵��� �Ÿ�
};

int N, M; // ����,����
Coor red, blue;
char board[MAX][MAX]; 
bool  visited[MAX][MAX][MAX][MAX]; // [redY][redX][blueY][blueX] �湮ó��
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

			// ������ ���� ��ġ�� �������� �Ǵ� ��� �Ÿ��� �Ǻ����ش�. (���� ��ġ - ���� ��ġ = �Ÿ�)
			if (nry == nby && nrx == nbx)
			{
				// �� ���� ������ ������ ��ġ�� �� ĭ��ŭ �ڷ� �����δ�.
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
	// '.'�� �� ĭ�� �ǹ��ϰ�, 
	// '#'�� ���� �̵��� �� ���� ��ֹ� �Ǵ� ���� �ǹ��ϸ�,
	// 'O'�� ������ ��ġ�� �ǹ��Ѵ�.
	// 'R'�� ���� ������ ��ġ, 'B'�� �Ķ� ������ ��ġ�̴�.
	// �Ķ� ����, ���� ���� ��� ó�� ���� ���� �� �̵��ϴ� ������ ���� ������� üũ�ؾ���
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