/*
    암호문2 - list
*/

#include<bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        list<int>::iterator it;
        list<int> cryp;
        int n; cin>>n;
        while(n--) {
            int val; cin>>val;
            cryp.push_back(val);
        }

        int m, x, y; cin>>m;
        char c;
        while(m--){
            cin>>c>>x>>y;
            it = cryp.begin();
            advance(it, x);

            if(c == 'I') {
                vector<int> tmp(y);
                for(int& i : tmp) cin>>i;
                cryp.insert(it, tmp.begin(), tmp.end());
            } else {
                while(y--){
                    it = cryp.erase(it);
                }              
            }
            
        }

        it = cryp.begin();
		cout << "#"<<test_case<<" ";
        for(int i = 0; i<10; i++) {
            cout << *it << " ";
            it++;
        }
        cout <<"\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}