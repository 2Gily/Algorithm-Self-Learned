// Date	 : 2021-08-01
// BOJ	 : 1002
// Title : �ͷ�
// Genre : ������
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
		1. ���� �� ������ ������ ���
		r2 - r1 < d < r1 + r2

		2. �� ���� �����ϴ� ��� (�������� ������)
		d = r1 + r2

		3. �� ���� �����ϴ� ��� (�������� ������)
		d = r2 - r1
		and
		d != 0

		4. �ϳ��� ���� �ٸ� ���� �����ϴ� ��� (������ �ʴ´�)
		d < r2 - r1

		5. �� ���� �ָ� ������ ������ �ʴ� ���
		d > r1 + r2

		6. �� ���� ��ġ�ϴ� ��� (������ ���� ������ ������)
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