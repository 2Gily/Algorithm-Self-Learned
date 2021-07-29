#include <bits/stdc++.h>
using namespace std;
set<string> s;
bool check[10] = { false, };
string n;
int nlen;

void solve(string ans, string anssum, int len) //len은 이번에 추가해서 몇글자가 되었는지
{ 
	if (len == nlen) 
	{
		if (ans == n) 
		{
			s.insert(anssum);
		}

		return;
	}
	for (int i = 0; i <= 9; i++) 
	{
		string temp = to_string(i);
		if (check[i]) solve(temp + ans, temp + ans + anssum, len + 1);
	}
	for (int i = 0; i <= 9; i++) 
	{
		string temp = to_string(i);
		if (check[i]) solve(ans + temp, temp + ans + anssum, len + 1);
	}
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	nlen = n.size();

	for (int i = 0; i < n.size(); i++)
	{
		check[n[i] - '0'] = true;
	}

	for (int i = 0; i <= 9; i++)
	{
		if (check[i]) solve(to_string(i), to_string(i), 1);
	}
	cout << s.size();
	return 0;
}