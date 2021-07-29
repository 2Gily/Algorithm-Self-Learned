#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(string s) {
    bool answer = true;
    int n = s.length();
        
    if(n != 4 && n != 6) answer = false;
    
    cout<<" test1 : "<< answer << endl;
    
    for(int i = 0; i < n ; i++)
    {
        if(s[i] - '0' < 0 || s[i] -'0' > 9) answer = false;
    }
    
    return answer;
}
