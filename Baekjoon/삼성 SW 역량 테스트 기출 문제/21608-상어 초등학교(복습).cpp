// Date	 : 2021-10-13
// BOJ	 : 21608-상어 초등학교(복습)
// Genre : 구현, 삼성 SW
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#define endl "\n"
#define N_MAX 21
#define S_MAX 401

using namespace std;

typedef struct STUDENT {
	int r = 0;
	int c = 0;
	int like = 0;
	int blank = 0;
}STUDENT;


struct cmp {
	bool operator()(STUDENT &A, STUDENT &B) {
		if (A.like == B.like)
		{
			if (A.blank == B.blank)
			{
				if (A.r == B.r)
				{
					return A.c > B.c;
				}
				return A.r > B.r;
			}
			return A.blank < B.blank;
		}
		return A.like < B.like;
	}
};

int N;
int map[N_MAX][N_MAX];
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
vector<int> studentLike[S_MAX];
long long totalScore;
int scoreList[5] = { 0,1,10,100,1000 };

void seat_student(int idx)
{
	// 방향 : 상,하,좌,우 우선순위 : 1. 좋아하는 학생수 2. 빈칸 수 3. 행이 작은 순 4. 열이 작은 순
	priority_queue<STUDENT, vector<STUDENT>, cmp> pq;

	for (int r = 1; r <= N; r++)
	{
		for (int c = 1; c <= N; c++)
		{
			if (map[r][c] != 0) continue;

			STUDENT temp;
			temp.r = r;
			temp.c = c;
			temp.like = 0, temp.blank = 0;

			for (int dir = 0; dir < 4; dir++)
			{
				int nr = r + dr[dir];
				int nc = c + dc[dir];

				if (nr <= 0 || nr > N || nc <= 0 || nc > N) continue;

				if (map[nr][nc] == 0) temp.blank++;
				else if (map[nr][nc] != 0)
				{
					for (int i = 0; i < 4; i++)
					{
						if (map[nr][nc] == studentLike[idx][i])
						{
							temp.like++;
						}
					}
				}
			}
			pq.push(temp);
		}
	}
	int best_r = pq.top().r;
	int best_c = pq.top().c;
	map[best_r][best_c] = idx;
}

void sum_score(void)
{
	for (int r = 1; r <= N; r++)
	{
		for (int c = 1; c <= N; c++)
		{
			int idx = map[r][c];
			int likeCnt = 0;
			for (int dir = 0; dir < 4; dir++)
			{
				int nr = r + dr[dir];
				int nc = c + dc[dir];
				if (nr <= 0 || nr > N || nc <= 0 || nc > N) continue;

				for (int i = 0; i < 4; i++)
				{
					if (map[nr][nc] == studentLike[idx][i])
					{
						likeCnt++;
						break;
					}
				}
			}
			totalScore += scoreList[likeCnt];
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

	cin >> N;
	int studentSize = N * N;

	for (int i = 0; i < studentSize; i++)
	{
		int number;
		cin >> number;

		for (int j = 0; j < 4; j++)
		{
			int temp;
			cin >> temp;
			studentLike[number].push_back(temp);
		}
		seat_student(number);
	}
	sum_score();
	cout << totalScore << endl;

	return 0;
}