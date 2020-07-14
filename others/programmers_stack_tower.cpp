/*
    수평 직선에 탑 N대를 세웠습니다. 탑의 꼭대기에서 발사한 신호는 송신탑보다 높은 탑에서만 수신합니다.
    또한, 한 번 수신된 신호는 다른 탑으로 송신되지 않습니다.
    탑의 높이를 담은 배열이 주어질 때 각 탑이 쏜 신호를 어느 탑에서 받았는지 기록한 배열을 반환해주세요.
*/
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> heights) {
    int s = heights.size();
    vector<int> answer(s);
    stack<pair<int,int>> st; //height, position
    
    st.push({heights[s-1], s-1});
    s -= 2;
    for(int i = s; i>=0; i--){
        while(!st.empty() && st.top().first<heights[i]){
            answer[st.top().second] = i+1;
            st.pop();
        }
        st.push({heights[i], i});
    }
    
    return answer;
}