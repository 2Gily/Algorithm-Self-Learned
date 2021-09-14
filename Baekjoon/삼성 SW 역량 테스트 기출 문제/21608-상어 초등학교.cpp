// Date	 : 2021-09-14
// BOJ	 : 21608
// Title : 상어 초등학교
// Genre : 빡구현
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#define endl "\n"
#define MAX 21

using namespace std;

typedef struct INFO {
	int y = 0;
	int x = 0;
	int like_cnt = 0;
	int blank_cnt = 0;
}INFO;

struct compare {
	bool operator()(INFO &a, INFO &b)
	{
		if (a.like_cnt == b.like_cnt)
		{
			if (a.blank_cnt == b.blank_cnt)
			{
				if (a.y == b.y)
				{
					return a.x > b.x;
				}
				else return a.y > b.y;
			}
			else return a.blank_cnt < b.blank_cnt;
		}
		else return a.like_cnt < b.like_cnt;
	}
};

int N;
int map[MAX][MAX];
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};
int score[5] = { 0, 1, 10, 100, 1000 };
vector<int> student[401];

void seat_student(int number)
{
	priority_queue<INFO, vector<INFO>, compare> pq;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			INFO temp;
			temp.y = i;
			temp.x = j;

			if (map[i][j] != 0) continue;
			else
			{
				for (int dir = 0; dir < 4; dir++)
				{
					int ny = i + dy[dir];
					int nx = j + dx[dir];

					if (ny <= 0 || ny > N || nx <= 0 || nx > N) continue;
					if (map[ny][nx] == 0) temp.blank_cnt++;
					else
					{
						for (int k = 0; k < student[number].size(); k++)
						{
							if (map[ny][nx] == student[number][k]) temp.like_cnt++;
						}
					}

				}
				pq.push(temp);
			}
		}
	}

	int pos_y = pq.top().y;
	int pos_x = pq.top().x;
	map[pos_y][pos_x] = number;

	return;
}

int score_sum(void)
{
	int total_sum = 0;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int number = map[i][j];
			int like_cnt = 0;

			for (int dir = 0; dir < 4; dir++)
			{
				int ny = i + dy[dir];
				int nx = j + dx[dir];

				if (ny <= 0 || ny > N || nx <= 0 || nx > N) continue;

				for (int k = 0; k < student[number].size(); k++)
				{
					if (map[ny][nx] == student[number][k]) like_cnt++;
				}
			}

			total_sum += score[like_cnt];
		}
	}

	return total_sum;
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
	cin >> N;

	for (int i = 1; i <= N * N; i++)
	{
		int number;
		cin >> number;

		for (int j = 0; j < 4; j++)
		{
			int like;
			cin >> like;
			student[number].push_back(like);
		}
		seat_student(number);
	}

	// // 자리배치 디버깅
	//for (int i = 1; i <= N; i++)
	//{
	//	for (int j = 1; j <= N; j++)
	//	{
	//		cout << map[i][j] << " ";
	//	}
	//	cout << "\n";
	//}

	cout << score_sum() << endl;

	return 0;
}