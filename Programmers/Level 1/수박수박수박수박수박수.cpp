#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    int subak = 0;
    string word = "수박";
    string su = "수";
    
    subak = n / 2;
    
    for(int i = 0;i < subak;i++)
    {
        answer+=word;
    }
    
    if(n%2 == 1) answer += su;
    
    return answer;
}
