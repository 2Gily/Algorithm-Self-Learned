// Date	 : 2021-10-20
// BOJ	 : 14888-연산자 끼워넣기(복습)
// Genre : 구현, 삼성 SW역량테스트
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"
#define MAX 12
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

using namespace std;

int N;
int minAnswer = 2e9;
int maxAnswer = -2e9;
int number[MAX];
int add,sub,mul,divi; // +,-,×,/

void dfs(int sum, int cnt)
{
	if (cnt == N)
	{
		minAnswer = min(minAnswer, sum);
		maxAnswer = max(maxAnswer, sum);
		return;
	}

	if (add > 0)
	{
		add--;
		dfs(sum + number[cnt], cnt + 1);
		add++;
	}
	if (sub > 0)
	{
		sub--;
		dfs(sum - number[cnt], cnt + 1);
		sub++;
	}
	if (mul > 0)
	{
		mul--;
		dfs(sum * number[cnt], cnt + 1);
		mul++;
	}
	if (divi > 0)
	{
		divi--;
		dfs(sum / number[cnt], cnt + 1);
		divi++;
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
	cin >> N;
	for (int i = 0; i < N; i++) cin >> number[i];
	cin >> add >> sub >> mul >> divi;
	dfs(number[0], 1);
	cout << maxAnswer << endl << minAnswer << endl;
	return 0;
}