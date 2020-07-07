/*
    암호생성기
*/

#include<bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int vv; cin >> vv;
		queue<int> q;
        for(int i = 0; i<8; i++) {
            int val; cin >> val; q.push(val);
        }
        
        int cycle = 0;
        while(1){
            cycle++;
            if(q.front() - cycle <= 0){
                q.pop();
                q.push(0);
                break;
            }
            int v = q.front() - cycle;
            q.pop();
            q.push(v);
            cycle %= 5;
        }
        cout << "#" << test_case << " ";
        for(int i = 0; i<8; i++) {
            cout << q.front() << " "; q.pop();
        }
    	cout << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}