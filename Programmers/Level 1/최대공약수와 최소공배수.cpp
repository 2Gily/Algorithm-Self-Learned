#include <string>
#include <vector>

using namespace std;

int GCD(int a, int b) // 최대공약수
{  
    return b ? GCD(b, a%b) : a; //삼항 연산자 활용
}

int LCM(int a, int b) // 최소공배수
{
    return a * b / GCD(a,b);
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    answer.push_back(GCD(n,m));
    answer.push_back(LCM(n,m));
    return answer;
}
