#include <string>
#include <vector>

using namespace std;

int solution(string s) {
	int answer = 0;
	int temp = 0;
	int n = 1;

	for (int i = 1; i < s.length()+1; i++)
	{
		temp = s[s.size() - i] - '0';
        if(temp >9 || temp <0) continue;
		temp *= n;
		answer += temp;
		n *= 10;
	}
    
    if(s[0] == '-') answer *=-1;

	return answer;
}
