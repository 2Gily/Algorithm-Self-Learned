#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#define endl "\n"

using namespace std;

vector<long long> v;
long long N, answer;
long long target;
bool check;

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void dfs(int idx, int cnt, long long sum)
{
	if (check) return;
	if (idx >= N) return;
	if (cnt > 3) return;

	sum += v[idx];

	if (cnt == 3)
	{
		if (sum == target)
		{
			answer = target;
			check = true;
			return;
		}
	}
	dfs(idx, cnt + 1, sum);
	dfs(idx + 1, cnt, sum - v[idx]);
}

int main(void)
{
	init();
	cin >> N;

	v = vector<long long>(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end(), greater<long long>());

	for (int i = 1; i < N; i++)
	{
		target = v[i-1];
		dfs(i, 1, 0);
		if (check) break;
	}
	
	cout << answer << endl;

	return 0;
}