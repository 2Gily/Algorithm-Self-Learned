#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<int> num;
    string s = to_string(n);
    
    for(int j=0 ; j < s.size() ; j++)
    {
        num.push_back(s[j]-'0');
    }
    
    sort(num.begin(), num.end(),less<>());
    
    for(int i=0; i < s.size() ; i++)
    {
        answer += num[i] * pow(10,i);
    }
    
    return answer;
}
