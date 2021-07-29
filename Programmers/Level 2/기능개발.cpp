#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> days;
    int work = 0;
    int done = 0;
    int wait = 0;
    int count = 1;
    
    for(int i = 0 ; i < progresses.size() ; i++)
    {
        work = (100 - progresses[i]) / speeds[i];
        if((100 - progresses[i]) % speeds[i] > 0) days.push(work+1);
        else days.push(work);
    }
    
    done = days.front();
    days.pop();
    
    while(!days.empty())
    {
        wait = days.front();
        if(wait <= done)
        {
            count++;
        }
        else
        {
            answer.push_back(count);
            count = 1;
            done = days.front();
        }
        days.pop();
        if(days.empty())
        {
            answer.push_back(count);
        }
    }
     
    return answer;
}
