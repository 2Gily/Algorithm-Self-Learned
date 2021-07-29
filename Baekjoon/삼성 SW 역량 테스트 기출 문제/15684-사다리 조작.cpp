#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#define N_MAX 12
#define H_MAX 32
#define endl "\n"

using namespace std;

int N, M, H;
int map[H_MAX][N_MAX]; // ���μ� ��ġ(��), ���μ� ��ġ(��)

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

bool check() 
{
	for (int i = 1; i <= N; i++) 
	{
		int y = 0;
		int x = i;

		while (true) // ��ٸ� Ÿ��
		{
			
			if (y == H + 1) // �ٴ� ����
			{
				if (x == i) break; // ����[i] == ���[i] ������
				else return false;
			}

			if (map[y + 1][x] == 1) // ������(->) �̵�
			{
				x++;
			}
			else if (map[y + 1][x] == 2) // ����(<-) �̵�
			{
				x--;
			}
			
			y++; //��ĭ ��������.
		}
	}

	return true;
}

int select(int y, int index) 
{
	if (index > 3) return -1;

	int answer = -1;

	for (int i = y; i <= H; i++)
	{
		for (int j = 1; j < N; j++) 
		{
			if (map[i][j] != 0) continue; // �̹� ����Ǿ� ������
			if (map[i][j + 1] != 0) continue;

			map[i][j] = 1; // i, i+1 ����
			map[i][j + 1] = 2;

			if (check()) 
			{
				answer = index; // ����[i] == ��[i] index(����� ���μ� ��)�� answer�� ����
			}

			int temp = select(i, index + 1); // ���� Ž�� y+1 ������ �̵�

			if (answer == -1) answer = temp; //answer�� �ʱⰪ�̶�� ���� Ž������ �޾ƿ� temp�� ����

			
			map[i][j] = 0; // ��� ���Ҵ� ���μ� ����
			map[i][j + 1] = 0; // ��� ���Ҵ� ���μ� ����
		}
	}

	return answer;
}


int main() 
{
	init();
	cin >> N >> M >> H;

	int a, b;
	
	for (int i = 0; i < M; i++) 
	{
		cin >> a >> b;
		map[a][b] = 1; // 1 : ������(->)���� �̵�
		map[a][b + 1] = 2; // 2 : ����(<-)���� �̵�
	}

	if (check()) cout << 0 << endl;
	else cout << select(1, 1) << endl;

	return 0;
}