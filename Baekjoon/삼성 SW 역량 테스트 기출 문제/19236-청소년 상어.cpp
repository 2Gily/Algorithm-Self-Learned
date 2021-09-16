// Date	 : 2021-09-14
// BOJ	 : 19236
// Title : û�ҳ� ���
// Genre : ������(�Ｚ �԰� �׽�Ʈ)
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#define endl "\n"
#define MAX 5
#define MAX_FISH 17
#define EMPTY -1

using namespace std;

typedef struct FISH {
	int y = 0;
	int x = 0;
	int dir = 0;
	bool life = true;
}FISH;

int answer = 0;
FISH fish[MAX_FISH];
int map[MAX][MAX];
int dy[] = { -1, -1, 0, 1, 1, 1, 0,-1};
int dx[] = {  0, -1,-1,-1, 0, 1, 1, 1};

void DFS(int map[MAX][MAX], FISH fish[MAX_FISH], int shark_y, int shark_x, int sum)
{
	int copy_map[MAX][MAX];
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			copy_map[i][j] = map[i][j];

	FISH copy_fish[MAX_FISH];
	for (int i = 0; i < MAX_FISH; i++) 
		copy_fish[i] = fish[i];

	int fishNum = copy_map[shark_y][shark_x];
	int shark_dir = copy_fish[fishNum].dir;
	copy_fish[fishNum].life = false;
	copy_map[shark_y][shark_x] = EMPTY;

	sum += fishNum;
	if (answer < sum) answer = sum;

	// ����� �̵�
	for (int i = 1; i <= 16; i++)
	{
		if (copy_fish[i].life == false) continue;

		//���� ����� ��ġ�� ����
		int y = copy_fish[i].y;
		int x = copy_fish[i].x;
		int dir = copy_fish[i].dir;

		//�̵� ���, ��ġ
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		int ndir = dir;

		// ������ �Ѿ�ų�, �̵��ؾ��� ��ġ�� �� �ִ� ��� -> ���� ��ȯ
		while (ny <= 0 || ny > 4 || nx <= 0 || nx > 4 || (ny == shark_y && nx == shark_x))
		{
			ndir = (ndir + 1) % 8;
			ny = y + dy[ndir];
			nx = x + dx[ndir];
		}
		// �̵��ؾ��� ��ġ�� ����Ⱑ �ִ� ���
		if (copy_map[ny][nx] != EMPTY)
		{
			int targetFish = copy_map[ny][nx];

			copy_fish[targetFish].y = y;
			copy_fish[targetFish].x = x;

			copy_fish[i].y = ny;
			copy_fish[i].x = nx;
			copy_fish[i].dir = ndir;

			copy_map[ny][nx] = i;
			copy_map[y][x] = targetFish;
		}
		// �̵��ؾ��� ��ġ�� �ƹ��͵� ���� ���
		else
		{
			copy_fish[i].y = ny;
			copy_fish[i].x = nx;
			copy_fish[i].dir = ndir;

			copy_map[y][x] = EMPTY; // ���� ĭ ����� ���� ǥ��
			copy_map[ny][nx] = i; // �̵��� ĭ�� ���� ����� �̵�ǥ��
		}
	}
	// ��� �̵�
	for (int i = 1; i <= 3; i++)
	{
		int ny = shark_y + dy[shark_dir] * i;
		int nx = shark_x + dx[shark_dir] * i;

		if (ny <= 0 || ny > 4 || nx <= 0 || nx > 4) break;

		if (copy_map[ny][nx] != EMPTY)
		{
			DFS(copy_map, copy_fish, ny, nx, sum);
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
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			int number, dir;
			cin >> number >> dir;
			fish[number].y = i, fish[number].x = j, fish[number].dir = dir - 1, fish[number].life = true;
			map[i][j] = number;
		}
	}

	DFS(map, fish, 1, 1, 0);
	cout << answer << endl;

	return 0;
}