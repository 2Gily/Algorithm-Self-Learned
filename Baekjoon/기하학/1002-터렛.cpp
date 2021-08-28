// Date	 : 2021-08-01
// BOJ	 : 1002
// Title : 터렛
// Genre : 기하학
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
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
	int testcase;
	cin >> testcase;
	while (testcase--)
	{
		long long x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		/*
		1. 원이 두 점에서 만나는 경우
		r2 - r1 < d < r1 + r2

		2. 두 원이 외접하는 경우 (한점에서 만난다)
		d = r1 + r2

		3. 두 원이 내접하는 경우 (한점에서 만난다)
		d = r2 - r1
		and
		d != 0

		4. 하나의 원이 다른 원을 포함하는 경우 (만나지 않는다)
		d < r2 - r1

		5. 두 원이 멀리 떨어져 만나지 않는 경우
		d > r1 + r2

		6. 두 원이 일치하는 경우 (무수히 많은 점에서 만난다)
		d = 0
		r1 = r2
		*/
		long long dx = x1 - x2;
		long long  dy = y1 - y2;
		if (r1 > r2) swap(r1, r2);
		long long  add = r1 + r2;
		add = add * add; 
		long long  sub = r2 - r1;
		sub = sub * sub;
		long long  d = dx * dx + dy * dy;

		if (d < add && d > sub) 
		{ 
			cout << 2; 
		}
		else if (d == add || (d == sub && d != 0)) 
		{ 
			cout << 1;
		}
		else if (d < sub || d > add) 
		{ 
			cout << 0; 
		}
		else if (d == 0) 
		{ 
			if (r1 == r2) cout << -1; 
			else cout << 0; 
		} 
		cout << '\n';
	}

	return 0;
}