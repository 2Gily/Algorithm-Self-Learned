// Date	 : 2021-10-13
// BOJ	 : 21611-마법사 상어와 블리자드
// Genre : 구현
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>
#define endl "\n"
#define MAX 50
#define MMAX 101
using namespace std;

int N, M;
long long score;
vector<int> marble;
int board[MAX][MAX];
int dy[] = {0, -1,1,0,0 }; // Up, Down, Left, Right
int dx[] = {0, 0,0,-1,1 };
int moveDy[4] = { 0, 1, 0, -1 }; // L, U, R, D
int moveDx[4] = { -1, 0, 1, 0 };

void print_debug(void)
{
	cout << "=============" << endl;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i == N / 2 + 1 && j == N / 2 + 1)
			{
				cout << "S" << " ";
				continue;
			}
			if (board[i][j] == 0) cout << "X" << " ";
			else cout << board[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void get_marble(void)
{
	marble.clear();
	int mv = 1;
	int ny = (N+1)/2;
	int nx = (N+1)/2;
	int dir = 0;

	while (true)
	{
		for (int turn = 0; turn < 2; turn++)
		{
			for (int i = 0; i < mv; i++)
			{
				ny += moveDy[dir];
				nx += moveDx[dir];

				if (board[ny][nx]) marble.push_back(board[ny][nx]);

				if (ny == 1 && nx == 1) return;
			}
			dir = (dir + 1) % 4;
		}
		mv++;
	}
}

void set_marble(void)
{
	memset(board, 0, sizeof(board));
	int mv = 1;
	int ny = (N+1)/2;
	int nx = (N+1)/2;
	int dir = 0;
	int idx = 0;

	while (idx < marble.size())
	{
		for (int turn = 0; turn < 2; turn++)
		{
			for (int i = 0; i < mv; i++)
			{
				ny += moveDy[dir];
				nx += moveDx[dir];

				board[ny][nx] = marble[idx];
				idx++;

				if (idx >= marble.size()) return;
			}
			dir = (dir + 1) % 4;
		}
		mv++;
	}
}

void explosion(void)
{
	get_marble();
	bool boomFlag = true;

	while (boomFlag)
	{
		vector<int> temp;
		boomFlag = false;

		for (int start = 0; start < marble.size(); start++)
		{
			int end = start;

			while (end < marble.size() && marble[start] == marble[end])
			{
				end++;
			}

			if (end - start >= 4)
			{
				boomFlag = true;
				score += marble[start] * (end - start);
			}
			else
			{
				for (int i = start; i < end; i++) temp.push_back(marble[i]);
			}

			start = end - 1;
		}

		marble = temp;
	}
}

void copy_marble(void)
{	
	vector<int> temp;

	for (int start = 0; start < marble.size(); start++)
	{
		if (temp.size() > N * N) break;
			
		int end = start;

		while (end < marble.size() && marble[start] == marble[end])
		{
			end++;
		}

		int marbleCnt = end - start;
		int marbleNum = marble[start];

		temp.push_back(marbleCnt);
		temp.push_back(marbleNum);

		start = end - 1;
	}

	if (temp.size() > N * N)
	{
		for (int i = temp.size(); i > N * N; i--)
		{
			temp.pop_back();
		}
	}

	marble = temp;
	set_marble();
}

void blizzard(int dir, int dist)
{
	for (int i = 1; i <= dist; i++)
	{
		int ny = (N+1)/2 + dy[dir] * i;
		int nx = (N+1)/2 + dx[dir] * i;
		board[ny][nx] = 0;
	}

	get_marble();
	set_marble();
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

	for (int i = 1; i <= M; i++)
	{
		int dir, dist;
		cin >> dir >> dist;
		// 1. 블리자드 마법 시전
		blizzard(dir, dist);
		// 2. 구슬 이동
		// 3. 폭팔 -> 이동 -> 폭팔 -> 이동 // 더 이상 폭팔하지 않을 때 까지.
		explosion();
		// 4. 변화 단계 하나의 그룹(같은 구슬) -> A,B로 나뉘어짐 A : 그룹의 구슬 갯수, B : 구슬의 종류
		copy_marble();
	}

	cout << score << endl;

	return 0;
}