#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> f(2);
    f[0] = 0; f[1] = 1;
    
    for(int i=2; i <= n; i++)
    {
        f.push_back(f[i-1] + f[i-2]) ;
        f[i] = f[i] % 1234567;
    }
    
    answer = f[n];
    return answer;
}
