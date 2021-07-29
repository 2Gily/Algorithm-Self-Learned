#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stdio.h>

using namespace std;

int pick(vector<vector<int>> &line, int n)
{
    int temp;
      
    for(int i = 0 ; i < line.size() ; i++)
    {
        if(line[i][n] != 0)
        {
            temp = line[i][n];
            line[i][n] = 0;
            
            return temp;
        }
    }
    return 0;
}

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int target = 0;
    vector<int> goal;

    for(int i = 0 ; i < moves.size() ; i++)
    {
        target = pick(board,moves[i]-1);
        if(target != 0) goal.push_back(target);
        else if(target == 0) continue;
        
        if(goal.size() > 0)
        {
            if(goal[goal.size()-2]==goal[goal.size()-1])
            {
                goal.pop_back();
                goal.pop_back();
                answer += 2;
            }
        }
    }
    return answer;
}
