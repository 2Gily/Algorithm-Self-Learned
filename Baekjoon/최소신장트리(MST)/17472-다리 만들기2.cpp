#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <set>
#include <queue>
#include <tuple>
#define endl "\n"
using namespace std;

typedef pair<int, int> PAIR;
typedef tuple<int, int, int> TUPLE;

const int MAX = 11;
const int ISLAND_MAX = 7;

int n, m;
int parent[ISLAND_MAX];
int map[MAX][MAX];
int visited[MAX][MAX];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
vector<TUPLE> edge; // ���� ������ �Ÿ� ���� vector
set<TUPLE> s; // ���� ���̿� �ߺ��Ǵ� ��θ� �����ϱ����� set

// ������ �����ϱ� ���� bfs �˰��� ���
void bfs(int x, int y, int numbering)
{
	queue<PAIR> q;
	q.push({ x, y });
	visited[y][x] = numbering;

	while (!q.empty())
	{
		PAIR now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];

			if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue; // ������ ����� ���
			if (!visited[ny][nx] && map[ny][nx] == map[now.second][now.first]) // �湮�� �� ���� ������ ���
			{
				q.push({ nx, ny });
				visited[ny][nx] = numbering;
			}
		}
	}
}

void calculate_distance(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int dist = 0;
		int nx = x;
		int ny = y;
		int numbering = visited[y][x];

		while (true)
		{
			nx += dx[i];
			ny += dy[i];
			int next_number = visited[ny][nx];

			if (nx < 0 || nx >= m || ny < 0 || ny >= n || next_number == numbering) break;
			if (next_number != 0 && next_number != numbering)
			{
				if (numbering > next_number) swap(numbering, next_number); // ���� ���� ��ȣ���� ū ��ȣ ������ ����
				if (dist > 1) s.insert({ dist, numbering, next_number}); // �ٸ� ���̴� 2�̻�
				break;
			}
			else dist++;
		}
	}
}

int Find(int x)
{
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int MST()
{
	sort(edge.begin(), edge.end());

	int sum = 0;

	for (int i = 0; i < edge.size(); i++)
	{
		int land1 = get<1>(edge[i]); // A��
		int land2 = get<2>(edge[i]); // B��
		int dist = get<0>(edge[i]); // A-B ������ �Ÿ�
		if (Find(land1) == Find(land2)) continue;
		Union(land1, land2);
		sum += dist;
	}
	return sum;
}

bool Check(int numbering)
{
	int p = Find(1);
	for (int i = 2; i <= numbering; i++)
		if (p != Find(i)) return false;
	return true;
}

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main()
{
	init();
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];

	// �� �󺧸�
	int numbering = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!visited[i][j] && map[i][j] != 0)
			{
				numbering++;
				bfs(j, i, numbering);
			}
		}
	}

	// ���Ͽ� ���ε� �ʱ� �θ� ����
	for (int i = 1; i <= numbering; i++) parent[i] = i;

	// ���� ������ �Ÿ� ����
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (visited[i][j] != 0) // �󺧸� �� ������ �����Ѵ�
				calculate_distance(j, i);

	for (auto i : s) edge.push_back(i); // �ߺ� ������ ���� ������ �Ÿ��� edge�� ����

	int answer = MST();

	if (Check(numbering)) // ��� ���� ����Ǿ������� �Ǽ� ��� ���
	{
		cout << answer << endl;
	}
	else cout << "-1" << endl; // ��� ���� ������ �� ������ -1 ���

	return 0;
}