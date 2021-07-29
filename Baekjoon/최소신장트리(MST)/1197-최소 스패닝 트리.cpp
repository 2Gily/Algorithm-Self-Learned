#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#include <queue>
#define endl "\n"

using namespace std;

typedef pair<int, int> PAIR;

vector<pair<int, int>> graph[10001];
int visit[10001];	//�湮�� Ȯ���ϴ� �迭

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main(void)
{
	init();
	int sum = 0 ;	//�ּ� ���д� Ʈ���� ����ġ
	int V, E;		// ������ ����, ������ ��
	int start = 1;	// ���������� ��ȣ
	cin >> V >> E; 

	while(E--)
	{
		int from, to, val;
		cin >> from >> to >> val;

		graph[from].push_back(make_pair(to, val));
		graph[to].push_back(make_pair(from, val));
	}

	priority_queue<PAIR, vector<PAIR>, greater<PAIR>> pq; //cost �� �켱���� ������ �ؾ��ϱ� ������ pair{cost, vertex} ������ �־��ش�.

	for (int i = 0; i < graph[start].size(); i++) 
	{
		int next = graph[start][i].first;
		int nextCost = graph[start][i].second;

		pq.push(make_pair(nextCost, next));
	}
	
	visit[start] = 1;

	while (!pq.empty()) 
	{
		int now = pq.top().second;
		int now_cost = pq.top().first;

		pq.pop();

		if (visit[now] == 1) 
		{
			continue;
		}

		visit[now] = 1;

		sum += now_cost;

		for (int i = 0; i < graph[now].size(); i++) 
		{
			int next = graph[now][i].first;
			int nextCost = graph[now][i].second;

			pq.push(make_pair(nextCost, next));
		}
	}
	cout << sum << endl;

	return 0;
}

/*
[����]
�׷����� �־����� ��, �� �׷����� �ּ� ���д� Ʈ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�ּ� ���д� Ʈ����, �־��� �׷����� ��� �������� �����ϴ� �κ� �׷��� �߿��� �� ����ġ�� ���� �ּ��� Ʈ���� ���Ѵ�.

[�Է�]
ù° �ٿ� ������ ���� V(1 �� V �� 10,000)�� ������ ���� E(1 �� E �� 100,000)�� �־�����. ���� E���� �ٿ��� �� ������ ���� ������ ��Ÿ���� �� ���� A, B, C�� �־�����. �̴� A�� ������ B�� ������ ����ġ C�� �������� ����Ǿ� �ִٴ� �ǹ��̴�. C�� ������ ���� ������, ������ 1,000,000�� ���� �ʴ´�.

�׷����� ������ 1������ V������ ��ȣ�� �Ű��� �ְ�, ������ �� ���� ���̿� ��ΰ� �ִ�. �ּ� ���д� Ʈ���� ����ġ�� -2,147,483,648���� ũ�ų� ����, 2,147,483,647���� �۰ų� ���� �����͸� �Է����� �־�����.

[���]
ù° �ٿ� �ּ� ���д� Ʈ���� ����ġ�� ����Ѵ�.
*/