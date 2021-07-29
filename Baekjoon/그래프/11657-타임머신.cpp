#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#define endl "\n"
#define MAX 502
#define INF 98765421
using namespace std;

int N, M;
long long dist[MAX];
vector<pair<pair<int, int>, int>> graph; // ������� start, end, cost

int main()
{
	cin >> N >> M;

	for (int i = 1; i <= N; i++) dist[i] = INF;
	for (int i = 0; i < M; i++)
	{
		int start, end, cost;

		cin >> start >> end >> cost;
		graph.push_back(make_pair(make_pair(start, end), cost));
	}

	dist[1] = 0;

	for (int i = 1; i <= N - 1; i++)
	{
		for (int j = 0; j < graph.size(); j++)
		{
			int start = graph[j].first.first;
			int end = graph[j].first.second;
			int cost = graph[j].second;

			if (dist[start] == INF) continue;

			if (dist[end] > dist[start] + cost)
			{
				dist[end] = dist[start] + cost; // �ش� ��ΰ� ���� ������� ���� cost�� ����ϸ� ����
			}
		}
	}

	for (int i = 0; i < graph.size(); i++)
	{
		int start = graph[i].first.first;
		int end = graph[i].first.second;
		int cost = graph[i].second;

		if (dist[start] == INF) continue;
		if (dist[end] > dist[start] + cost)
		{
			cout << -1 << endl;
			return 0;
		}
	}

	for (int i = 2; i <= N; i++)
	{
		if (dist[i] == INF) cout << -1 << endl;
		else cout << dist[i] << endl;
	}

	return 0;
}