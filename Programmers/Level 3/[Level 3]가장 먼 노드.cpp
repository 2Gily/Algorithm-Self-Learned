#include <string>
#include <vector>
#include <queue>
#define MAX 20001

using namespace std;

vector<int> graph[MAX];
int dist[MAX];
int maxDist = 0;
bool visited[MAX];

void bfs(int start)
{
	queue<pair<int,int>> q;
	queue<int> qq;
	visited[start] = true;
	q.push({ start, 0 });
	dist[start] = 0;

	while (!q.empty())
	{
		int now = q.front().first;
		int nowDist = q.front().second;
		if(dist[now] > nowDist) dist[now] = nowDist;
		q.pop();

		for (int i = 0; i < graph[now].size(); i++)
		{
			int next = graph[now][i];
			int nextDist = nowDist + 1;

			if (visited[next]) continue;
			visited[next] = true;
			q.push({ next,nextDist });
		}
	}
}

int solution(int n, vector<vector<int>> edge) 
{
	int answer = 0;

	for (int i = 0; i < edge.size(); i++)
	{
		int from, to;
		from = edge[i][0];
		to = edge[i][1];
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	for (int i = 0; i < MAX; i++)
	{
		dist[i] = 987654321;
	}

	return answer;
}