// Date	 : 2021-10-06
// BOJ	 : 15654
// Title : N°ú M (5)
// Genre : BackTracking
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"
#define MAX 9
using namespace std;

int N, M;
vector<int> number;
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

	for (int i = 0; i < N; i++)
	{
		if (visited[i]) continue;
		visited[i] = true;
		answer.push_back(number[i]);
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
	for (int i = 1; i <= N; i++)
	{
		int temp;
		cin >> temp;
		number.push_back(temp);
	}
	sort(number.begin(), number.end());
	dfs(0, 0);

	return 0;
}