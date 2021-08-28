// Date	 : 2021-08-01
// BOJ	 : 1085
// Title : 직사각형에서 탈출
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
	int x, y, w, h;
	cin >> x >> y >> w >> h;

	cout << min({ abs(x - w), abs(y - h),x,y }) << endl;

	return 0;
}