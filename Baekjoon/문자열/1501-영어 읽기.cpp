#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <sstream>
#define endl "\n"

using namespace std;

int N, M;
map<string, bool> dic;
string first_str, end_str;

int check_dic(string str)
{
	int answer = 0;

	if (str.size() <= 3)
	{
		if (dic[str] == true) answer++;
	}
	else
	{
		string temp = str.substr(1, str.size()-2);
		sort(temp.begin(), temp.end());

		do
		{
			if (dic[first_str + temp + end_str]) answer++;

		} while (next_permutation(temp.begin(), temp.end()));
	}

	return answer;
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
		dic[temp] = true;
	}

	cin >> M;
	cin.ignore();

	for (int i = 0; i < M; i++)
	{
		string temp;
		getline(cin, temp);

		vector<string> v;
		string token;
		stringstream ss(temp);

		while (getline(ss, token, ' '))
		{
			v.push_back(token);
			cout << token << endl;
		}


	}
	
	return 0;
}