/*
[����]
n(2 �� n �� 100)���� ���ð� �ִ�. �׸��� �� ���ÿ��� ����Ͽ� �ٸ� ���ÿ� �����ϴ� m(1 �� m �� 100,000)���� ������ �ִ�. �� ������ �� �� ����� �� �ʿ��� ����� �ִ�.

��� ������ �� (A, B)�� ���ؼ� ���� A���� B�� ���µ� �ʿ��� ����� �ּڰ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

[�Է�]
ù° �ٿ� ������ ���� n�� �־����� ��° �ٿ��� ������ ���� m�� �־�����. �׸��� ��° �ٺ��� m+2�ٱ��� ������ ���� ������ ������ �־�����. ���� ó������ �� ������ ��� ������ ��ȣ�� �־�����. ������ ������ ������ ���� ���� a, ���� ���� b, �� �� Ÿ�µ� �ʿ��� ��� c�� �̷���� �ִ�. ���� ���ÿ� ���� ���ð� ���� ���� ����. ����� 100,000���� �۰ų� ���� �ڿ����̴�.

���� ���ÿ� ���� ���ø� �����ϴ� �뼱�� �ϳ��� �ƴ� �� �ִ�.

[���]
n���� ���� ����ؾ� �Ѵ�. i��° �ٿ� ����ϴ� j��° ���ڴ� ���� i���� j�� ���µ� �ʿ��� �ּ� ����̴�. ����, i���� j�� �� �� ���� ��쿡�� �� �ڸ��� 0�� ����Ѵ�.


[�÷��̵� �ͼ�]
1.��� �������� ��� ���������� �ִ� ��θ� �ѹ��� ���Ѵ�. �� ������ ����, ��� ���� �ִ� ��θ� ���ϰ� �ȴ�.
	��� ���� ǥ���ϴ� ���(������ �迭)�� �����ϰ� ���̳��� ���α׷��� ������� ������ ���ҵ�(�� ���� �ִܰŸ�)�� ������Ʈ �س�����.
		������Ʈ ���� -> ���� ���İ��� ����

2.���İ��� ������ �������� �˰����� �����Ѵ�.
	i ���� j �� ���µ� �ش� ������ �����ؼ� ���� ���� �� �����ٸ� �� ������ ���ļ� ���°ɷ� ������Ʈ �Ѵ�.

[����] https://ansohxxn.github.io/algorithm/floyd/
*/

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#define endl "\n"
using namespace std;

const int MAX = 101;
const int INF = 987654321;

int graph[MAX][MAX];
int city, bus;

void floyd_warshall()
{
	for (int i = 1; i <= city; i++)
	{
		for (int j = 1; j <= city; j++)
		{
			for (int k = 1; k <= city; k++)
			{
				if (graph[j][i] != INF && graph[i][k] != INF)
				{
					graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
				}
			}
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
	int from, to, weight;

	cin >> city >> bus;

	for (int i = 1; i <= city; i++)
	{
		for (int j = 1; j <= city; j++)
		{
			graph[i][j] = INF;
		}
	}

	for (int i = 0; i < bus; i++) 
	{    
		cin >> from >> to >> weight;

		if (graph[from][to] > weight)
			graph[from][to] = weight;
	}

	floyd_warshall();

	for (int i = 1; i <= city; i++) 
	{
		for (int j = 1; j <= city; j++)
		{
			if (i == j || graph[i][j] == INF)
			{
				cout << 0 << " ";
			}
			else
			{
				cout << graph[i][j] << " ";
			}
		}
		cout << endl;
	}

	return 0;
}