using namespace std;

long long solution(int price, int money, int count)
{
	long long answer = -1;
	long long sum = 0;

	for (int i = 1; i <= count; i++) sum += i * price;

	long long emptyMoney = money - sum;
	if (emptyMoney < 0) answer *= emptyMoney;
	else answer = 0;

	return answer;
}