// Date	 : 2022-04-12
// BOJ	 : 2908 - 상수
// Genre : 구현
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
	string numOne, numTwo;
	cin >> numOne >> numTwo;

	reverse(numOne.begin(), numOne.end());
	reverse(numTwo.begin(), numTwo.end());

	int tOne = stoi(numOne);
	int tTwo = stoi(numTwo);
	if (tOne > tTwo) cout << tOne << endl;
	else cout << tTwo << endl;

	return 0;
}