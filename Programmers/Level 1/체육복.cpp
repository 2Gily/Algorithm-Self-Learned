#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> cloth(n+2,1);
    int r = 0;
    /* 0번 n+1번 여유공간 만들기 */
    cloth[0] = 1;
    cloth[n+1] = 1; 
    
    for(int i = 0; i < reserve.size() ; i++) // 여유롭게 가지고 온 애들 ++
    {
        int r = reserve[i];
        cloth[r]++;
    }
    
    for(int i = 0 ; i < lost.size() ; i++) //  잃어버린 애들 --
    {
        int l = lost[i];
        cloth[l]--;
    }
    
    for(int i = 1 ; i < cloth.size()-1 ; i++)
    {
        if(cloth[i] == 2)
        {
            if(cloth[i-1] == 0 && cloth[i+1] == 0)
            {
                cloth[i-1]++;
                cloth[i]--;
            }
            else if(cloth[i-1] == 0 && cloth[i+1] != 0)
            {
                cloth[i-1]++;
                cloth[i]--;
            }
            else if(cloth[i-1] != 0 && cloth[i+1] == 0)
            {
                cloth[i+1]++;
                cloth[i]--;
            }
            else continue;
        }
    }
    
    for(int i = 0 ; i < cloth.size() ; i++)
    {
        if(cloth[i] > 0) answer++;
    }
    
    answer -= 2;
    
    return answer;
}
