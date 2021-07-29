#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
 
using namespace std;
 
bool chk(int n) {
    if (n < 2) return false;
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
 
int solution(string numbers) {
    int answer = 0;
    vector<int> v;
    for (int i = 0; i < numbers.size(); i++) {
        v.push_back(numbers[i] - '0');
    }
    sort(v.begin(), v.end());
    vector<int> ans;
    // 모든 경우의 수 찾기
    do {
        for (int i = 0; i <= v.size(); i++) {
            int tmp = 0;
            for (int j = 0; j < i; j++) {
                tmp = (tmp * 10) + v[j];
                ans.push_back(tmp);
                cout << "v[j] : " << v[j]  << "tmp : " << tmp << endl;
            }
        }
    } while(next_permutation(v.begin(), v.end()));
    
    // 중복된 vector값 제외
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    // 소수 찾기
    for (int i = 0; i < ans.size(); i++) {
        if (chk(ans[i])) answer += 1;
    }
    return answer;
}
