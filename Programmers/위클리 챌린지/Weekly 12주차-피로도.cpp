#include <string>
#include <vector>
#include <algorithm>
#define max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

bool visited[8];
int answer = 0;
void dfs(int k, int cnt, int idx, vector<vector<int>> &d)
{
	if (cnt > d.size()) return;
	answer = max(answer, cnt);

	for (int i = 0; i < d.size(); i++)
	{
		if (visited[i]) continue;
		if (k < d[i][0]) continue;

		visited[i] = true;
		dfs(k - d[i][1], cnt + 1, i, d);
		visited[i] = false;
	}
}

int solution(int k, vector<vector<int>> dungeons) {
	dfs(k, 0, 0, dungeons);
	return answer;
}