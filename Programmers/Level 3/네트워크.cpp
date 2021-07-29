#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool visit[201]; // DFS 방문한 노드 체크

void dfs(int now, int n, vector<vector<int>> &computers)
{
    visit[now] = true;
    
    for(int i = 0 ; i < n ; i++)
    {
        if(!visit[i] && computers[now][i]) // 방문한적이 없고, computers[now][i]가 1이면
            dfs(i, n, computers);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i = 0 ; i < n ; i++)
    {
        if(!visit[i])
        {
            answer++;
            dfs(i, n, computers);
        }
    }
    
    return answer;
}
