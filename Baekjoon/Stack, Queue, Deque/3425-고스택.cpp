#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#define endl "\n"
#define MAX_NUM 1000000000

using namespace std;

typedef long long ll;

stack<ll> st;
vector<ll> num_operator;
vector<string> order;
int v_idx;

bool range_check(ll num)
{
	if (num > MAX_NUM) return true;
	else return false;
}

void NUM(void)
{
	st.push(num_operator[v_idx]);
	v_idx++;
	if (v_idx == num_operator.size()) v_idx = 0;
}

void POP(void)
{
	st.pop();
}

void INV(void)
{
	ll temp = st.top();
	st.pop();
	st.push(temp * -1);
}

void DUP(void)
{
	ll temp = st.top();
	st.push(temp);
}

void SWP(void)
{
	ll first, second;

	first = st.top();
	st.pop();
	second = st.top();
	st.pop();

	st.push(second);
	st.push(first);
}

void ADD(void)
{
	ll first, second;

	first = st.top();
	st.pop();
	second = st.top();
	st.pop();

	st.push(first + second);
}

void SUB(void)
{
	ll first, second;

	first = st.top();
	st.pop();
	second = st.top();
	st.pop();

	st.push(first - second);
}

void MUL(void)
{
	ll first, second;

	first = st.top();
	st.pop();
	second = st.top();
	st.pop();

	st.push(first * second);
}

void DIV(void)
{
	ll first, second, result = 0;
	int result_sign = 1;

	first = st.top();
	st.pop();
	second = st.top();
	st.pop();

	bool first_sign = false, second_sign = false;

	if (first < 0)
	{
		first_sign = true;
		first *= -1;
	}
	if (second < 0)
	{
		second_sign = true;
		second *= -1;
	}

	if (first_sign != second_sign)
	{
		result_sign = -1;
	}

	result = second / first;
	result *= result_sign;

	st.push(result);
}

void MOD(void)
{
	ll first, second, result = 0;
	int result_sign = 1;

	first = st.top();
	st.pop();
	second = st.top();
	st.pop();

	bool second_sign = false;

	if (second < 0)
	{
		second_sign = true;
		second *= -1;
	}

	if (second_sign)
	{
		result_sign = -1;
	}

	result = second % first;
	result *= result_sign;

	st.push(result);
}

void init(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main()
{
	init();

	while (true)
	{
		num_operator.clear();
		v_idx = 0;

		string str;
		cin >> str;

		while (true)
		{
			if (str == "QUIT") return 0;
			if (str == "END") break;
			if (str == "NUM")
			{
				int num;
				cin >> num;

				num_operator.push_back(num);
			}
		}

		int N;
		cin >> N;

		while (N--)
		{
			int num;
			cin >> num;

			while (st.empty()) st.pop();

			st.push(num);

			for (int idx = 0; idx < order.size(); idx++)
			{
				if (order[idx] != "NUM")
				{
					if (st.empty())
					{
						cout << "ERROR" << endl;
						break;
					}
				}

				if (order[idx] == "SWAP" || order[idx] == "ADD" || order[idx] == "SUB" || order[idx] == "MUL" || order[idx] == "DIV" || order[idx] == "MOD")
				{
					if (st.size() < 2)
					{
						cout << "ERROR" << endl;
						break;
					}
				}

				if (order[idx] == "NUM") NUM();
				else if (order[idx] == "POP") POP();
				else if (order[idx] == "INV") INV();
				else if (order[idx] == "DUP") DUP();
				else if (order[idx] == "SWP") SWP();
				else if (order[idx] == "ADD") ADD();
				else if (order[idx] == "SUB") SUB();
				else if (order[idx] == "MUL") MUL();
				else if (order[idx] == "DIV") DIV();
				else if (order[idx] == "MOD") MOD();
			}

			if (range_check(st.top()))
			{
				cout << "ERROR" << endl;
			}
		}

		cin.ignore();
	}

	return 0;
}