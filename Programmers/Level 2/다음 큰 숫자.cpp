#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int num = n + 1;
    int n_binary = 0;
    
    for(int i = 0 ; i < 32 ; i++)
    {
        if(n & (1 << i)) n_binary++;
    }
    
    while(true)
    {
        int count = 0;
        
        for(int i = 0 ; i < 32 ; i++)
        {
            if(num & (1 << i)) count++;
        }
        
        if(count == n_binary) return num;
        else num++;
    }
}
