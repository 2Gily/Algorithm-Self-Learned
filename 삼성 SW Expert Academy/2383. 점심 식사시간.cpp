#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cmath>
#define MAX 11
using namespace std;

typedef struct COORD {
	int y, x;
}COORD;

vector<COORD> stair, person;
int board[MAX][MAX];
int testcase;
int N;

int distance_cal(COORD P, COORD S)
{

}

int main(void)
{
	ios::sync_with_stdio(false); 
	cin.tie(0); 
	cout.tie(0);

	cin >> testcase;

	while (testcase--)
	{
		cin >> N;
		for (int y = 1; y <= N; y++)
		{
			for (int x = 1; x <= N; x++)
			{
				cin >> board[y][x];
			}
		}
	}
}