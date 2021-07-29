#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <stack>

//#pragma warning(disable:4996)

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
	//freopen("input.txt", "r", stdin);

	int n;
	cin >> n;

	vector<int> number(n); // input ���ڸ� ��Ƶδ� �迭
	vector<int> answer(n); // return�� ���� �־�δ� �迭
	stack<int> st; // ���� ��ū���� ã�� ���� index�� ��Ƶδ� ����(*)

	for (int i = 0 ; i < n ; i++)
	{
		cin >> number[i];
	}

	for (int i = 0; i < n; i++)
	{
		while (!st.empty() && number[st.top()] < number[i])
		{
			answer[st.top()] = number[i];
			st.pop();
		}
		st.push(i);
	}

	while (!st.empty())
	{
		answer[st.top()] = -1;
		st.pop();
	}

	for (int num : answer)
	{
		cout << num << " ";
	}

	return 0;
}