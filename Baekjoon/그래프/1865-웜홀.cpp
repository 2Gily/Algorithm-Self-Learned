// Date	 : 2021-07-31
// Title : ��Ȧ
// BOJ	 : 1865
// Genre : ����-����, �׷���
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

	// 1 ~ N-1 ���� ��� ����
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
	// N-1 ~ N���� ���� ����Ŭ Ȯ��
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
		ù ��° �ٿ���
		������ �� N(1 �� N �� 500)
		������ ���� M(1 �� M �� 2500)
		��Ȧ�� ���� W(1 �� W �� 200)
		*/
		cin >> N >> M >> W;
		initSetting();

		for (int i = 0; i < M; i++)
		{
			/*
			S�� E�� ����� ������ ��ȣ, T�� �� ���θ� ���� �̵��ϴµ� �ɸ��� �ð��� �ǹ�
			(�� ���δ� ������ ������ ��Ȧ�� ������ �ִ�.)
			*/
			int S, E, T;
			cin >> S >> E >> T;
			graph.push_back({ S,E,T });
			graph.push_back({ E,S,T });
		}

		for (int i = 0; i < W; i++)
		{
			/*
			��Ȧ�� ������ S, E, T -> S�� ���� ����, E�� ���� ����, T�� �پ��� �ð��� �ǹ�
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