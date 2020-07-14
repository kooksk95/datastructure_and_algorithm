/*
    (a) 레이저는 '()'으로 표현합니다. 또한 모든 '()'는 반드시 레이저를 표현합니다.
    (b) 쇠막대기의 왼쪽 끝은 여는 괄호 '('로, 오른쪽 끝은 닫힌 괄호 ')'로 표현됩니다.
    쇠막대기와 레이저의 배치를 표현한 문자열이 주어질 때, 잘린 쇠막대기 조각의 총 개수를 구하세요.

*/
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    stack<int> st;
    for(int i = 0; i<arrangement.size(); i++){
        if(arrangement[i] == '(')
            st.push(i);
        else{
            st.pop();
            if(arrangement[i-1] == '('){
                answer += st.size();
            } else
                answer++;
        }
    }
    
    return answer;
}