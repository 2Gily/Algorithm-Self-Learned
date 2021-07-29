#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    int i = 0;
        
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    for(int k = completion.size() ; k < participant.size() ; k++)
        completion.push_back("NULL");
    
    for(i ; i < participant.size() ; i++)
    {
        if(participant[i] != completion[i]) 
        {
            answer = participant[i];
            return answer;
        }
    }
}
