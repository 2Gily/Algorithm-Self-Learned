#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#pragma warning(disable:4996)

using namespace std;

int cmp(const pair<int, int> &a, const pair<int, int> &b) // ������ �ð��� ���ٸ� ���۽ð��� ���� ������ ����
{
	if (a.second == b.second)
	{
		return a.first < b.first;
	}

	return a.second < b.second;
}

int main(void)
{
	freopen("input.txt", "r", stdin);
	vector<pair<int, int>> v; // ���۽ð�, ����ð�

	int n;
	int answer = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int start, end;

		cin >> start >> end;
		v.push_back(make_pair(start, end));
	}

	sort(v.begin(), v.end(), cmp);

	int end = -1;

	for (int i = 0; i < n; i++)
	{
		if (v[i].first >= end) // ���� ȸ���� ���۽ð��� ���� ȸ���� ������ �ð����� ���ĸ�
		{
			answer++; // ȸ�Ǽ� ����
			end = v[i].second; // ������ �ð� end�� ���� v[i]�� ������ �ð��� �־���
		}
	}

	cout << answer << endl;

	return 0;
}