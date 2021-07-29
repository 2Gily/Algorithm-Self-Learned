#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <stack>

#pragma warning(disable:4996)

using namespace std;

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main(void)
{
	init();
	freopen("input.txt", "r", stdin);

	stack<int> st;
	string answer = "";
	int now = 1;
	int n;
	cin >> n;

	while (n--)
	{
		int num;
		cin >> num;

		if (now <= num) // push ���� ���� ���ذ��� now���� �����ؾ��ϴ� num�� ũ�Ⱑ �� ũ�� ����
		{
			while (now <= num)
			{
				st.push(now);
				answer += '+';
				now++;
			}
			st.pop();
			answer += '-';
		}
		else // now(���ذ�)�� num���� Ŭ �� ���̻� push�� �� �� ���� pop�� ����
		{
			if (st.top() < num)
			{
				cout << "NO\n";
				return 0;
			}
			else
			{
				st.pop();
				answer += '-';
			}
		}
	}

	for (int j = 0; j < answer.size(); j++)
	{
		cout << answer[j] << "\n";
	}

	return 0;
}