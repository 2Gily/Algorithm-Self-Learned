#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b)
{
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> ntos;
    
    for(int i: numbers)
    {
        ntos.push_back(to_string(i));
    }
    
    sort(ntos.begin(), ntos.end(), cmp);
    
    for(string str: ntos) answer += str;
    
    if(answer[0] == '0') return "0";
    
    return answer;
}
