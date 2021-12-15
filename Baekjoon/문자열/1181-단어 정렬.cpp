// Date	 : 2021-12-15
// BOJ	 : 1181-단어 정렬
// Genre : 문자열, 정렬
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"

using namespace std;

int N;
vector<string> words;

bool comp(string &a, string &b)
{
	if (a.size() == b.size())
	{
		return a < b;
	}
	return a.size() < b.size();
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
	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;
		words.push_back(temp);
	}
	
	sort(words.begin(), words.end(),comp);
	words.erase(unique(words.begin(), words.end()), words.end());
	for (string s : words)
	{
		cout << s << endl;
	}

	return 0;
}