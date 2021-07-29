#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(string s)
{
    int num = 0;
    
    for(int i = 0 ; i < s.length() ; i++)
    {
        if(num < 0) return false;
        if(s[i] == '(') num++;
        else if(s[i] == ')') num--;
    }
    
    return num == 0; // 자체 조건문 t or f
}
