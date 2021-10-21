// Date	 : 2021-10-21
// BOJ	 : 2292-¹úÁı
// Genre : ¼öÇĞ
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"

using namespace std;

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main(void)
{
	init();
	int N;
	cin >> N;

	if (N == 1) cout << 1 << endl;
	else
	{
		int cnt = 1;
		int start = 2;
		int number = 6;

		while (true)
		{
			int end = start + number - 1;
			cnt++;
			number = 6 * cnt;

			if (start <= N && N <= end)
			{
				break;
			}

			start = end + 1;
		}

		cout << cnt << endl;
	}

	return 0;
}