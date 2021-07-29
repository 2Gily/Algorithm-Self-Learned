#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer[] = {"THU","FRI","SAT","SUN","MON","TUE","WED"};
    int month[]={31,29,31,30,31,30,31,31,30,31,30,31};
    int day = 0;
    int sum = 0;
    
    for(int i = 0;i < a-1;i++)
    {
        sum += month[i];
    }

    sum += b;
    
    day = sum % 7;
    
    return answer[day];
}
