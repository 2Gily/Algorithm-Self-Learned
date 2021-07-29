#include <vector>
#include <iostream>
#include <string>
#include <cmath>
#include <functional>
#define endl "\n"

using namespace std;

string number[10] =
{
	"####.##.##.####",
	"..#..#..#..#..#",
	"###..#####..###",
	"###..####..####",
	"#.##.####..#..#",
	"####..###..####",
	"####..####.####",
	"###..#..#..#..#",
	"####.#####.####",
	"####.####..####"
};

vector<int> number_list[10];
vector<string> v;
int n;
int total_cnt;
double answer = 0.0;

//void dfs(int idx, int now_num)
//{
//	if (idx == n) 
//	{
//		answer += (double)now_num;
//		cnt++;
//		return;
//	}
//
//	for (int i = 0; i < number_list[idx].size(); i++)
//	{
//		dfs(idx + 1, now_num + number_list[idx][i]);
//	}
//}

void possible_check(string temp,int pos)
{
	int cnt = 0;
	double sum = 0;

	for (int num = 0; num < 10; num++)
	{
		bool flag = true;

		for (int i = 0; i < 15; i++)
		{
			if (temp[i] == '#')
			{
				if (number[num][i] == '.')
				{
					flag = false;
					break;
				}
			}
		}
		if (flag) 
		{
			int num_temp = num * pow(10, n - (pos + 1));
			number_list[pos].push_back(num_temp);
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
	scanf_s("%d", &n);

	for (int i = 0; i < 5; i++)
	{
		string temp;
		cin >> temp;
		v.push_back(temp);
	}

	int num = 0;

	while (num < n)
	{
		string temp = "";

		for (int i = 0; i < 5; i++)
		{
			for (int j = num * 4; j < num * 4 + 3; j++) 
			{
				temp += v[i][j];
			}
		}

		possible_check(temp, num);

		if (number_list[num].size() == 0)
		{
			printf("-1\n");
			return 0;
		}
		else
		{
			double temp_sum = 0.0;

			for (int k = 0; k < number_list[num].size(); k++)
			{
				temp_sum += number_list[num][k];
			}

			answer += temp_sum / number_list[num].size();
		}

		num++;
	}

	printf("%lf\n", answer);

	
	return 0;
}