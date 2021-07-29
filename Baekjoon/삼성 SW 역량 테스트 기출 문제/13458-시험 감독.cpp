/*
����
N�� ������, i�� �������� ������ �� ������[i] = A��, �Ѱ����� �� �����忡�� B����� ���� ����, �ΰ������� C��
�� �����忡�� �Ѱ������� 1��, �ΰ������� ������
�̶� �ʿ��� ������(�Ѱ����� + �ΰ�����)�� ��

�Է�
ù° �ٿ� �������� ���� N(1 �� N �� 1,000,000)�� �־�����.

��° �ٿ��� �� �����忡 �ִ� �������� �� Ai (1 �� Ai �� 1,000,000)�� �־�����.

��° �ٿ��� B�� C�� �־�����. (1 �� B, C �� 1,000,000)

���
�� �����帶�� ���û��� ��� �����ϱ� ���� �ʿ��� �������� �ּ� ���� ����Ѵ�.
*/
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#define endl "\n"

using namespace std;

vector<int> A;

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main(void)
{
	init();

	int N,B, C;;
	long long sum = 0;

	cin >> N;

	for(int i = 0 ; i < N ; i++)
	{
		int temp;
		cin >> temp;

		A.push_back(temp);
	}

	cin >> B >> C;

	for (int i = 0; i < N; i++)
	{
		int temp = 0;

		A[i] -= B;
		sum++;

		if (A[i] <= 0) continue;

		temp = A[i] / C;
		A[i] -= temp * C;

		sum += temp;
		if (A[i] > 0) sum++;
	}

	cout << sum << endl;

	return 0;
}