#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#define endl "\n"
#define MAX 100000

using namespace std;

int N, M;
vector<int> A;

int binarySearch(int low, int high, int target)
{
	if (low > high) // low�� high���� ũ�� ���� ��
	{
		return 0;
	}
	else
	{
		int mid = (low + high) / 2;

		if (A[mid] == target) return 1; // find
		else if (A[mid] > target) return binarySearch(low, mid - 1, target); // left
		else return binarySearch(mid + 1, high, target); //right
	}
}

void init()
{
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
}

int main(void)
{
	init();
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		A.push_back(num);
	}

	sort(A.begin(), A.end()); //�̺�Ž���� ���ĵǾ� �־�� �Ѵ�.

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int num;
		cin >> num;
		cout << binarySearch(0, N - 1, num) << endl;
	}

	return 0;
}
