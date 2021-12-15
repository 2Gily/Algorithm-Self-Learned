#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#include <stack>
#define endl "\n"

using namespace std;

int N;

bool comp(pair<string, int> a, pair<string, int> b)
{
	if (a.first[0] != b.first[0])
	{
		return a.first[0] < b.first[0];
	}

	return atoi(a.first.substr(2, a.first.size() - 2).c_str()) < atoi(b.first.substr(2, b.first.size() - 2).c_str()); // c.str() string -> char �ٲ��ִ� �޼ҵ�.
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
	cin >> N;

	N = 5 * N;

	vector<pair<string, int>> v(N);
	vector<int> num(N);
	stack<int> line, wait; // �����, ���� �����

	for (int i = 0; i < N; i++)
	{
		cin >> v[i].first; // Ƽ�� String
		v[i].second = i; // �Էµ� ����, �ε���
	}

	sort(v.begin(), v.end(), comp); // Ƽ�� ������� ����.

	for (int i = 0; i < N; ++i)
	{
		num[v[i].second] = i;
	}

	for (int i = N - 1; i >= 0; i--)
	{
		line.push(num[i]);
	}

	for (int i = 0; i < N; i++)
	{
		if (!wait.empty() && wait.top() == i)
		{
			wait.pop();
			continue;
		}

		bool in = false;
		
		while (!line.empty())  // ������� �� �� ������ �ݺ�, ������� �� ����µ� ���� ������� ������ �ʴ� �ٸ� false, ��� �����ٸ� true;
		{
			if (line.top() != i) // ����� -> ���� �����
			{
				wait.push(line.top());
				line.pop();
			}
			else // ����� -> ���� ����� -> �ٷ� ����
			{
				line.pop();
				in = true;
				break;
			}
		}

		if (!in) 
		{
			cout << "BAD" << endl;

			return 0;
		}
	}

	cout << "GOOD" << endl;

	return 0;
}