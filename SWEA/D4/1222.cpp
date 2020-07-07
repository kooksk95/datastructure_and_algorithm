/*
    계산기1 - 한자리수 더하기만 하는 계산기 *후위표기식으로 바꾼 후 계산하기
*/
#include<bits/stdc++.h>

using namespace std;

int calc(string str) {
    stack<int> nums;
    for(int i = 0; i<str.size(); i++){
        char c = str[i];
        if(c == '+') {
            int b = nums.top(); nums.pop();
            int f = nums.top(); nums.pop();
            nums.push(b + f);
        } else {
            nums.push(c - '0');
        }  
    }
    return nums.top();
}

string change(string origin, int len) {
    string ret;
    int val;
    stack<char> st;
    
    for(int i = 0; i<len; i++) {
        char c = origin[i];
        if(c == '+'){
            ret += to_string(val);
            if(st.empty()) st.push(c);
            else ret += c;
        } else
            val = c - '0';
    }
    
    ret += to_string(val) + st.top();
    return ret;
}

int main(int argc, char** argv)
{
	int test_case;
	int T =10;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int len;
        string str;
        cin >> len >> str;
        string changed = change(str, len);
        cout << "#" << test_case << " " << calc(changed) << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}