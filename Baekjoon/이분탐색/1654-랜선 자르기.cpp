// Date	 : 2021-07-31
// Title : 랜선 자르기
// BOJ	 : 1654
// Genre : 이분탐색
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
	=> 정렬 457 539 743 802 이 4개로 11개를 만들고 싶다.
	이미 가지고 있는 랜선의 개수 K, 그리고 필요한 랜선의 개수 N (K <= N )
	랜선을 모두 N개의 같은 길이의 랜선으로 만들고 싶었기 때문에 K개의 랜선을 잘라서 만들어야 한다.
	802cm 랜선에서 4개, 743cm 랜선에서 3개, 457cm 랜선에서 2개, 539cm 랜선에서 2개를 잘라내 모두 11개를 만들 수 있다.
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