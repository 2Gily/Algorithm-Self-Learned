#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    
    set<int> pon;
    
    for(int i = 0 ; i < nums.size() ; i++)
    {
        pon.insert(nums[i]);    
    }
    
    if(pon.size() > (nums.size()/2) )
    {
        answer = nums.size()/2;
    }
    else
    {
        answer = pon.size();
    }
       
    return answer;
}
