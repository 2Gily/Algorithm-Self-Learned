#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#include <deque>
#define endl "\n"

using namespace std;

int N, K; // �����̾��� ���� N(��Ʈ�� 2N), ������ 0 �ѵ�
deque<pair<bool, int>> conveyor;

void rotate(void)
{
	conveyor.push_front(conveyor.back());
	conveyor.pop_back();
}

void put_bot(void)
{
	if (!conveyor.front().first && conveyor.front().second > 0)
	{
		conveyor.front().first = true;
		conveyor.front().second--;
	}
}

void move_bot(void)
{
	for (int i = N - 2; i >= 0; i--)
	{
		if (conveyor[N - 1].first)
		{
			conveyor[N - 1].first = false;
		}
		// �� ĭ�� �κ��� ���� �������� 0 �̻��̰�, ���� ĭ�� �κ��� ������
		if (!conveyor[i + 1].first && conveyor[i + 1].second > 0 && conveyor[i].first)
		{
			conveyor[i + 1].first = true;
			conveyor[i + 1].second--;
			conveyor[i].first = false;
		}
	}
}

bool checking(void)
{
	int check_zero = 0;

	for (int i = 0; i < conveyor.size(); i++)
	{
		if (conveyor[i].second < 1)
		{
			check_zero++;
		}

		if (check_zero >= K)
		{
			return false;
		}
	}

	return true;
}

void show_print(void)
{
	for (int i = 0; i < conveyor.size(); i++)
	{
		cout << "[" << boolalpha << conveyor[i].first << " " << conveyor[i].second << "] ";
	}
	cout << endl;
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
	int flag = true;
	int time = 0;
	cin >> N >> K;

	for (int i = 0; i < 2 * N; i++)
	{
		int temp;
		cin >> temp;
		conveyor.push_back({ false,temp });
	}

	while (flag)
	{
		time++;
		//cout << "ó�� "; show_print();
		rotate(); // 1. ��Ʈ�� �� ĭ ȸ���Ѵ�
		//cout << "ȸ�� "; show_print();
		move_bot(); // 2.���� ���� ��Ʈ�� �ö� �κ�����, ��Ʈ�� ȸ���ϴ� �������� �� ĭ �̵��� �� �ִٸ� �̵��Ѵ�. ���� �̵��� �� ���ٸ� ������ �ִ´�.
		//cout << "���� "; show_print();
		put_bot(); // 3. �ö󰡴� ��ġ�� �κ��� ���ٸ� �κ��� �ϳ� �ø���.
		//cout << "���� "; show_print();
		flag = checking(); // 4. �������� 0�� ĭ�� ������ K�� �̻��̶�� ������ �����Ѵ�. �׷��� �ʴٸ� 1������ ���ư���.
	}

	cout << time << endl;

	return 0;
}