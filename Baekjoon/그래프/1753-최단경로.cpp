#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <queue>
#include <climits>
#define INF INT_MAX
#define V_MAX 20001
#define E_MAX 300001

using namespace std;

int v, e, start; // v : ������ ����, e : ������ ����, start : ���� ������ ��ȣ

vector<pair<int, int> > graph[V_MAX]; // �� ��忡 ����Ǿ� �ִ� ��忡 ���� ������ ��� �迭
int d[E_MAX]; // �ִ� �Ÿ� ���̺� �����

void dijkstra(int start)
{
	priority_queue<pair<int, int>>pq; // �Ÿ�, ��� �ε���

	pq.push({ 0,start }); //���� ���� �������� �ִ� ��δ� 0���� �����Ͽ�, ť�� ����.
	d[start] = 0;

	while (!pq.empty())
	{
		int dist = -pq.top().first; //���� �������� ���
		int now = pq.top().second; // ���� ���
		pq.pop();

		if (d[now] < dist) // �̹� �ִܰ�θ� üũ�� ����� ��� �н�
			continue;

		for (int i = 0; i < graph[now].size(); i++)
		{
			int cost = dist + graph[now][i].second; // ���ļ� ���� ����� ����� ���
												  // ��������� ��� + ���� ��� ���
			if (cost < d[graph[now][i].first]) // ����� �� �۴ٸ� �ִܰ�� ���̺� ���� ����.
			{
				d[graph[now][i].first] = cost;
				pq.push(make_pair(-cost, graph[now][i].first));
			}
		}
	}
}

int main(void)
{
	cin >> v >> e;
	cin >> start;

	// ��� ���� ������ �Է¹ޱ�
	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		// a�� ��忡�� b�� ���� ���� ����� c��� �ǹ�
		graph[a].push_back({ b, c });
	}

	// �ִ� �Ÿ� ���̺��� ��� �������� �ʱ�ȭ
	fill(d, d + E_MAX, INF);

	// ���ͽ�Ʈ�� �˰����� ����
	dijkstra(start);

	// ��� ���� ���� ���� �ִ� �Ÿ��� ���
	for (int i = 1; i <= v; i++)
	{
		// ������ �� ���� ���, ����(INF : INFINITY)�̶�� ���
		if (d[i] == INF) {
			cout << "INF" << '\n';
		}
		// ������ �� �ִ� ��� �Ÿ��� ���
		else {
			cout << d[i] << '\n';
		}
	}

	return 0;
}