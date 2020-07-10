/*
    암호문1 - List
*/
#include<bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int n; cin>>n;
        list<int> cryp;
        for(int i = 0; i<n; i++){
            int val; cin>>val;
            cryp.push_back(val);
        }
        
        list<int>::iterator it;
        int m, x, y; cin>>m;
        while(m--){
            char c; cin>>c>>x>>y;
            vector<int> tmp(y);
            for(int& i : tmp) cin>>i;
            
            it = cryp.begin();
            advance(it, x);
            cryp.insert(it, tmp.begin(), tmp.end()); 
        }
        
        cout << "#"<<test_case<<" ";
        it = cryp.begin();
        for(int i = 0; i<10; i++){
            cout << *it << " ";
            it++;
        }
    	cout << "\n";
    }
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}