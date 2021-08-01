// Date	 : 2021-08-01
// BOJ	 : 2110
// Title : ������ ��ġ
// Genre : �̺�Ž��
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"
#define MAX 100001
using namespace std;

int N, C;
int iptime[MAX];
long long max_dist = 0;

//������ �� �� ������ �Ÿ��� x �̻��� �ǰ� �� �� �ִ°�?
int binarySearch(int n, int c) 
{
	int left = 1;
	int right = iptime[n - 1];
	int answer = 0;

	while (left <= right) 
	{
		int cnt = 1;
		int mid = (right + left) / 2;
		int start = iptime[0];
		
		for (int i = 1; i < n; i++)
		{
			if (iptime[i] - start >= mid)
			{
				start = iptime[i];
				cnt++;
			}
		}
			
		if (cnt >= c) answer = mid, left = mid + 1;
		else  right = mid - 1;
	}
	return answer;
}

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main(void)
{
	// C���� ��ġ�Ϸ��� �Ѵ�.
	// ���� ������ �� ������ ������ �Ÿ��� ������ ũ�� �Ͽ� ��ġ�Ϸ��� �Ѵ�.
	// ù° �ٿ� ���� ���� N (2 �� N �� 200,000)�� �������� ���� C (2 �� C �� N)�� �ϳ� �̻��� �� ĭ�� ���̿� �ΰ� �־�����. 
	// ��° �ٺ��� N���� �ٿ��� ���� ��ǥ�� ��Ÿ���� xi (0 �� xi �� 1,000,000,000)�� �� �ٿ� �ϳ��� �־�����.
	init();
	cin >> N >> C;
	for (int i = 0; i < N; i++)
	{
		cin >> iptime[i];
		max_dist = max((int)max_dist, iptime[i]);
	}
	// ���� Ž��(�̺� Ž��) �ϱ������� �ݵ�� ����!!
	sort(iptime, iptime + N);
	// ���� Ž��(�̺� Ž��)
	cout << binarySearch(N, C) << endl;

	return 0;
}