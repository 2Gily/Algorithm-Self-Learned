// Update : 2021.07.31
// Title : 1647-도시 분할 계획
// Genre : MST
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#define endl "\n"

using namespace std;

typedef struct INFO {
	int from;
	int to;
	int cost;
};

struct compare {
	bool operator()(INFO a, INFO b)
	{
		return a.cost > b.cost;
	}
};

int N, M;
vector<int> parent;

int Find(int x)
{
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int a, int b)
{
	int pa = Find(a);
	int pb = Find(b);

	parent[pb] = pa;
}

bool CycleCheck(int a, int b)
{
	int pa = Find(a);
	int pb = Find(b);

	if (pa == pb) return true; // 사이클이다.
	return false; // 사이클이 아니다.
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
	무방향, 가중치
	N : 노드 개수, M : 간선 개수
	MST의 간선 수 => N-1

	*/
	init();
	cin >> N >> M;
	parent.resize(N + 1);
	priority_queue<INFO, vector<INFO>, compare> pq;

	for (int i = 1; i <= N; i++) parent[i] = i;

	for (int i = 0; i < M; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		pq.push({ from,to,cost });
	}

	long long totalCost = 0;
	int max_cost = 0;
	int cnt = 0;

	while (!pq.empty())
	{
		if (cnt == N - 1) break;

		INFO node = pq.top();
		pq.pop();

		int from = node.from;
		int to = node.to;
		int cost = node.cost;

		if (Find(from) == Find(to)) continue;
		
		Union(from, to);
		max_cost = max(max_cost, cost);
		totalCost += cost;
		cnt++;
	}

	cout << totalCost - max_cost << endl;

	return 0;
}