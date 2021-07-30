// Update : 2021.07.31
// Title : ��Ƽ
// Genre : ���ͽ�Ʈ��
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
	[���ͽ�Ʈ��]
	priority_queue ���
	������ ���� -> �ּ� ��� Ž���� ���
	���� ���� X(���� ����ġ X)
	������ �迭 distance ��� ����� ������ŭ ���
	ó���� INF�� �ʱ�ȭ
	dist = min(dist,new) ��.
	*/
	/*
	[���� ����]
	�� ���� ���̿��� �� M���� �ܹ��� ���ε��� �ְ� i��° ���� �����µ� Ti(1 �� Ti �� 100)�� �ð��� �Һ��Ѵ�.
	���� ���� X�� ����
	ù ��° �ٿ� N���� �л��� �� ���� ���µ� ���� ���� �ɸ��� �л��� �ҿ�ð��� ����Ѵ�.
	*/
	init();
	cin >> N >> M >> X;
	// �ʱ�ȭ
	adj.resize(N+1);

	for (int i = 0; i < M; i++)
	{
		int from, to, time;
		cin >> from >> to >> time;
		// �ܹ���
		adj[from].push_back({to,time});
	}
	// i -> X ������ �ִܰŸ�
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