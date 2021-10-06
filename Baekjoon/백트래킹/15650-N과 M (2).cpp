// Date	 : 2021-10-04
// BOJ	 : 15650
// Title : N과 M (2)
// Genre : 백트래킹
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"
#define MAX 9

using namespace std;

int N, M;
vector<int> answer;
bool visited[MAX];

void dfs(int num, int cnt)
{
	if (cnt == M)
	{
		sort(answer.begin(), answer.end());
		for (int num : answer)
		{
			cout << num << " ";
		}
		cout << endl;
		return;
	}

	for (int i = num; i <= N; i++)
	{
		if (visited[i]) continue;
		visited[i] = true;
		answer.push_back(i);
		dfs(i, cnt + 1);
		visited[i] = false;
		answer.pop_back();
	}
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
	cin >> N >> M;

	dfs(1, 0);

	return 0;
}