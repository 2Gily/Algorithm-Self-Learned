/*
[����]
���� 2040��, �̹����� ���ֿ� �ڽŸ��� �ձ��� �������. �ձ��� N���� �༺���� �̷���� �ִ�. �����̴� �� �༺�� ȿ�������� �����ϱ� ���ؼ� �༺�� �����ϴ� �ͳ��� ������� �Ѵ�.

�༺�� 3���� ��ǥ���� �� ������ �����ϸ� �ȴ�. �� �༺ A(xA, yA, zA)�� B(xB, yB, zB)�� �ͳη� ������ �� ��� ����� min(|xA-xB|, |yA-yB|, |zA-zB|)�̴�.

�����̴� �ͳ��� �� N-1�� �Ǽ��ؼ� ��� �༺�� ���� ����ǰ� �Ϸ��� �Ѵ�. �̶�, ��� �༺�� �ͳη� �����ϴµ� �ʿ��� �ּ� ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

[�Է�]
ù° �ٿ� �༺�� ���� N�� �־�����. (1 �� N �� 100,000) ���� N�� �ٿ��� �� �༺�� x, y, z��ǥ�� �־�����. ��ǥ�� -109���� ũ�ų� ����, 109���� �۰ų� ���� �����̴�. �� ��ġ�� �༺�� �� �� �̻� �ִ� ���� ����.

[���]
ù° �ٿ� ��� �༺�� �ͳη� �����ϴµ� �ʿ��� �ּ� ����� ����Ѵ�.
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
using namespace std;

typedef pair<int, int> PAIR;
typedef tuple<long long, int, int> TUPLE;
const int MAX = 100000;

int N;
vector<int> parent;

int Find(int index)
{
	if (parent[index] == index) return index; // �θ����� ���
	else return parent[index] = Find(parent[index]);
}

bool Union(int a, int b) 
{
	a = Find(a);
	b = Find(b);

	if (a == b) return false;
	else if (a > b) parent[a] = b;
	else parent[b] = a;

	return true;
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
	cin >> N;

	parent.assign(N, 0);
	for (int i = 0; i < N; i++) 
	{
		parent[i] = i;
	}

	vector<PAIR> x, y, z;
	vector<TUPLE> distance;

	for (int i = 0; i < N; i++) 
	{
		int a, b, c;
		cin >> a >> b >> c;
		x.push_back({ a, i }); // { x��ǥ, index }
		y.push_back({ b, i }); // { y��ǥ, index }
		z.push_back({ c, i }); // { z��ǥ, index }
	}
	// ��� ������ ������ vector�迭�� �̿��� ������ N x (N-1)�� ��ŭ �ҿ�� O(N^2)��ŭ �ð����⵵, �������⵵
	sort(x.begin(), x.end()); 
	sort(y.begin(), y.end());
	sort(z.begin(), z.end());

	for (int i = 0; i < N - 1; i++) 
	{
		distance.push_back({ abs(x[i].first - x[i + 1].first), x[i].second, x[i + 1].second });
		distance.push_back({ abs(y[i].first - y[i + 1].first), y[i].second, y[i + 1].second });
		distance.push_back({ abs(z[i].first - z[i + 1].first), z[i].second, z[i + 1].second });
	}

	sort(distance.begin(), distance.end());

	int count = 0;
	long long sum = 0;

	for (int i = 0; i < distance.size() && count != N - 1; i++) // MST
	{
		if (Union(get<1>(distance[i]), get<2>(distance[i])))
		{
			count++;
			sum += get<0>(distance[i]);
		}
	}

	cout << sum << endl;

	return 0;
}