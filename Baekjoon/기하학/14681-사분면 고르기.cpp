// Date	 : 2021-08-01
// BOJ	 : 14681
// Title : 사분면 고르기
// Genre : 기하학
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
	int x, y;
	cin >> x >> y;
	int answer;
	if (x > 0 && y > 0) answer = 1;
	else if (x < 0 && y > 0) answer = 2;
	else if (x < 0 && y < 0) answer = 3;
	else answer = 4;
	cout << answer << endl;
	return 0;
}