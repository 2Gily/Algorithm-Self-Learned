#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#include <queue>
#define endl "\n"

using namespace std;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int N = 12;
string arr[12];
int visit[12][6];
bool break_check = false; // 4�� �̻� �𿴴��� Ȯ���ϴ� ����

queue <pair<int, int>> q;
vector <pair<int, int>> v;

int DownPuyo(int y, int x) 
{
	int tempY = -1;

	for (int i = y; i < N; i++)
	{
		if (arr[i][x] == '.')
		{
			tempY = i;
		}
	}
	return tempY;
}

void bfs(int y, int x) 
{

	q.push({ y, x }); 
	v.push_back({ y,x }); 

	while (!q.empty()) 
	{

		int now_y = q.front().first;
		int now_x = q.front().second;
		visit[now_y][now_x] = 1;
		q.pop();

		for (int i = 0; i < 4; i++) 
		{
			int ny = now_y + dy[i];
			int nx = now_x + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= 6 || visit[ny][nx]) continue;

			if (arr[now_y][now_x] == arr[ny][nx])
			{
				q.push({ ny, nx }); // �� �� �ִ� ĭ�� Ǫ��
				v.push_back({ ny,nx }); // �湮�� ��θ� Ǫ��
				visit[ny][nx] = 1;
			}
		}
	}
}

int main() 
{
	int crash = 0, tempY = -1;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	while (true) 
	{

		
		for (int i = 0; i < N; i++) 
		{
			for (int j = 0; j < 6; j++) 
			{
				if (arr[i][j] != '.' && visit[i][j] != 1) //���ÿ� ���� �� �ִ� ������ visit�� 1
				{
					bfs(i, j);
				}

				if (v.size() >= 4) // 4�� �̻� ������� ��� true�� ����
				{
					break_check = true;
				}

				if (v.size() < 4) // 4�� �̸����� ����� ��� visit ���
				{ 
					for (int i = 0; i < v.size(); i++) 
					{
						visit[v[i].first][v[i].second] = 0;
					}
				}
				 
				v.clear();
			}
		}

		
		if (break_check == true) crash += 1; // ���� 1���� �߰�
		else if (break_check == false) break; // �� �˻��ߴµ� ���� ���� ������ ��������

		for (int i = 0; i < N; i++) // visit�� 1�� ǥ�õ� ���� ��� . ���� ����
		{
			for (int j = 0; j < 6; j++) 
			{
				if (visit[i][j] == 1) 
				{
					arr[i][j] = '.';
				}
			}
		}
		
		for (int i = N - 2; i >= 0; i--) //�ؿ� . �� �ִٸ� . �� ���� ������ ��� ��ġ�� ������ ����.
		{
			for (int j = 0; j < 6; j++) 
			{
				tempY = -1;
				if (arr[i][j] != '.') 
				{
					tempY = DownPuyo(i, j);
				}
				if (tempY != -1) 
				{
					arr[tempY][j] = arr[i][j]; // ���� ������ . �� ���� ������ �ű��,
					arr[i][j] = '.'; // �� �ڸ��� . �� �����Ѵ�.
				}
			}
		}
		// ���� Ž���� ���� �ʱ�ȭ
		break_check = false;

		for (int i = 0; i < N; i++) 
		{
			for (int j = 0; j < 6; j++) 
			{
				visit[i][j] = 0;
			}
		}
	}

	cout << crash;

	return 0;
}