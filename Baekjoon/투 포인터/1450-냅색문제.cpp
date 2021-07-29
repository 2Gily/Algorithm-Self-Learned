#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#define endl "\n"

using namespace std;

long long N, C, W[31], answer;
vector<long long> group1;
vector<long long> group2;

void dfs(int start, int end, vector<long long>& v, long long sum)
{
	if (start > end)
	{
		v.push_back(sum);
		return;
	}
	else
	{
		dfs(start + 1, end, v, sum);
		dfs(start + 1, end, v, sum + W[start]);
	}
}

// N : 2 , C : 1
// dfs(0, 1, group1, 0)
// dfs(2, 1, group2, 0)
// 1 1 group1, 0
// 2 1 gruop1, 0
// if(start > end) -> true group1 = {0};
// 2 1 group1 0+1
// if(start > end) -> true group1 = {0, 1};

int main()
{
	cin >> N >> C;

	for (int i = 0; i < N; i++)
	{
		cin >> W[i];
	}

	// ������ ������ ����Ǽ� ����  
	dfs(0, N / 2, group1, 0); // 0 ~ N/2 ���� ����� �� ã��.
	dfs(N / 2 + 1, N - 1, group2, 0); // N/2 + 1 ~ N���� ����� �� ã��.
	sort(group2.begin(), group2.end());


	for (int i = 0; i < group1.size(); i++)
	{
		answer += upper_bound(group2.begin(), group2.end(), C - group1[i]) - group2.begin();

		/*
		upper_bound ��?
		- lower_bound�� ���������� ����Ž��(Binary Search)����� Ž���� �Դϴ�.
		- ����Ž��(Binary Search)����̹Ƿ� �迭�̳� ����Ʈ�� ������������ ���� �Ǿ��־�� �մϴ�.
		- upper_bound�� key���� �ʰ��ϴ� ���� ù ��° ������ ��ġ�� ���ϴ� �� �Դϴ�.
		- ���� ���Ұ� ������ ���� �ص� �׻� ������ �ظ� ���� �� �ֽ��ϴ�.
		- ������ [start, end]�� �迭�� ������, �߰���ġ�� index�� mid ��� �ϸ�, arr[mid-1] <= key �̸鼭 arr[mid] > key �� �ּ��� m ���� ã���� �˴ϴ�. (m>=2)
		- upper_bound���� ����ؾ� �� ���� (���� ���� �ƴ�) key ���� �ʰ��ϴ� ���� ù��° ������ ��ġ ��� �� �Դϴ�.
		*/
	}

	cout << answer << endl;

	return 0;
}