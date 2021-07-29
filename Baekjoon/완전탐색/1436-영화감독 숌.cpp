#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

int main(void)
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);

	int N;
	int count = 0;
	int title = 665;
	string temp;

	cin >> N;

	while (title++) 
	{
		temp = to_string(title);

		if (temp.find("666") != string::npos)  // string.find( ) ã���� �ش� ��ġ�� index�� ��ȯ, ������ -1(string::npos) ��ȯ
		{
			++count;
		}

		if (count == N)
		{
			cout << title << endl;
			break;
		}
	}

	return 0;
}