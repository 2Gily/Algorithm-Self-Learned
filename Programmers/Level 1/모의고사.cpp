#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> st_list(3,0);
    vector<int> student1 = {1, 2, 3, 4, 5};
    vector<int> student2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> student3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int st_1 = 0, st_2 = 0, st_3 = 0;
    int st_best = 0;
    
     for(int i = 0 ; i < answers.size() ; i++)
     {
         st_1 = i % student1.size();
         st_2 = i % student2.size();
         st_3 = i % student3.size();
         
         if(student1[st_1] == answers[i]) st_list[0]++;
         if(student2[st_2] == answers[i]) st_list[1]++;
         if(student3[st_3] == answers[i]) st_list[2]++;
     }
    
    st_best = *max_element(st_list.begin(),st_list.end());
    
    for(int j = 0 ; j < 3 ; j++)
    {
        if(st_list[j] == st_best) answer.push_back(j+1);
    }
    
    return answer;
}
