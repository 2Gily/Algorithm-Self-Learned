#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

map<string,int> m;
vector<string> kinds;
int solution(vector<vector<string>> clothes) {
    long long answer = 1;
    
    for(auto c : clothes)
    {
        if(m[c[1]] == 0) kinds.push_back(c[1]);
        m[c[1]] += 1;
    }
    
    for(auto n : kinds)
    {
        answer *= m[n] + 1;
    }
    
    return answer -1;
}
