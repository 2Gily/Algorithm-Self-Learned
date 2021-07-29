#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <deque>
#include <queue>
#define endl "\n"
#define MAX 51

using namespace std;

int N, M, T;
int X, D, K;
deque<int> dq[MAX];

int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };

void rotate(void)
{
	for (int i = X; i <= N; i += X)
	{
		for (int j = 0; j < K; j++)
		{
			if (D == 0) // �ð� ����
			{
				int temp = dq[i].back();
				dq[i].pop_back();
				dq[i].push_front(temp);
			}
			else // �ݽð� ����
			{
				int temp = dq[i].front();
				dq[i].pop_front();
				dq[i].push_back(temp);
			}
		}
	}
}

bool delete_number(void)
{
	bool flag = false;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (dq[i][j] == 0) continue;

			queue<pair<int, int>> q;
			vector<pair<int, int>> v;
			bool visit[MAX][MAX] = { false, };
			int value = dq[i][j];

			q.push({ i,j });
			visit[i][j] = true;

			while (!q.empty())
			{
				int y = q.front().first;
				int x = q.front().second;
				q.pop();

				v.push_back({ y,x });

				for (int d = 0; d < 4; d++)
				{
					int ny = y + dy[d];
					int nx = x + dx[d];

					if (ny == 0 || ny > N) continue; // ���� ���� üũ

					if (nx == -1) // ������ �ε��� ���� 
					{
						nx = M - 1;
					}
					else if (nx == M) // ������ �ε��� ����
					{
						nx = 0;
					}

					if (visit[ny][nx]) continue; // �湮üũ

					if (dq[ny][nx] == value) // ���� ���� ������
					{
						visit[ny][nx] = true;

						q.push({ ny,nx });
					}
				}
			}

			if (v.size() >= 2) // ������ ���ڰ� ���� ��� ����, ���� ǥ�� 0
			{
				flag = true;

				for (int k = 0; k < v.size(); k++)
				{
					int y = v[k].first;
					int x = v[k].second;

					dq[y][x] = 0;
				}
			}
		}
	}

	return flag;
}

void chage_number(void)
{
	int sum = 0;
	int cnt = 0;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (dq[i][j] == 0) continue;

			sum += dq[i][j];
			cnt++;
		}
	}

	double average = (double)sum / cnt;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (dq[i][j] == 0) continue; // �̹� ���ŵ� ����

			if (dq[i][j] > average) dq[i][j]--; // ��պ��� ū ������ 1�� ����
			else if (dq[i][j] < average) dq[i][j]++; // ���� ������ 1�� ���Ѵ�.
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
	cin >> N >> M >> T;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int num;
			cin >> num;

			dq[i].push_back(num);
		}
	}

	for (int t = 0; t < T; t++)
	{
		cin >> X >> D >> K;

		rotate();

		bool flag = delete_number();

		if (flag) continue;

		chage_number();
	}

	int answer = 0;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			answer += dq[i][j];
		}
	}

	cout << answer << endl;

	return 0;
}