#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int str_len = 0;
    int p_cnt = 0,y_cnt = 0;
    
    str_len = s.length();
    
    for(int i = 0;i < str_len + 1;i++)
    {
        if(s[i]=='p' || s[i]=='P') p_cnt++;
        else if(s[i]=='y' || s[i]=='Y') y_cnt++;
    }
    
    if(p_cnt != y_cnt) answer = false;
    
    return answer;
}
