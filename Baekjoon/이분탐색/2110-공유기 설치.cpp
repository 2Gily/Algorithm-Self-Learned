// Date	 : 2021-08-01
// BOJ	 : 2110
// Title : 공유기 설치
// Genre : 이분탐색
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

//공유기 두 개 사이의 거리가 x 이상이 되게 할 수 있는가?
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
	// C개를 설치하려고 한다.
	// 가장 인접한 두 공유기 사이의 거리를 가능한 크게 하여 설치하려고 한다.
	// 첫째 줄에 집의 개수 N (2 ≤ N ≤ 200,000)과 공유기의 개수 C (2 ≤ C ≤ N)이 하나 이상의 빈 칸을 사이에 두고 주어진다. 
	// 둘째 줄부터 N개의 줄에는 집의 좌표를 나타내는 xi (0 ≤ xi ≤ 1,000,000,000)가 한 줄에 하나씩 주어진다.
	init();
	cin >> N >> C;
	for (int i = 0; i < N; i++)
	{
		cin >> iptime[i];
		max_dist = max((int)max_dist, iptime[i]);
	}
	// 이진 탐색(이분 탐색) 하기전에는 반드시 정렬!!
	sort(iptime, iptime + N);
	// 이진 탐색(이분 탐색)
	cout << binarySearch(N, C) << endl;

	return 0;
}