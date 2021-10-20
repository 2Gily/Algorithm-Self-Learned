#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define endl "\n"
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define NMAX 9

using namespace std;

typedef struct COORD {
	int y;
	int x;
};

int N, K;
int high;
int answer;
int map[NMAX][NMAX];
bool visited[NMAX][NMAX];
vector<COORD> highList;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void dfs(COORD now,int dist, bool check)
{
	answer = max(answer, dist);

	int y = now.y;
	int x = now.x;

	for (int dir = 0; dir < 4; dir++)
	{
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		if (ny <= 0 || ny > N || nx <= 0 || nx > N || visited[ny][nx]) continue;

		if (map[ny][nx] >= map[y][x])
		{
			if (check)
			{
				for (int i = 1; i <= K; i++)
				{
					int temp = map[ny][nx] - i;

					if (temp < map[y][x])
					{
						map[ny][nx] -= i;
						visited[ny][nx] = true;
						check = false;
						dfs({ ny,nx }, dist + 1, check);
						map[ny][nx] += i;
						visited[ny][nx] = false;
						check = true;
					}
				}
			}
		}
		else
		{
			visited[ny][nx] = true;
			dfs({ ny,nx }, dist + 1, check);
			visited[ny][nx] = false;
		}
	}

	
}

void find_high(void)
{
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			if(map[i][j] == high) highList.push_back({i,j});
}

void init_data(void)
{
	answer = 0;
	high = 0;
	highList.clear();
	memset(map, 0, sizeof(map));
	memset(visited, false, sizeof(visited));
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int test_case;
	int T;

	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		init_data();
		cin >> N >> K;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				cin >> map[i][j];
				high = max(high, map[i][j]);
			}
		}
		find_high();
		for (int i = 0; i < highList.size(); i++)
		{
			visited[highList[i].y][highList[i].x] = true;
			dfs(highList[i], 1, true);
			visited[highList[i].y][highList[i].x] = false;
		}

		cout << "#" << test_case << " " << answer << endl;
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}