#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

struct MARBLE
{
	int y, x, range;
};

bool stopFlag;
int answer;
int n, w, h;
int copyMap[16][13];
int map[16][13];
vector<int> marble;

const int dy[4] = { -1,1,0,0 };
const int dx[4] = { 0,0,-1,1 };

void map_sort(void)
{
	for (int x = 0; x < w; ++x)
	{
		int arr[16];
		memset(arr, 0, sizeof(arr));
		int r = h - 1;
		for (int y = h - 1; y >= 0; y--)
		{
			if (copyMap[y][x] != 0)
			{
				arr[r--] = copyMap[y][x];
				copyMap[y][x] = 0;
			}
		}

		for (int y = h - 1; y >= 0; y--)
		{
			copyMap[y][x] = arr[y];
		}
	}
}

void boom_marble(void)
{
	memset(copyMap, 0, sizeof(copyMap));

	for (int y = 0; y < h; ++y) 
	{
		for (int x = 0; x < w; ++x)
		{
			copyMap[y][x] = map[y][x];
		}
	}

	for (int i = 0; i < n; ++i)
	{
		int ny = 0; 
		int nx = marble[i];

		while (ny < h && copyMap[ny][nx] == 0) ny++;
			
		if (ny == h)
		{
			continue;
		}

		int visitied[15][12] = { 0, };

		if (copyMap[ny][nx] == 0) 
		{
			continue;
		}
		else 
		{
			//bfs
			queue<MARBLE> q;
			q.push({ ny,nx,copyMap[ny][nx] });

			while (!q.empty())
			{
				MARBLE cur = q.front(); q.pop();

				visitied[cur.y][cur.x] = 1;
				copyMap[cur.y][cur.x] = 0;

				for (int dist = 1; dist < cur.range; ++dist) 
				{
					for (int dir = 0; dir < 4; ++dir)
					{
						int ny = cur.y + dy[dir] * dist;
						int nx = cur.x + dx[dir] * dist;

						if (ny < 0 || ny >= h || nx < 0 || nx >= w)
							continue;

						if (visitied[ny][nx] == 1)
							continue;

						q.push({ ny,nx,copyMap[ny][nx] });
					}
				}
			}
		}
		map_sort();
	}
}

int get_cnt(void)
{
	int cnt = 0;
	for (int y = 0; y < h; ++y) 
	{
		for (int x = 0; x < w; ++x) 
		{
			if (copyMap[y][x] != 0) ++cnt;
		}
	}

	if (cnt == 0) stopFlag = true;	
	return cnt;
}

void dfs(int cnt)
{
	if (stopFlag) return;

	if (cnt == n)
	{
		boom_marble();
		int candi = get_cnt();
		if (candi < answer) answer = candi;
			
		return;
	}

	for (int i = 0; i < w; ++i)
	{
		marble.push_back(i);
		dfs(cnt + 1);
		marble.pop_back();
	}
}

void init_data(void)
{
	answer = 987654321;
	memset(map, 0, sizeof(map));
	marble.clear();
	stopFlag = false;
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		init_data();
		cin >> n >> w >> h;

		for (int y = 0; y < h; ++y)
		{
			for (int x = 0; x < w; ++x) 
			{
				cin >> map[y][x];
			}
		}

		dfs(0);
		cout << "#" << test_case << " " << answer << "\n";
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}