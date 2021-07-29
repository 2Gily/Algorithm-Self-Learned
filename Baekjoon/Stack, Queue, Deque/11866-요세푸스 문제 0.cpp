#include <iostream>
#include <queue>
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
	int N, K;
	cin >> N >> K;

	queue<int> q;

	for (int i = 1; i < N + 1; i++)
	{
		int temp;
		cin >> temp;
		q.push(i);
	}

	cout << "<";

	while (1)
	{
		for (int i = 0; i < K-1; i++)
		{
			q.push(q.front());
			q.pop();
		}

		cout << q.front();
		q.pop();

		if (q.empty())
		{
			cout << ">" << endl;
			break;
		}

		cout << ", ";
	}

	return 0;
}