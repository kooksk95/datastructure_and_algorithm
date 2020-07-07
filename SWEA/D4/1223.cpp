/*
    계산기2 - 한자리수 +/* 하는 계산기 *후위표기식으로 바꾼 후 계산하기
*/
#include<bits/stdc++.h>

using namespace std;

int calc(string str) {
    stack<int> nums;
    
    for(int i = 0; i<str.size(); i++) {
        char c = str[i];
        if(c == '+' || c == '*') {
            int b = nums.top(); nums.pop();
            int f = nums.top(); nums.pop();
            int tmp = c == '+' ? b+f : b*f;
            nums.push(tmp);
        } else
            nums.push(c-'0');
    }

    return nums.top();
}

bool not_prior(char target, char cmp){
    return !(target == '*' && cmp == '+');
}

string change(string origin) {
	string ret;
    stack<char> ops;
    
    for(int i = 0; i<origin.size(); i++) {
        char c = origin[i];
        if(c == '+' || c == '*') {
            if(ops.empty()) ops.push(c);
            else {
                while(!ops.empty() && not_prior(c, ops.top())) {
                    ret += ops.top();
                    ops.pop();
                }
                ops.push(c);
            }
        } else
            ret += c;
    }
    
    while(!ops.empty()){
        ret += ops.top();
        ops.pop();
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