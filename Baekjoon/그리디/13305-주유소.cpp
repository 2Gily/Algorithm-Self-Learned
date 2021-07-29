#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#define MAX 100001
#pragma warning(disable:4996)

using namespace std;

//long long price[MAX];
//long long dist[MAX];

int main(void)
{
	freopen("input.txt", "r", stdin);

	long long n = 0;
	long long sum = 0;
	vector<long long> dist;
	vector<long long> price;
	
	cin >> n;

	for (int i = 0; i < n - 1; i++)
	{
		long long temp;
		cin >> temp;
		dist.push_back(temp);
	}

	for (int i = 0; i < n; i++) 
	{ 
		long long temp;
		cin >> temp;
		price.push_back(temp);
	}

	long long max_price = *max_element(price.begin(),price.end()); // ���� �� ���� ���� ������ �ϴ� �ʱ�ȭ

	for (int i = 0; i < n; i++)
	{
		if (max_price > price[i]) // ������ �ִ밪���� price[i]�� �� �����ϸ� ���⼭ �����ؾ���
		{
			max_price = price[i];
		}
		sum += max_price * dist[i];
	}

	cout << sum << endl;

	return 0;
}