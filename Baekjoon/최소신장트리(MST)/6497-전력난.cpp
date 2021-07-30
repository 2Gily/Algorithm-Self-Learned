// Update : 2021.07.31
// Title : 전력난
// Genre : MST
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#define endl "\n"

using namespace std;

typedef struct INFO {
	int x;
	int y;
	int dist;
};

struct compare {
	bool operator()(INFO a, INFO b)
	{
		return a.dist > b.dist;
	}
};

int m, n; // 집의 수, 길의 수
vector<int> parent;
priority_queue<INFO, vector<INFO>, compare> pq;

int Find(int a)
{
	if (parent[a] == a) return a;
	return parent[a] = Find(parent[a]);
}

void Union(int a, int b)
{
	int pa = Find(a);
	int pb = Find(b);

	if(pa > pb) parent[pb] = pa;
	else parent[pa] = pb;
}

int makeMST(void)
{
	int result = 0;
	int cnt = 0;

	while (!pq.empty())
	{
		if (cnt == m - 1) break;

		int x = pq.top().x;
		int y = pq.top().y;
		int dist = pq.top().dist;
		pq.pop();

		int px = Find(x);
		int py = Find(y);

		if (px != py) // 사이클이 아니면
		{
			Union(x, y);
			result += dist;
			cnt++;
		}
	}

	return result;
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
	while (true)
	{
		cin >> m >> n;
		if (m == 0 && n == 0) break;

		// 초기화
		int total = 0;
		parent.clear();
		parent.resize(m + 1);
		while (!pq.empty()) pq.pop();
		
		for (int i = 0; i < m; i++) parent[i] = i;

		for (int i = 0; i < n; i++)
		{
			INFO temp;
			cin >> temp.x >> temp.y >> temp.dist;
			pq.push(temp);
			total += temp.dist;
		}

		cout << total - makeMST() << endl;
	}

	return 0;
}