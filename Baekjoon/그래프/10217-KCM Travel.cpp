#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#include <tuple>
#include <queue>
#include <functional>
#define endl "\n"
#define N_MAX 103
#define M_MAX 10003
#define INF 987654321
using namespace std;

typedef tuple<int, int, int> TUPLE;

int dp[N_MAX][M_MAX]; // dp[i][j] : start ���ÿ��� i�� ���ñ��� ��� j�� �Ἥ �� �� �ּ� �ð�

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main(void)
{
	init();

	int T;
	cin >> T;

	while (T--)
	{
		int N, M, K;
		cin >> N >> M >> K;

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				dp[i][j] = INF;
			}
		}

		dp[1][0] = 0;

		vector<TUPLE> info[N_MAX]; // info[���۵���] = {���������� Index, ���, �ҿ�ð�}

		while (K--)
		{
			int u, v, c, d;
			cin >> u >> v >> c >> d;
			info[u].push_back({ v, c, d });
		}

		priority_queue<TUPLE, vector<TUPLE>, greater<TUPLE> > pq; // �ð� ������ ���

		pq.push({ 0, 1,0 });

		bool ExistsPath = false;

		while (!pq.empty())
		{
			auto cur = pq.top();
			pq.pop();

			int time = get<0>(cur);
			int city = get<1>(cur);
			int cost = get<2>(cur);

			if (city == N)
			{
				cout << time << endl; // �־��� cost ������ time�� ���� ������ �����ֱ� ������ N�� �����ϴ� ��� ����ϸ� ��
				ExistsPath = true;
				break;
			}

			if (dp[city][cost] < time) // �̹� city�� cost�� �Ἥ �� ���� ������ ��찡 ���� ���
				continue;

			for (auto near : info[city])
			{
				int city_near = get<0>(near);
				int cost_near = get<1>(near);
				int time_near = get<2>(near);

				if (cost + cost_near > M) // ������ �ʰ����� ���
					continue;

				if (dp[city_near][cost + cost_near] > time_near + time) // �� ���� ��θ� ã�� ���
				{
					dp[city_near][cost + cost_near] = time_near + time;
					pq.push({ time_near + time , city_near, cost + cost_near });
				}
			}
		}

		if (!ExistsPath)
		{
			cout << "Poor KCM" << endl;
		}
	}

	return 0;
}