#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<bool> prime(n+1,true);
    
    prime[0] = false;
    prime[1] = false;
    
    for(int i = 2; i < n+1; i++)
    {
        if(!prime[i]) continue;
        for(int j = i+i ; j < n+1 ; j+=i)
        {
            prime[j]=false;
        }
    }
    
    for(int k = 2 ; k < n+1 ; k++)
    {
        if(prime[k]) answer++;
    }
    return answer;
}
