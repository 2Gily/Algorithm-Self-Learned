#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#define MAX 29

using namespace std;

int testcase;
int N, K;
int block;
char input[MAX];
deque<int> number;
vector<long long> answer;

void number_push(void)
{
	int idx = 0;
	while (idx < number.size())
	{
		int start = idx;
		int end = idx + block;
		long long tempSum = 0;
		int nn = block;

		for (start; start < end; start++)
		{
			tempSum += (long long)number[start] * (long long)pow(16, --nn);
		}

		idx = end;
		answer.push_back(tempSum);
	}
}

void ratate_number(void)
{
	for (int i = 0; i < N; i++)
	{
		number_push();

		number.push_front(number.back());
		number.pop_back();
	}
}

int chage_number(char ch)
{
	switch(ch){
		case 'A': return 10;
		case 'B': return 11;
		case 'C': return 12;
		case 'D': return 13;
		case 'E': return 14;
		case 'F': return 15;
		default: return (ch - '0');
	}
}

void init_data(void)
{
	memset(input, '\0', sizeof(input));
	number.clear();
	answer.clear();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> testcase;
	for (int i = 1 ; i <= testcase ; i++)
	{
		init_data();

		string temp;
		cin >> N >> K;
		cin >> temp;
		block = N / 4;
		
		for (int i = 0; i < temp.size(); i++)
		{
			input[i] = temp[i];
			number.push_back(chage_number(input[i]));
		}
		ratate_number();
		sort(answer.begin(), answer.end(), greater<int>());
		answer.erase(unique(answer.begin(), answer.end()), answer.end());
		cout << "#" << i << " " << answer[K - 1] << endl;
	}

	return 0;
}