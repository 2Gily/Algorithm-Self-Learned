#include <iostream>
#include <cmath>
#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;
    int i = 0;
    int quo = 0;
    int res = n;
    
    while(1)
    {
        if(n/int(pow(10,i)) == 0) break;
        i++;
    }
    for(int j = i-1 ; j >= 0 ; j--)
    {
        quo = res / pow(10,j);
        res -= quo * pow(10,j);
        answer += quo;
    }
    return answer;
}
