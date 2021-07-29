#include <string>
#include <iostream>
#include <cmath>
 
using namespace std;
 
//다음 문자열 확인함수
int nextCheck(string& dartResult, int i) {
    //인덱스가 길이를 넘지않는지 확인
    if (i + 1 < dartResult.length()) {
        if (dartResult[i + 1] == '*')    return 2;    //스타상이라면 2배
        else if (dartResult[i + 1] == '#') return -1;    //아차상이라면 -1배
    }
    return 1;    //아무것도 아니라면 1배
}
 
int solution(string dartResult) {
    int current = 0, Squared = 0, score[3]{ 0, 0, 0 };
    //문자열을 처음부터 끝까지 반복
    for (int i = 0; i < dartResult.length(); i++) {
        //몇 제곱인지 확인
        if (dartResult[i] == 'S')    Squared = 1;
        else if (dartResult[i] == 'D')    Squared = 2;
        else if (dartResult[i] == 'T')    Squared = 3;
        //점수가 확인되었다면
        if (Squared) {
            //앞의 숫자 확인하기 0~10;
            int temp_int = stoi(dartResult.substr(0, i));
            //다음글자를 확인해서 2배인지 -1배인지 1배인지 확인
            int mulityply = nextCheck(dartResult, i);
            //1배가 아니라면 -> 2배 혹은 -1배라면 2칸뒤로 이동
            if (mulityply != 1)     dartResult = dartResult.substr(i + 2);
            //옵션이 없으므로 1칸뒤로 이동한다.
            else    dartResult = dartResult.substr(i + 1);
            //2배점수였다면 이전점수 또한 2배로 바꿔준다.
            if (mulityply == 2 && current)     score[current - 1] *= 2;
            //현재 다트횟수에 점수를 넣어준다.
            score[current] = pow(temp_int, Squared) * mulityply;
            //문자열을 잘랐으므로 인덱스초기화, 다트회수증가,  S D T영역 초기화
            i = 0;    Squared = 0;  current++;
        }
    }
    return score[0] + score[1] + score[2];
}
