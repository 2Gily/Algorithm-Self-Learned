#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string s[5] = { "A", "E", "I", "O", "U" };
vector<string> v;

void dfs(string now)
{
	for (int i = 0; i < 5; i++)
	{
		string temp = now + s[i];
		if (temp.length() > 5) continue;
		v.push_back(temp);
		dfs(temp);
	}
}

int solution(string word) 
{
	int answer = 0;
	dfs("");
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == word) answer = i + 1;
	}

	return answer;
}