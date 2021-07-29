#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) 
{
    vector<int> answer;
    int zero = 0;
    int correct = 0;
    
    for(int i = 0 ; i < lottos.size() ; i++)
    {
        if(lottos[i] == 0) zero++;
    }
    
    for(int i = 0 ; i < lottos.size() ; i++)
    {
        for(int j = 0 ; j < win_nums.size() ; j++)
        {
            if(lottos[i] == win_nums[j]) correct++;
        }
    }
    
    int max,min;
    

    max = 7 - (correct+zero);
    min = 7 - (correct);

    
    if(max > 5) max = 6;
    if(min > 5) min = 6;
    
    answer.push_back(max);
    answer.push_back(min);
    
    return answer;
}
