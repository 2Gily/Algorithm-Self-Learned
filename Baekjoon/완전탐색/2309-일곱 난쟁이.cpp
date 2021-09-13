// Date	 : 2021-09-14
// BOJ	 : 2309
// Title : ÀÏ°ö ³­ÀïÀÌ
// Genre : ¿ÏÀüÅ½»ö, Á¤·Ä
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#define endl "\n"

using namespace std;

int height[10];
int sum = 0;

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main(void)
{
	init();

	for (int i = 0; i < 10; i++)
	{
		cin >> height[i];
		sum += height[i];
	}

	sort(height, height + 9);

	for (int i = 0; i < 9; i++)
	{
		sum -= height[i];
		for (int j = 0; j < 9; j++) 
		{
			if (j == i) continue;
			sum -= height[j];
			if (sum == 100)
			{
				for (int idx = 0; idx < 9; idx++)
				{
					if (idx == i || idx == j) continue;
					cout << height[idx] << endl;
				}

				return 0;
			}
			sum += height[j];
		}
		sum += height[i];
	}

	return 0;
}