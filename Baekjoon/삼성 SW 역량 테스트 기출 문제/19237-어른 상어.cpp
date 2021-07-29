#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#define endl "\n"
#define MAX 20
#define SHARK_MAX 401

using namespace std;

typedef struct INFO {
	int shark;
	int left_time;
}INFO;

typedef struct SHARK {
	int y;
	int x;
	int dir;
};

int N, M, K;
int time;
INFO map[MAX][MAX];
SHARK shark[SHARK_MAX];
int priority_dir[SHARK_MAX][5][5];
bool life[SHARK_MAX];

int dy[5] = { 0,-1,1,0,0 };
int dx[5] = { 0,0,0,-1,1 };

void SpendTime(void)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j].left_time > 0)
			{
				map[i][j].left_time--;
			}
		}
	}
}

bool CheckLife(void)
{
	for (int i = 2; i <= M; i++)
	{
		if (!life[i]) return true;
	}

	return false;
}

void MoveShark(void)
{
	SpendTime(); // ���� �ð� ����

	for (int i = 1; i <= M; i++)
	{
		if (life[i]) continue;

		int y = shark[i].y;
		int x = shark[i].x;
		int dir = shark[i].dir;
		int now_state = 0;

		for (int j = 1; j <= 4; j++)
		{
			int ny = y + dy[priority_dir[i][dir][j]];
			int nx = x + dx[priority_dir[i][dir][j]];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue; // ����üũ
			if (map[ny][nx].shark != 0) continue; // ������ ���� ����� ������ �ִ���

			now_state = 1;
			shark[i].y = ny; // y�� ����
			shark[i].x = nx; // x�� ����
			shark[i].dir = priority_dir[i][dir][j]; // ���ο� ���� ����
			break; // Ž���� �ƴ�, �̵���!!!!!
		}

		if (now_state == 0) // ������ ���� ��� ������ �־� �ڽ��� ������ ���� ���
		{
			for (int j = 1; j <= 4; j++)
			{
				int ny = y + dy[priority_dir[i][dir][j]];
				int nx = x + dx[priority_dir[i][dir][j]];

				if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue; // ����üũ
				if (map[ny][nx].shark == i)
				{
					shark[i].y = ny; // y�� ����
					shark[i].x = nx; // x�� ����
					shark[i].dir = priority_dir[i][dir][j]; // ���ο� ���� ����
					break;
				}
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j].left_time == 0) // ������ �������� ���� �ʱ�ȭ
			{
				map[i][j].shark = 0;
			}
		}
	}

	for (int i = 1; i <= M; i++) // ���� ��ġ�� �� ���������� ���
	{
		if (life[i]) continue; // ���� ������ �� ���� ���Բ�

		int y = shark[i].y;
		int x = shark[i].x;

		if (map[y][x].left_time == K)
		{
			life[i] = true;
			continue;
		}

		map[y][x].shark = i; // �ش� ��ġ���� ��� ��ȣ ����
		map[y][x].left_time = K; // ���� �ð� ����
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
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int number;
			cin >> number;

			if (number != 0)
			{
				shark[number] = { i,j,0 };
				map[i][j] = { number, K };
			}
		}
	}

	for (int i = 1; i <= M; i++)
	{
		cin >> shark[i].dir;
	}

	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			for (int k = 1; k <= 4; k++)
			{
				cin >> priority_dir[i][j][k];
			}
		}
	}

	while (CheckLife()) // 1�� ��ġ�� �� ���� �� ����
	{
		time++;

		if (time > 1000)
		{
			time = -1;
			break;
		}

		MoveShark();
	}

	cout << time << endl;

	return 0;
}