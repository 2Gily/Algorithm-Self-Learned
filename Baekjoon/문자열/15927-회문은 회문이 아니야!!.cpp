#include <vector>
#include <iostream>
#include <string>
#define endl "\n"

using namespace std;

string str;

bool answer = false;
bool palin = false;

int check_palin(string s)
{
	int size = s.size();

	for (int i = 0; i < size / 2; i++) // �Ӹ���� üũ
	{
		if (s[i] != s[size - i - 1]) return size;
	}

	for (int i = 1; i < size; i++) 
	{
		if (s[0] != s[i]) return size - 1; // ��ü ���� �������� üũ
	}

	return -1;
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
	cin >> str;

	cout << check_palin(str);

	return 0;
}