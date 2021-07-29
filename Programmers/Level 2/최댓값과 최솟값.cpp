#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    int index = 0;
    vector<int> space;
    vector<int> temp;
    
    for(int i =0 ; i < s.size() ; i++)
    {
        if(s[i] == ' ') space.push_back(i);
    }
    
    for(int i = 0 ; i < space.size() ; i++)
    {
        if(i == 0)
        {
            temp.push_back(stoi(s.substr(index, space[i])));
            index = space[i]+1;
        }
        else
        {
            temp.push_back(stoi(s.substr(index, space[i] - index)));
            index = space[i] + 1;
        }
        
        if(i == space.size()-1)
        {
            temp.push_back(stoi(s.substr(index)));
        }
    }
    
    sort(temp.begin(), temp.end());
    
    answer = to_string(temp[0]) + " " + to_string(temp[temp.size()-1]);
    
    
    return answer;
}
