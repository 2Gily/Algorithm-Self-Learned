#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int i;

bool cmp(string &a, string &b){
    if (a[i] > b[i]) return false;
    else if (a[i] < b[i]) return true;
    else if (a[i] == b[i]){
        if(a > b) return false;
        else return true;
    }
}


vector<string> solution(vector<string> strings, int n) {
    i = n;
    sort(strings.begin(), strings.end(), cmp);
    return strings;
}
