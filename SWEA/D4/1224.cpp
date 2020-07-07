/*
    계산기3 - 괄호가 있는 한자리수 +/* 하는 계산기 *후위표기식으로 바꾼 후 계산하기
*/

#include<bits/stdc++.h>

using namespace std;
char priority[3] = {'(', '+', '*'};

int calc (string str) {
    stack<int> nums;
    for(int i = 0; i<str.size(); i++) {
        char c = str[i];
        if(c == '+' || c == '*'){
            int a = nums.top(); nums.pop();
            int b = nums.top(); nums.pop();
            if(c=='+') nums.push(a+b);
            else nums.push(a*b);
        } else
            nums.push(c-'0');
    }
    
    return nums.top();
}

bool is_prior(char target, char comp){
    return find(priority, priority+3, target) - find(priority, priority+3, comp) > 0;
}

string change(string origin) {
    string ret;
    stack<char> st;
    for(int i = 0; i<origin.size(); i++) {
        char c = origin[i];
    	if (c == '(') {
            st.push(c);
    	} else if (c == ')') {
        	while(st.top() != '('){
                ret += st.top();
                st.pop();
            }
            st.pop();
        } else if(c == '+' || c == '*'){
            if(st.empty()) st.push(c);
            else{
                while(!st.empty() && !is_prior(c, st.top())){
                    ret += st.top();
                    st.pop();
                }
                st.push(c);
            }
        } else
            ret += c;
    }
    
    return ret;
}

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int len;
        string str;
        cin >> len >> str;
		
        string changed = change(str);
        cout << "#" << test_case << " " << calc(changed) << "\n";
    }
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}