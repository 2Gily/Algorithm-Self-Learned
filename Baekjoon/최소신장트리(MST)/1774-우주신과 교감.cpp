/*
[����]
�̹� ����Ǿ� �ִ� ������ �����Ѵ�. �������� �ڼ��ھ�, �ڼ��ھ��� ������ȣ 1�� �����Ѵ�.

[�Է�]
ù° �ٿ� ���ֽŵ��� ����(N<=1,000) �̹� ����� �ŵ���� ����� ����(M<=1,000)�� �־�����.

�� ��° �ٺ��� N���� �ٿ��� Ȳ���ڸ� �����Ͽ� ���ֽŵ��� ��ǥ�� (0<= X<=1,000,000), (0<=Y<=1,000,000)�� �־�����. 
�� ������ M���� �ٿ��� �̹� ����� ��ΰ� �־�����. ��ȣ�� ���� �Է¹��� ��ǥ���� ������� �����ϸ� �ȴ�. ��ǥ�� �����̴�.

[���]
ù° �ٿ� ������ �� �ּ��� ��� ���̸� ����϶�. ����� �Ҽ��� ��°¥������ ����Ͽ���.
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
#define MAX 1001
using namespace std;

typedef pair<int, int> PAIR;
typedef tuple<double, int, int> TUPLE;

int parent[MAX];
vector<PAIR> god;
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
	int N, M;
	cin >> N >> M;

	double answer = 0;

	for (int i = 1; i <= N; i++)
	{
		parent[i] = i; //�ڱ� �ڽ��� �θ�� ����
	}

	god.push_back({ 0,0 });

	for (int i = 1; i <= N; i++)
	{
		int x, y;
		cin >> x >> y;
		god.push_back({ x, y });
	}

	for (int i = 1; i <= M; i++)
	{
		int a, b;
		cin >> a >> b;
		Union(a, b); // �̹� ����� ��ε� �Է�
	}


	for (int i = 1; i <= N - 1; i++)
	{
		for (int j = i + 1; j <= N; j++)
		{
			double far = Calculate(god[i], god[j]);
			dist.push_back({ far, i, j }); // { A-B ������ �Ÿ�, A�� index, B�� index }
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