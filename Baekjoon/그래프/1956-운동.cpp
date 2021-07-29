#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#define endl "\n"
#define INF 987654321
#define V_MAX 401
#define E_MAX 200000

using namespace std;

int graph[V_MAX][V_MAX];

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main(void)
{
	init();

	int V, E;
	cin >> V >> E;

	for (int i = 1; i <= V; i++) 
	{
		for (int j = 1; j <= V; j++) 
		{
			graph[i][j] = INF; // graph[][] = { INF }�� �ʱ�ȭ
		}
	}
	for (int i = 0; i < E; i++) 
	{
		int a, b, c;
		cin >> a >> b >> c;

		graph[a][b] = c; // a -> b cost: c
	}

	int ans = INF;

	for (int k = 1; k <= V; k++) 
	{
		for (int i = 1; i <= V; i++) 
		{
			for (int j = 1; j <= V; j++) 
			{
				if (graph[i][k] + graph[k][j] < graph[i][j])  // (i -> k -> j) vs (i -> j)
				{
					graph[i][j] = graph[i][k] + graph[k][j]; // ����
				}
			}
		}
	}
	for (int i = 1; i <= V; i++) 
	{
		for (int j = 1; j <= V; j++) 
		{
			if (i == j) continue; // graph[a][b] = 0 (��,a == b)

			ans = min(ans, graph[i][j] + graph[j][i]); // ������ �亸�� ���� ���� ����Ŭ�̶��~ Update
		}
	}

	if (ans == INF)
	{
		cout << -1 << endl;
	}
	else cout << ans << endl;

	return 0;
}

/*
[����]
V���� ������ E���� ���η� �����Ǿ� �ִ� ���ð� �ִ�. ���δ� ������ ���� ���̿� ���� ������, �Ϲ� ���� �����̴�. �������� ���ǻ� 1������ V������ ��ȣ�� �Ű��� �ִٰ� ����.

����� ���θ� ���� ��� �ϱ� ���� ��θ� ã������ �Ѵ�. ��� �� �Ŀ��� �ٽ� ���������� ���ƿ��� ���� ���� ������, �츮�� ����Ŭ�� ã�⸦ ���Ѵ�. ��, ����� ��� �ſ� �������ϹǷ�, ����Ŭ�� �̷�� ������ ������ ���� �ּҰ� �ǵ��� ã������ �Ѵ�.

������ ������ �־����� ��, ������ ������ ���� ���� ���� ����Ŭ�� ã�� ���α׷��� �ۼ��Ͻÿ�. �� ������ �պ��ϴ� ��쵵 ����Ŭ�� ���Եʿ� �����Ѵ�.

[�Է�]
ù° �ٿ� V�� E�� ��ĭ�� ���̿� �ΰ� �־�����. (2 �� V �� 400, 0 �� E �� V(V-1)) ���� E���� �ٿ��� ���� �� ���� ���� a, b, c�� �־�����. a�� �������� b�� ������ ���� �Ÿ��� c�� ���ΰ� �ִٴ� �ǹ��̴�. (a �� b�ӿ� ����) �Ÿ��� 10,000 ������ �ڿ����̴�. (a, b) ���� ���� ���ΰ� ���� �� �־����� �ʴ´�.

[���]
ù° �ٿ� �ּ� ����Ŭ�� ���� ������ ���� ����Ѵ�. � ��θ� ã�� ���� �Ұ����� ��쿡�� -1�� ����Ѵ�.
*/