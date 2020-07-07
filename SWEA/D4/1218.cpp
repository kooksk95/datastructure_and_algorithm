/*
    괄호 짝짓기
*/

#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int len; cin >> len;
		bool valid = 1;
        char stack[len];
        int size = 0;
        
        while(len--) {
            char c; cin >> c;
            
            if(c=='(' || c=='[' || c=='{' || c=='<'){
                stack[size++] = c;
            } else {
                char comp = stack[size-1];
                if(size>0 &&
                   ((comp == '(' && c==')')
                   || (comp == '[' && c==']')
                   || (comp == '{' && c=='}')
                   || (comp == '<' && c=='>'))) {
                  		size--;
                   } else
                       valid = 0;
            }
        }
        
		cout << "#"<<test_case<<" "<< valid <<"\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}