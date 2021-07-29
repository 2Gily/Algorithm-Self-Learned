/*
[����]
�����̴� ������ ���̴�. ���� �����̴� �ƹ����Գ� �κ귯�� �ִ� n���� ������ �̾ ���ڸ��� �ϳ� ���� ���̴�. ���ڸ��� ������ ������ ����.

���ڸ��� �̷�� ���� ���� �ٸ� �� ���� ���������� ���� �����̴�.
��� ������ ���ڸ� ���� ���� ���� ���� ��/���������� �̾��� �־�� �Ѵ�.
������ 2���� ��� ���� ���� �ִ�. ���� �ϳ� ���� ������ �� �� ������ �Ÿ���ŭ�� ����� ��ٰ� �� ��, ���ڸ��� ����� �ּ� ����� ���Ͻÿ�.

[�Է�]
ù° �ٿ� ���� ���� n�� �־�����. (1 �� n �� 100)

��° �ٺ��� n���� �ٿ� ���� �� ���� x, y��ǥ�� �Ǽ� ���·� �־�����, �ִ� �Ҽ��� ��°�ڸ����� �־�����. ��ǥ�� 1000�� ���� �ʴ� ���� �Ǽ��̴�.

[���]
ù° �ٿ� ������ ����Ѵ�. ����/��� ������ 1/100���� ����Ѵ�.(�Ҽ��� 2°¥������ ���)

[�Է�]
3
1.0 1.0
2.0 2.0
2.0 4.0

*/

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#include <tuple>
#define endl "\n"
#define MAX 101
using namespace std;

typedef pair<double, double> PAIR;
typedef tuple<double, int, int> TUPLE;

int parent[MAX];
vector<PAIR> star;
vector<TUPLE> dist;

int Find(int index)
{
	if (parent[index] == index) return index; // �θ����� ���
	else return parent[index] = Find(parent[index]);
}

bool Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (a == b) return false; // �θ� ��尡 ���ٸ� ����Ŭ�� ����Ƿ� �ǳʶ�
	else
	{
		parent[a] = b; // a�� �θ� b�� ����, Ʈ�� ����

		return true;
	}
}

double Calculate(PAIR a, PAIR b)
{
	double x = pow(b.first - a.first, 2);
	double y = pow(b.second - a.second, 2);

	return sqrt(x + y);
}

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main()
{
	init();
	int N;
	cin >> N;

	double answer = 0;

	for (int i = 1; i <= N; i++)
	{
		parent[i] = i; //�ڱ� �ڽ��� �θ�� ����
	}
		
	// ������ ��ǥ �Է�
	star.push_back({ 0,0 });

	for (int i = 1; i <= N; i++)
	{
		double x, y;
		cin >> x >> y;
		star.push_back({ x, y });
	}

	// i��° ���� j��° �� ������ �Ÿ� ���
	for (int i = 1; i <= N - 1; i++)
	{
		for (int j = i + 1; j <= N; j++)
		{
			double far = Calculate(star[i],star[j]);
			dist.push_back({ far, i, j }); // { A-B ������ �Ÿ�, �� A�� index, �� B�� index }
		}
	}

	sort(dist.begin(), dist.end());

	// MST ���
	for (int i = 0; i < dist.size(); i++)
	{
		double x = get<1>(dist[i]);
		double y = get<2>(dist[i]);
		double far = get<0>(dist[i]);
		if (Union(x, y)) answer += far;
	}

	cout << fixed;
	cout.precision(2);
	cout << answer << endl;
	
	return 0;
}