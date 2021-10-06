// Date	 : 2021-10-06
// BOJ	 : 15651
// Title : N과 M (3)
// Genre : 백트래킹
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"
#define MAX 8
using namespace std;

int N, M;
bool visited[MAX];
vector<int> answer;

void dfs(int num, int cnt)
{
	if (cnt == M)
	{
		for (int number : answer)
		{
			cout << number << " ";
		}
		cout << endl;
		return;
	}

	for (int i = num; i <= N; i++)
	{
		answer.push_back(i);
		dfs(i, cnt + 1);
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