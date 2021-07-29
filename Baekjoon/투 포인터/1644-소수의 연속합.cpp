#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
vector<int> primes;
vector<bool> check;

void MakePrime(void) // �����佺�׳׽��� ü
{
	for (int i = 2; i*i <= n; i++)
	{
		if (!check[i]) continue;

		for (int j = i * i; j <= n; j += i)
		{
			check[j] = false;
		}
	}

	for (int i = 2; i <= n; i++)
	{
		if (check[i]) primes.push_back(i);
	}
}

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main()
{
	cin >> n;
	
	check.resize(n + 1, true);

	MakePrime();

	int answer = 0;
	int sum = 0;
	int low = 0, high = 0;

	while (true) 
	{
		if (sum >= n) // n���� sum(�Ҽ��� ��)�� ���ų� ū ���
		{
			sum -= primes[low++];
		}
		else if (high == primes.size()) 
		{
			break;
		}
		else // n���� sum(�Ҽ��� ��)�� ���� ���
		{
			sum += primes[high++];
		}

		if (sum == n) answer++;
	}

	cout << answer;

	return 0;
}