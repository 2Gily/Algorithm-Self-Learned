#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> arr;
    int quo = 0 , rem = 0;
    while(n>0)
    {
        quo = n / 3;
        rem = n % 3;
        n = quo;
        arr.push_back(rem);
    }
    
    reverse(arr.begin(),arr.end());
    
    for(int i = arr.size()-1 ; i > -1 ; i--)
    {
        answer += arr[i] * pow(3,i);
    }
    
    
    
    return answer;
}
