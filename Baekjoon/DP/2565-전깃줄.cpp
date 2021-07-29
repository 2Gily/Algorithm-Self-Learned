#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[102];

int main() 
{
	int N, a, b;
	int result = 0;
	cin >> N;

	vector<pair<int, int>> v;
	v.emplace_back(0, 0); // 객체지향 언어 개념, 임시 객체를 만들어내서 거기에 넣는다
	for (int i = 0; i < N; i++) 
	{
		cin >> a >> b;
		v.emplace_back(a, b);
	}
	sort(v.begin(), v.end());


	for (int i = 1; i <= N; i++) 
	{
		for (int j = 0; j < i; j++) 
		{
			if (v[i].second > v[j].second) 
			{
				if (dp[j] >= dp[i]) 
				{
					dp[i] = dp[j] + 1;
				}
			}
		}
		result = max(result, dp[i]);
	}

	cout << N - result << endl;
	return 0;
}