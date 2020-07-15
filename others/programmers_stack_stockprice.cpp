/*
    주식가격 - 가격이 떨어지지 않은 기간은 몇 초인지를 return 하도록 solution 함수를 완성하세요.
*/
#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    int s = prices.size();
    vector<int> answer(s);
    stack<int> st;
    for(int i = 0; i<s; i++){
    	while (!st.empty() && (prices[st.top()]>prices[i] || i==s-1)){
            answer[st.top()] = i-st.top();
			st.pop();
		}

		st.push(i);
    }

    return answer;
}