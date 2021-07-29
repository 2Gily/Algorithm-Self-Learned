#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for(int i = 0 ; i < s.length() ; i++)
    {
        if(s[i] >= 'A' && s[i] <= 'Z')
        {
            if(s[i]+n > 'Z') s[i] = 64 + (s[i] + n - 'Z');
            else s[i] = s[i] + n;
        }
        else if(s[i] >= 'a' && s[i] <= 'z')
        {
            if(s[i]+n > 'z') s[i] = 96 + (s[i] + n - 'z');
            else s[i] = s[i] + n;
        }
    }
    return s;
}
