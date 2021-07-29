#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    
    long long small=a , big=b;
    
    if(a > b) big=a, small=b;
    else if(a == b) return a;
    
    for(small;small < big+1;small++)
    {
        answer+= small;
    }
    
    return answer;
}
