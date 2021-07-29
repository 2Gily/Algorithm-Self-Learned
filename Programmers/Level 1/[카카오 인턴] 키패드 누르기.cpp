#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int height(int n)
{
    if(n > 0 && n < 4) return 0;
    else if(n > 3 && n < 7) return 1;
    else if(n > 6 && n < 10) return 2;
    else return 3;
}

string check(int left,int right, int center, string hand)
{
    int xl = 2 - (left % 3);
    int xr;
    int yl = height(left), yc = height(center), yr = height(right);
    
    if(right % 3 == 0) xr = 1;
    else xr = 0;
    
    int dist_l = xl + abs(yl - yc);
    int dist_r = xr + abs(yr - yc);
    
    cout << "dist_l : " << dist_l << endl;
    cout << "dist_r : " << dist_r << endl;
    
    if(dist_l < dist_r) return "L";
    else if(dist_l > dist_r) return "R";
    else if(dist_l == dist_r)
    {
        if(hand == "left") return "L";
        else return "R";
    }
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left = 10, right = 12;
    
    for(int i = 0; i < numbers.size(); i++)
    {
        if(numbers[i] == 0) numbers[i] = 11;
        
        if(numbers[i] % 3 == 1)
        {
            answer.append("L");
            left = numbers[i];
        }
        else if(numbers[i] % 3 == 0)
        {
            answer.append("R");
            right = numbers[i];
        } 
        else
        {
            if(check(left, right, numbers[i],hand) =="L")
            {
                answer.append("L");
                left = numbers[i];
            }
            else if(check(left, right, numbers[i],hand) =="R")
            {
                answer.append("R");
                right = numbers[i];
            }
        }
    }
    return answer;
}
