#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#define NMAX 12
#define endl "\n"
using namespace std;

int N;
int opCnt;
int num[NMAX];
vector<int> answer;

void dfs(int add, int sub, int multi, int divi, int sum,int idx)
{
	if (idx >= N)
	{
		answer.push_back(sum);
		return;
	}

	if (add > 0)
	{
		dfs(add - 1, sub, multi, divi, sum + num[idx], idx + 1);
	}
	if (sub > 0)
	{
		dfs(add, sub-1, multi, divi, sum - num[idx], idx + 1);
	}
	if (multi > 0)
	{
		dfs(add, sub, multi -1, divi, sum * num[idx], idx + 1);
	}
	if(divi > 0)
	{
		dfs(add, sub, multi, divi - 1, sum / num[idx], idx + 1);
	}

}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		memset(num, 0, sizeof(num));
		answer.clear();
		int add, sub, multi, divi;

		cin >> N;
		cin >> add >> sub >> multi >> divi;
		opCnt = N - 1;
		for (int i = 0; i < N; i++) cin >> num[i];

		dfs(add, sub, multi, divi, num[0], 1);

		int maxNum = *max_element(answer.begin(), answer.end());
		int minNum = *min_element(answer.begin(), answer.end());
		cout << "#" << test_case << " " << maxNum - minNum << endl;
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}