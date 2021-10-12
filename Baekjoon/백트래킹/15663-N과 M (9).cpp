// Date	 : 2021-10-11
// BOJ	 : 15663-N°ú M (9)
// Genre : Backtracking
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>

#define endl "\n"
#define MAX 9

using namespace std;

int N, M;
vector<int> number;
vector<int> answer;
bool visited[MAX];

void dfs(int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < answer.size(); i++)
		{
			cout << answer[i] << " ";
		}
		cout << endl;
		return;
	}

	int preNum = -1;

	for (int i = 0; i < N; i++)
	{
		if (preNum == number[i] || visited[i]) continue;
		visited[i] = true;
		preNum = number[i];
		answer.push_back(number[i]);
		dfs(cnt + 1);
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

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		number.push_back(temp);
	}

	sort(number.begin(), number.end());
	dfs(0);

	return 0;
}