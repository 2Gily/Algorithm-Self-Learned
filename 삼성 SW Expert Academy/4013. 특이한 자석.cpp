#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>
#define endl "\n"

using namespace std;

int K;
bool sideCheck; // true : 시계방향, false : 반시계방향
bool visited[4];
deque<int> magnet[4]; // N 극이 0 , S 극이 1 2번은 6번하고 맞닿아 있음.

void debugg(void)
{
	cout << "test" << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << i + 1 << "번 자석 : ";
		for (int j = 0; j < magnet[i].size(); j++)
		{
			cout << magnet[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void init_data(void)
{
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < 4; i++) magnet[i].clear();
}


int get_score(void)
{
	int answer = 0;
	for (int i = 0; i < 4; i++)
	{
		if (magnet[i][0]) answer += (int)pow(2, i);
	}

	return answer;
}

void rotation(int idx, bool side)
{
	if (side == true)
	{
		magnet[idx].push_front(magnet[idx].back());
		magnet[idx].pop_back();
		return;
	}
	else if (side == false)
	{
		magnet[idx].push_back(magnet[idx].front());
		magnet[idx].pop_front();
		return;
	}
}

void simul(int idx, bool side)
{
	int now = idx;
	int right = idx + 1;
	int left = idx - 1;
	
	int nextSide = side;
	int nowRight = magnet[idx][2];
	int nowLeft = magnet[idx][6];

	rotation(idx, side);

	while (left >= 0)
	{
		int nextRight = magnet[left][2];

		if (nowLeft != nextRight)
		{
			now = left;
			left--;
			nowLeft = magnet[now][6];
			nextSide = !nextSide;

			rotation(now, nextSide);
		}
		else break;
	}

	now = idx;
	nextSide = side;

	while (right <= 3)
	{
		int nextLeft = magnet[right][6];

		if (nowRight != nextLeft)
		{
			now = right;
			right++;
			nowRight = magnet[now][2];
			nextSide = !nextSide;

			rotation(now, nextSide);
		}
		else break;
	}
}

int main(void)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		init_data();
		cin >> K;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				int temp;
				cin >> temp;
				magnet[i].push_back(temp);
			}
		}

		for (int i = 0; i < K; i++)
		{
			memset(visited, false, sizeof(visited));
			int idx, side;
			bool sideBool;
			cin >> idx >> side;

			if (side == 1) sideBool = true;
			else sideBool = false;

			simul(idx - 1, sideBool);
		}
		cout << "#" << test_case << " " << get_score() << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}