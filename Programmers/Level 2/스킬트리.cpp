#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    string word;
    bool flag = true;
    vector<char> temp;
    
    for(int i = 0 ; i < skill_trees.size() ; i++)
    {
        word = skill_trees[i];
        
        for(int j = 0 ; j < skill_trees[i].size() ; j++)
        {
            for(int k = 0 ; k < skill.size() ; k++)
            {
                if(word[j] == skill[k])
                {
                    temp.push_back(word[j]);
                    break;
                }
            }
        }
        
        int n_temp = temp.size();
        
        for(int m = 0 ; m < n_temp ; m++)
        {
            if(skill[m] != temp[m])
            {
                flag = false;
                break;
            }
        }
        
        if(flag) answer++;
        else
        {
            flag = true;
        }
        
        temp.clear();
    }
    
    return answer;
}
