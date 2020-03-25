#include <bits/stdc++.h>

using namespace std;
#define MAX 1001
#define IOS ios::sync_with_stdio(0);cin.tie(0);
#define REP(i,a,b) for(auto i=a; i<=b; i++) //repeat a~b
#define pb push_back
#define mp make_pair
#define ENT cout<<"\n";
typedef vector<int> vi;
typedef vector<long long> vl;
typedef long long ll;
typedef pair<int,int> pi;

int main(){
    IOS
    
    int test; cin >> test;
    
    REP(i, 1, test){
        int N; cin>>N;
        vector<char> ans;
        int cnt = N+N-2;
        while(cnt--){
            char lin; cin >> lin;
            if(lin == 'E') ans.pb('S');
            else ans.pb('E');
        }
        
        
        // OUT
        cout << "Case #"<<i<<": ";
        for(char x : ans) cout << x;
        ENT
        
    }
    
    
    return 0;
}


