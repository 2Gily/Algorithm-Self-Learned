// Date	 : 2021-10-13
// BOJ	 : 15666-N°ú M (12)
// Genre : Backtracking
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"
#define MAX 8
using namespace std;

int N, M;
int number[MAX];
bool visited[MAX];
vector<int> answer;

void dfs(int cnt, int idx)
{
	if (cnt == M)
	{
		for (int a : answer)
		{
			cout << a << " ";
		}
		cout << endl;
		return;
	}

	int preNum = -1;

	for (int i = idx; i < N; i++)
	{
		if (preNum == number[i]) continue;
		preNum = number[i];
		answer.push_back(number[i]);
		dfs(cnt + 1, i);
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
	for (int i = 0; i < N; i++) cin >> number[i];

	sort(number, number + N);
	dfs(0, 0);

	return 0;
}