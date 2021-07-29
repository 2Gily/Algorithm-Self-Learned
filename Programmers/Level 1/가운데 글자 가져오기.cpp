#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) 
{
    string answer = "";
    
    if(s.length()%2 != 0)
    {
        int idx = (s.length()/2);
        answer = s.substr(idx,1);
    }
    else
    {
        int idx = (s.length()/2)-1;
        answer = s.substr(idx,2);
    }
    
    return answer;
}
