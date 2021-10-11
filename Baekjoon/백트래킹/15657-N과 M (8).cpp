// Date	 : 2021-10-11
// BOJ	 : 15657-N°ú M (8)
// Genre : BackTracking
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#define endl "\n"
#define MAX 9
using namespace std;

int N, M;
vector<int> number;
vector<int> answer;

void dfs(int idx, int cnt)
{
	if (cnt == M)
	{
		vector<int>::iterator it;
		for (it = answer.begin(); it != answer.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
		
		return;
	}

	for (int i = idx; i < N; i++)
	{
		answer.push_back(number[i]);
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
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		number.push_back(temp);
	}
	sort(number.begin(), number.end());
	dfs(0, 0);

	return 0;
}