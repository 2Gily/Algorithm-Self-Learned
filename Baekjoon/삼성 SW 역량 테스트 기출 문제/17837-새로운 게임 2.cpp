// Date	 : 2021-10-17
// BOJ	 : 17837-새로운 게임 2
// Genre : 구현
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#define endl "\n"
#define NMAX 13
#define KMAX 11
#define WHITE 0
#define RED 1
#define BLUE 2
using namespace std;

typedef struct HORSE {
	int y = 0;
	int x = 0;
	int dir = 0;
}HORSE;

int N, K;
HORSE horse[KMAX];
bool visited[KMAX];
int color[NMAX][NMAX];
vector<int> board[NMAX][NMAX]; //board[y][x][0] = 말의 개수, board[y][x][1~4] 말의 종류 4개 이상이 되면 게임이 끝남.
pair<int, int> mv[5] = { {0,0}, {0,1},{0,-1},{-1,0},{1,0} }; // →, ←, ↑, ↓

int reverse_dir(int dir)
{
	switch (dir)
	{
		case 1 :
			return 2;
		case 2:
			return 1;
		case 3:
			return 4;
		case 4 :
			return 3;
		default:
			return dir;
	}
}


int move(int idx)
{
	HORSE cur = horse[idx];
	HORSE next;
	next.y = cur.y + mv[cur.dir].first;
	next.x = cur.x + mv[cur.dir].second;
	next.dir = cur.dir;

	if (next.y <= 0 || next.y > N || next.x <= 0 || next.x > N || color[next.y][next.x] == BLUE)
	{
		next.dir = reverse_dir(next.dir);
		next.y = cur.y + mv[next.dir].first;
		next.x = cur.x + mv[next.dir].second;
		horse[idx].dir = next.dir;

		if (next.y <= 0 || next.y > N || next.x <= 0 || next.x > N || color[next.y][next.x] == BLUE)
		{
			return board[cur.y][cur.x].size();
		}
	}

	int start = -1;
	int size = board[cur.y][cur.x].size();

	for (int i = 0; i < size; i++)
	{
		if (board[cur.y][cur.x][i] == idx)
		{
			start = i;
			break;
		}
	}

	vector<int> temp;
	for (int i = start; i < size; i++)
	{
		int idx = board[cur.y][cur.x][i];
		horse[idx].y = next.y;
		horse[idx].x = next.x;
		
		temp.push_back(board[cur.y][cur.x][i]);

	}

	for (int i = 0; i < temp.size(); i++)
	{
		board[cur.y][cur.x].pop_back();
	}

	if (color[next.y][next.x] == RED)
	{

		reverse(temp.begin(), temp.end());
	}

	for (int i = 0; i < temp.size(); i++)
	{
		board[next.y][next.x].push_back(temp[i]);
	}

	return board[next.y][next.x].size();
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
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> color[i][j];
	for (int i = 1; i <= K; i++)
	{
		int y, x, dir;
		cin >> y >> x >> dir;
		horse[i] = { y,x,dir };
		board[y][x].push_back(i);
	}

	int loop = 0; 
	int result = -1;

	while (loop <= 1000 && result == -1)
	{
		loop++;

		for (int idx = 1; idx <= K; idx++)
		{
			int cnt = move(idx);

			if (cnt >= 4)
			{
				result = loop;
				break;
			}
		}
	}

	cout << result << endl;

	return 0;
}