#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue< int, vector<int>, greater<int> > pq;
    
    for(int i = 0 ; i < scoville.size() ; i++)
    {
        pq.push(scoville[i]);
    }
    
    while(pq.top() < K)
    {
        int first = pq.top();
        int second = 0;
        
        pq.pop();
        
        if(pq.empty()) return -1;
        else
        {
            second = pq.top();
            pq.pop();
        }
        
        pq.push(first + (second*2));
        
        answer++;
    }
    
    return answer;
}
