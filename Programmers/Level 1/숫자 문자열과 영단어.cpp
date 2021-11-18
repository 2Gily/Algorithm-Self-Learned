#include <string>
#include <vector>
#include <iostream>

using namespace std;

string alphabet[10] = {"zero", "one", "two", "three", "four", 
                      "five","six", "seven","eight","nine"};
string answer = "";

void trans(string s, string temp,int idx)
{
    if(idx >= s.size()) return;
    
    if('0' <= s[idx] && s[idx] <= '9')
    {
        answer += stoi(to_string(s[idx]));
        trans(s,"",idx+1);
        return;
    }
    else
    {
        temp += s[idx];
        
        for(int i = 0 ; i < 10 ; i++)
        {
            if(temp == alphabet[i])
            {
                answer += to_string(i);
                temp = "";
                break;
            }
        }
        
        trans(s,temp,idx+1);
    }
}

int solution(string s) {
    trans(s,"",0);
    return stoi(answer);
}
