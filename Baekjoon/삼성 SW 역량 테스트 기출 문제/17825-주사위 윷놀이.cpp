// Date	 : 2021-10-19
// BOJ	 : 17825-주사위 윷놀이
// Genre : 구현, 삼성 SW역량테스트
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"
#define FIN 32
#define MAX 33
#define max(a, b) (((a) > (b)) ? (a) : (b))

using namespace std;

typedef struct INFO {
	int nowPos;
	int nowScore;
	int nextPos[6];
}INFO;

int result;
INFO board[MAX]; // 보드의 점수, 다음 이동 칸
bool visited[MAX]; // 위치에 따른 말의 존재 여부
int malPos[4]; // 말의 위치
int dice[10]; // 주사위 순서대로 입력

void dfs(int cnt,int sum)
{
	if (cnt == 10)
	{
		result = max(result, sum);

		return;
	}

	for (int num = 0; num < 4; num++)
	{
		int dist = dice[cnt];
		int now = malPos[num];
		int next = board[now].nextPos[dist];
		int tempSum = board[next].nowScore;

		if (now == FIN) continue;
		if (visited[next] && next != FIN ) continue;

		
		visited[next] = true;
		visited[now] = false;
		malPos[num] = next;

		dfs(cnt + 1, sum + tempSum);

		visited[next] = false;
		visited[now] = true;
		malPos[num] = now;
	}
}

void init_board(void)
{
	for (int i = 0; i <= 20; i++)
	{
		INFO temp;
		temp.nowPos = i;
		temp.nowScore = i * 2;
		for (int j = 0; j <= 5; j++)
		{
			if (i + j > 20) temp.nextPos[j] = FIN;
			else temp.nextPos[j] = i + j;
		}
		board[i] = temp;
	}

	board[5] = { 5,10,{5,21,22,23,29,30} };
	board[10] = { 10,20,{10,24,25,29,30,31} };
	board[15] = { 15,30,{15,26,27,28,29,30} };
	board[20] = { 20,40,{20,FIN,FIN,FIN,FIN,FIN} };

	board[21] = { 21,13,{21,22,23,29,30,31} };
	board[22] = { 22,16,{22,23,29,30,31,20} };
	board[23] = { 23,19,{23,29,30,31,20, FIN} };
	board[24] = { 24,22,{24,25,29,30,31,20} };
	board[25] = { 25,24,{25,29,30,31,20,FIN} };
	board[26] = { 26,28,{26,27,28,29,30,31} };
	board[27] = { 27,27,{27,28,29,30,31,20} };
	board[28] = { 28,26,{28,29,30,31,20,FIN} };
	board[29] = { 29,25,{29,30,31,20,FIN,FIN} };
	board[30] = { 30,30,{30,31,20,FIN,FIN,FIN} };
	board[31] = { 31,35,{31,20,FIN,FIN,FIN,FIN} };
	board[32] = { FIN,0,{FIN,FIN,FIN,FIN,FIN,FIN} };

	//debug
	//for (int i = 0; i < MAX; i++)
	//{
	//	cout << board[i].nowPos << " " << board[i].nowScore << " {";
	//	for (int j = 1; j < 6; j++)
	//	{
	//		cout << board[i].nextPos[j] << " ";
	//	}
	//	cout << "}" << endl;
	//}
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
	init_board();
	for (int i = 0; i < 10; i++) cin >> dice[i];
	dfs(0, 0);
	cout << result << endl;

	return 0;
}