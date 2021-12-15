// Date	 : 2021-12-04
// BOJ	 : 1913-달팽이
// Genre : 구현
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"

using namespace std;

int N, target;

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main(void)
{
	init();
	cin >> N;
	cin >> target;
	vector<vector<int>> v(N, vector<int>(N,0));

	pair<int, int> answer;
	int dy[4] = { -1,0,1,0 };
	int dx[4] = { 0,1,0,-1 };
	int number = 1;
	int range = 1;
	int cy = N / 2;
	int cx = N / 2;
	int dir = 0;

	v[cy][cx] = number++;

	while (true)
	{
		for (int t = 0; t < 2; t++)
		{
			for (int r = 0; r < range; r++)
			{
				cy += dy[dir];
				cx += dx[dir];
				v[cy][cx] = number++;
				if (cy == 0 && cx == 0) break;
			}
			if (cy == 0 && cx == 0) break;
			dir = (dir + 1) % 4;
		}
		if (cy == 0 && cx == 0) break;
		range++;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << v[i][j] << " ";
			if (v[i][j] == target) answer = make_pair(i, j);
		}
		cout << endl;
	}

	cout << answer.first + 1 << " " << answer.second + 1 << endl;

	return 0;
}