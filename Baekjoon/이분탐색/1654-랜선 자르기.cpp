// Date	 : 2021-07-31
// Title : ���� �ڸ���
// BOJ	 : 1654
// Genre : �̺�Ž��
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"
#define MAX 10001
using namespace std;

int K, N;
long long max_length;
long long lan[MAX];

long long search_answer(void)
{
	long long start = 1;
	long long end = max_length;
	long long mid = (start + end) / 2;
	long long result = 0;

	while(start <= end)
	{	
		long long cnt = 0;
		mid = (start + end) / 2;

		for (int i = 0; i < K; i++)
		{
			cnt += lan[i] / mid;
		}

		if (cnt < N)
		{
			end = mid - 1;
		}
		else if (cnt >= N)
		{
			result = max(result, mid);
			start = mid + 1;
		}
	}
	
	return result;
}

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main(void)
{
	/*
	4 11
	802
	743
	457
	539
	=> ���� 457 539 743 802 �� 4���� 11���� ����� �ʹ�.
	�̹� ������ �ִ� ������ ���� K, �׸��� �ʿ��� ������ ���� N (K <= N )
	������ ��� N���� ���� ������ �������� ����� �;��� ������ K���� ������ �߶� ������ �Ѵ�.
	802cm �������� 4��, 743cm �������� 3��, 457cm �������� 2��, 539cm �������� 2���� �߶� ��� 11���� ���� �� �ִ�.
	*/
	init();
	cin >> K >> N;

	for (int i = 0; i < K; i++)
	{
		cin >> lan[i];
		max_length = max(max_length, lan[i]);
	}

	cout << search_answer() << endl;

	return 0;
}