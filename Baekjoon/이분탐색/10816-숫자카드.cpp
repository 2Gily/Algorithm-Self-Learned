// Date	 : 2021-07-31
// Title : ����ī��
// BOJ	 : 10816
// Genre : �̺�Ž��
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#define endl "\n"

using namespace std;

int N, M;
vector<int> number;

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
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		number.push_back(temp);
	}
	sort(number.begin(), number.end());
	cin >> M;
	
	// 5 �̻� 11 ������ ���� :  upper_bound(arr.begin(), arr.end(), 11) - lower_bound(arr.begin(), arr.end(), 5)
	// N�� ���� :  upper_bound(arr.begin(), arr.end(), N) - lower_bound(arr.begin(), arr.end(), N);

	for (int i = 0; i < M; i++)
	{
		int findNumber;
		cin >> findNumber;
		cout << upper_bound(number.begin(), number.end(), findNumber) - lower_bound(number.begin(), number.end(), findNumber) << " ";
	}

	return 0;
}