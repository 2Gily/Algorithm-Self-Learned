#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#define MAX 1001

using namespace std;

/*
������ Ǯ���� ���� �� �����ϴ� �κм����� �տ��� �ϴ� ���̶� �ڿ��� �ϴ� ���̶��ؼ�
���� ���� �����ϴ� �迭�� ���� ����� Front[i] Back[i]�� ���� ���� ū ��
*/

int main()
{
	int N;
	int number[MAX] = { 0, };
	int front[MAX] = { 0, };
	int back[MAX] = { 0, };

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> number[i];
	}

	for (int i = 0; i < N; i++)
	{
		front[i] = 1;
		back[i] = 1;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (number[j] < number[i] && front[j] >= front[i])
			{
				front[i] = front[j] + 1;
			}
		}
	}

	for (int i = N - 1; i >= 0; i--)
	{
		for (int j = N - 1; j >= i; j--)
		{
			if (number[j] < number[i] && back[j] >= back[i])
			{
				back[i] = back[j] + 1;
			}
		}
	}

	int answer = front[0] + back[0];

	for (int i = 1; i < N; i++)
	{
		int temp = front[i] + back[i];
		if (temp > answer) answer = temp;
	}

	cout << answer - 1 << endl;

	return 0;
}

