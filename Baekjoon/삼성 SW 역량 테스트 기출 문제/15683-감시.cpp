#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#define endl "\n"
#define INF 987654321
#define MAX 9
using namespace std;

typedef pair<int, int> PAIR;

int n, m, answer, count;
int map[MAX][MAX];
int temp[MAX][MAX];
int cctv_dir[MAX];

// left right down up
int dx[5] = { 0,0,0,1,-1 };
int dy[5] = { 0,1,-1,0,0 };

vector<PAIR> cctv;

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}


void copy() 
{
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			temp[i][j] = map[i][j];
}

void detect(int x, int y, int d) // �ش� ��ǥ���� ���ϴ� ������� ���ù����� ���ϴ� �Լ�
{
	int nx = x;
	int ny = y;

	while (true) 
	{
		nx += dx[d];
		ny += dy[d];

		if (nx < 0 || ny < 0 || nx >= n || ny >= m) break;

		if (temp[nx][ny] == 0) // ��ĭ ���� Ȯ��
		{
			temp[nx][ny] = 7;
		}
		else if (temp[nx][ny] == 6) // ��
		{
			break;
		}
	}
}

void set_cctv() // ��� cctv�� ������ ������ ����, 1~5�� ���� detect �Լ��� �ٸ��� �����
{
	for (int i = 0; i < cctv.size(); i++) 
	{
		int x = cctv[i].first;
		int y = cctv[i].second;

		switch (temp[x][y]) 
		{
		case 1:
		{
			// left right down up �� �ϳ�
			int dir = cctv_dir[i];
			detect(x, y, dir);
			break;
		}

		case 2:
		{
			if (cctv_dir[i] == 1) 
			{
				detect(x, y, 1);
				detect(x, y, 2);
			}
			else 
			{
				detect(x, y, 3);
				detect(x, y, 4);
			}

			break;
		}
		case 3:
		{
			if (cctv_dir[i] == 1) 
			{
				detect(x, y, 1);
				detect(x, y, 4);
			}
			else if (cctv_dir[i] == 2) 
			{
				detect(x, y, 1);
				detect(x, y, 3);
			}
			else if (cctv_dir[i] == 3) 
			{
				detect(x, y, 2);
				detect(x, y, 3);
			}
			else if (cctv_dir[i] == 4) 
			{
				detect(x, y, 2);
				detect(x, y, 4);
			}
			break;
		}
		case 4:
		{
			if (cctv_dir[i] == 1) 
			{
				detect(x, y, 1);
				detect(x, y, 2);
				detect(x, y, 4);
			}
			else if (cctv_dir[i] == 2) 
			{
				detect(x, y, 1);
				detect(x, y, 3);
				detect(x, y, 4);
			}
			else if (cctv_dir[i] == 3) 
			{
				detect(x, y, 1);
				detect(x, y, 2);
				detect(x, y, 3);
			}
			else if (cctv_dir[i] == 4) 
			{
				detect(x, y, 2);
				detect(x, y, 3);
				detect(x, y, 4);
			}
			break;
		}
		case 5:
		{
			detect(x, y, 1);
			detect(x, y, 2);
			detect(x, y, 3);
			detect(x, y, 4);
			break;
		}

		default:
			break;
		}
	}
}


int check() // �簢���븦 ���ϴ� �Լ�
{
	int space = 0;
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++) 
		{
			if (temp[i][j] == 0) space++;
		}
	}
	return space;
}

void dfs(int idx, int cnt) 
{
	if (cnt == cctv.size()) // ��� cctv�� ������ �����ߴٸ�
	{
		copy(); // �ӽ� �迭 ����
		set_cctv();
		answer = min(answer, check());
		return;
	}

	int x = cctv[idx].first;
	int y = cctv[idx].second;

	
	for (int k = 1; k <= 4; k++) // cctv ���� ����
	{
		// 2���� 5���� ���� 2��, 1���� ���⸸ �����ϹǷ� ���� ó��
		if (map[x][y] == 5 && k > 1) continue;
		if (map[x][y] == 2 && k > 2) continue;

		cctv_dir[idx] = k;
		dfs(idx + 1, cnt + 1);
		cctv_dir[idx] = 0;
	}
}

int main() 
{
	init();
	cin >> n >> m;
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++) 
		{
			cin >> map[i][j];
			if (map[i][j] >= 1 && map[i][j] <= 5)
			{
				cctv.push_back(PAIR(i, j));
			}
		}
	}

	answer = INF;
	dfs(0, 0);
	cout << answer << endl;

	return 0;
}