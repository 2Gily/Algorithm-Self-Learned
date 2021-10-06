#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"

using namespace std;

int n, m;
int arr[10];
bool visited[10];

void DFS(int k) 
{ 
	if (k == m) 
	{ 
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';

		return;
	}

	for (int i = 1; i <= n; i++) 
	{ 
		if (!visited[i]) 
		{ 
			arr[k] = i;
			visited[i] = true;
			DFS(k + 1); 
			visited[i] = false;
		}
	}
}

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main(void)
{
	init();
	cin >> n >> m;

	DFS(0);

	return 0;
}