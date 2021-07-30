// Date	 : 2021-07-31
// Title : 웜홀
// BOJ	 : 1865
// Genre : 벨만-포드, 그래프
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"
#define INF 1e9

using namespace std;

typedef struct INFO {
	int start, end, cost;
}INFO;

int N, M, W;
vector<int> dist;
vector<INFO> graph;

bool time_check(void)
{
	dist[1] = 0;
	int start, end, cost;

	// 1 ~ N-1 까지 경로 갱신
	for (int i = 1; i <= N - 1; i++)
	{
		for (int j = 0; j < graph.size(); j++)
		{
			start = graph[j].start;
			end = graph[j].end;
			cost = graph[j].cost;

			if (dist[end] > dist[start] + cost)
			{
				dist[end] = dist[start] + cost;
			}
		}
	}
	// N-1 ~ N까지 음수 사이클 확인
	for (int i = 0; i < graph.size(); i++) 
	{
		start = graph[i].start;
		end = graph[i].end;
		cost = graph[i].cost;

		if (dist[end] > dist[start] + cost) 
		{
			return true;
		}
	}

	return false;
}

void initSetting(void)
{
	graph.clear();
	graph.resize(N + 1);
	dist.clear();
	dist.resize(N + 1,INF);
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
	int testcase;
	cin >> testcase;
	while (testcase--)
	{
		/*
		첫 번째 줄에는
		지점의 수 N(1 ≤ N ≤ 500)
		도로의 개수 M(1 ≤ M ≤ 2500)
		웜홀의 개수 W(1 ≤ W ≤ 200)
		*/
		cin >> N >> M >> W;
		initSetting();

		for (int i = 0; i < M; i++)
		{
			/*
			S와 E는 연결된 지점의 번호, T는 이 도로를 통해 이동하는데 걸리는 시간을 의미
			(단 도로는 방향이 없으며 웜홀은 방향이 있다.)
			*/
			int S, E, T;
			cin >> S >> E >> T;
			graph.push_back({ S,E,T });
			graph.push_back({ E,S,T });
		}

		for (int i = 0; i < W; i++)
		{
			/*
			웜홀의 정보가 S, E, T -> S는 시작 지점, E는 도착 지점, T는 줄어드는 시간을 의미
			*/
			int S, E, T;
			cin >> S >> E >> T;
			graph.push_back({ S,E,-T });
		}

		if (time_check()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}