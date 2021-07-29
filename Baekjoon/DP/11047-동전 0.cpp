#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#define MAX 101

using namespace std;

int money[MAX];

int main(void)
{
	int n, k; 
	int cnt = 0;

	cin >> n >> k;

	for (int i = 1; i <= n; i++) // ������������ �־���
	{
		cin >> money[i];
	}

	for (int i = n; i > 0; i--) 
	{
		cnt += k / money[i]; // k���� money[i] ���� ũ�� ������ ���� 0
		k %= money[i];

		if (k == 0) break;
	}
	cout << cnt;

	return 0;
}