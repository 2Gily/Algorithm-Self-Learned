#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#define MAX 1000001

using namespace std;

int main(void)
{
	long long number[MAX] = { 0, }; // number �迭���� Ƚ���� ��
	long long N;

	cin >> N;

	while (N > 1) // 0�� �� ������ �ʱ�ȭ ���� �״����. ������ �� Ƚ���� ���Ͽ� ���� ������ ����
	{
		if (number[N - 1] > number[N] + 1 || number[N - 1] == 0) number[N - 1] = number[N] + 1;
		if (N % 2 == 0 && (number[N / 2] > number[N] + 1 || number[N / 2] == 0)) number[N / 2] = number[N] + 1;
		if (N % 3 == 0 && (number[N / 3] > number[N] + 1 || number[N / 3] == 0)) number[N / 3] = number[N] + 1;
		N--;
	}

	cout << number[1];

	return 0;
}