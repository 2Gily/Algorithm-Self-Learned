#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) 
{
    int count = 0;
    for(int i = 0 ; i < s.length() ; i++){
        if(count % 2 == 0){
            if(s[i] >= 'a' &&  s[i] <= 'z') s[i] -= 32;
        }
        else{
            if(s[i] >= 'A' &&  s[i] <= 'Z') s[i] += 32;
        }
        if(s[i] == ' ') count = 0;
        else count++;
    }
    return s;
}
