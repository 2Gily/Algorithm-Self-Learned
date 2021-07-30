// Update : 2021.07.31
// Title : 파티
// Genre : 다익스트라
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#define endl "\n"
#define INF 1e9
#define MAX 1001
using namespace std;

typedef struct pair<int, int> pii;
struct compare {
	bool operator()(pii a, pii b)
	{
		return a.second > b.second;
	}
};

int N, M, X;
int dist[MAX];
vector<vector<pii>> adj;

vector<int> dijkstra(int start)
{
	for (int i = 1; i <= N; i++) dist[i] = INF;
	dist[start] = 0;

	priority_queue<pii, vector<pii>, compare> pq;
	pq.push({ start,0 });

	while (!pq.empty())
	{
		int now = pq.top().first;
		int cost = pq.top().second;
		pq.pop();

		if (dist[now] < cost) continue;

		for (int i = 0; i < adj[now].size(); i++)
		{
			int next = adj[now][i].first;
			int ncost = adj[now][i].second;

			if (ncost + cost < dist[next])
			{
				dist[next] = ncost + cost;
				pq.push({next,ncost + cost });
			}
		}
	}

	vector<int> v(N + 1);
	for (int i = 1; i <= N; i++) v[i] = dist[i];
	return v;
}

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main(void)
{
	/*
	[다익스트라]
	priority_queue 사용
	시작점 고정 -> 최소 경로 탐색에 사용
	음수 간선 X(음수 가중치 X)
	일차원 배열 distance 사용 노드의 개수만큼 사용
	처음에 INF로 초기화
	dist = min(dist,new) 함.
	*/
	/*
	[문제 조건]
	이 마을 사이에는 총 M개의 단방향 도로들이 있고 i번째 길을 지나는데 Ti(1 ≤ Ti ≤ 100)의 시간을 소비한다.
	시작 마을 X번 마을
	첫 번째 줄에 N명의 학생들 중 오고 가는데 가장 오래 걸리는 학생의 소요시간을 출력한다.
	*/
	init();
	cin >> N >> M >> X;
	// 초기화
	adj.resize(N+1);

	for (int i = 0; i < M; i++)
	{
		int from, to, time;
		cin >> from >> to >> time;
		// 단방향
		adj[from].push_back({to,time});
	}
	// i -> X 마을의 최단거리
	int answer = 0;
	vector<int> temp2 = dijkstra(X);

	for (int i = 1; i <= N; i++)
	{
		vector<int> temp1 = dijkstra(i);

		answer = max(answer, temp1[X] + temp2[i]);
	}

	cout << answer << endl;

	return 0;
}