#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#define endl "\n"
#define MAX 1001
#define INF 1e9
using namespace std;

typedef struct BUS {
	int target;
	int cost;
}BUS;

struct compare {
	bool operator()(BUS a, BUS b)
	{
		return a.cost > b.cost;
	}
};

int N, M;
int dist[MAX];
vector<BUS> bus[MAX];

void dijkstra(int start)
{
	priority_queue<BUS, vector<BUS>, compare> pq;

	pq.push({ start,0 });


	while (!pq.empty())
	{
		int ncity = pq.top().target;
		int ncost = pq.top().cost;
		pq.pop();

		if (dist[ncity] < ncost) continue;

		for (BUS next : bus[ncity])
		{
			int next_cost = next.cost + ncost;

			if (next_cost < dist[next.target])
			{
				dist[next.target] = next_cost;
				pq.push({ next.target,next_cost });
			}
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
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		bus[from].push_back({ to,cost });
	}

	int start, end;
	cin >> start >> end;

	for (int i = 0; i <= N; i++)
	{
		if (start == i) dist[i] = 0;
		else dist[i] = INF;
	}

	dijkstra(start);

	cout << dist[end] << endl;

	return 0;
}