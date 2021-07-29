#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int shape = 0; // 0은 정사각형, 1은 직사각형
    int root = 0;
    
    root = sqrt(yellow);
    
    if(root * root == yellow) shape = 0;
    else shape = 1;
    
    if(brown == (root * 4) + 4 && shape == 0) // 정사각형이다.
    {
        answer.push_back(root+2);
        answer.push_back(root+2);
    }
    else if(brown == (yellow * 2) + 6 && shape == 1) // yellow가 한줄짜리인 직사각형
    {
        answer.push_back(yellow+2);
        answer.push_back(3);
    }
    else
    {
        for(int x = yellow / 2 ; x > 1 ; x--)
        {
            if(yellow % x == 0)
            {
                for(int y = x ; y > 1 ; y--)
                {
                    if((x*2) + (y*2) + 4 == brown && x * y == yellow)
                    {
                        answer.push_back(x+2);
                        answer.push_back(y+2);
                        return answer;
                    }
                }
            }

        }
    }
    return answer;
}
