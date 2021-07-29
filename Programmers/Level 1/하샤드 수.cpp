#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    string number =to_string(x);
    int sum = 0;
    
    for(int i = 0 ; i < number.size() ; i++) sum += number[i] - '0';
    
    if(x % sum != 0) answer = false;
    
    return answer;
}
