#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#define endl "\n"
#define MAX 150

using namespace std;

int map[MAX][MAX];
int number[101];
int r, c, k;
int row_size = 3, column_size = 3;
vector<pair<int, int>> temp;

void column_sort() 
{
	int new_row = 0;

	for (int i = 0; i < column_size; i++) 
	{

		for (int j = 0; j < row_size; j++) 
		{
			number[map[j][i]]++;
		}

		for (int k = 1; k <= 100; k++) 
		{
			if (number[k] != 0) 
			{
				temp.push_back({ number[k], k });
				number[k] = 0;
			}
		}

		sort(temp.begin(), temp.end());


		int temp_size = temp.size();
		int new_size = temp_size * 2;

		new_row = max(new_row, new_size);

		int index = 0;

		for (int k = 0; k < new_size; k += 2) 
		{
			map[k][i] = temp[index].second;
			map[k + 1][i] = temp[index].first;
			index++;
		}

		for (int k = new_size; k < row_size; k++) 
		{
			map[k][i] = 0;
		}

		temp.clear();
	}
	row_size = new_row;
}

void row_sort() 
{
	int new_column = 0; // ���ο� �� ũ�� �� �ִ�

	for (int i = 0; i < row_size; i++) 
	{
		for (int j = 0; j < column_size; j++) 
		{
			number[map[i][j]]++; //������ ���� Ƚ�� ī��Ʈ, number[index] �� ����.
		}
		
		for (int k = 1; k <= 100; k++)
		{
			if (number[k] != 0) //������ 0���� �ƴ϶�� temp�� �־��ְ� number�迭�� �ٽ� 0���� �ʱ�ȭ
			{
				temp.push_back({ number[k], k }); // ���� ����Ƚ���� ����, ���Ϳ� ������� push
				number[k] = 0;
			}
		}

		sort(temp.begin(), temp.end());

		int temp_size = temp.size();
		int new_size = temp_size * 2; // temp�� �ڷ��� pair

		new_column = max(new_column, new_size); // �� ������ ������

		int index = 0;

		for (int k = 0; k < new_size; k += 2) 
		{
			
			map[i][k] = temp[index].second; // ���� �ڿ� �־����Ƿ� second�� ����
			map[i][k + 1] = temp[index].first; // ���� ���� Ƚ���� first�� �־�����Ƿ� ���߿�
			index++;
		}

		
		for (int k = new_size; k < column_size; k++) 
		{
			map[i][k] = 0; // ���� ĭ 0
		}

		temp.clear();
	}
	column_size = new_column; //�� ũ��� �̹� ���꿡�� ���� �� ���� ũ���
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
	cin >> r >> c >> k;

	for (int i = 0; i < 3; i++) 
	{
		for (int j = 0; j < 3; j++) 
		{
			cin >> map[i][j];
		}
	}

	r--; // index ���߱�
	c--; // index ���߱�

	int time = 0;

	while (true)
	{
		if (map[r][c] == k) // ã�� ���
		{
			cout << time << endl;
			break;
		}

		time++;

		if (time > 100) // �ð��ʰ�
		{
			cout << -1 << endl;
			break;
		}

		if (row_size >= column_size)
		{
			row_sort();
		}
		else
		{
			column_sort();
		}
	}

	return 0;
}