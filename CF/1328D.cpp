#include <bits/stdc++.h>

using namespace std;
#define MAX 1001
#define IOS ios::sync_with_stdio(0);cin.tie(0);
#define REP(i,a,b) for(auto i=a; i<=b; i++)
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
    while(test--){
        int n; cin>>n;
        vi t(n), ans(n);
        cin >> t[0];
        ans[0] = 1;

        int s = 1;
        REP(i, 1, n-1) {
            cin >> t[i];
            if(t[i] == t[i-1]) ans[i] = ans[i-1];
            else {
                ans[i] = 3-ans[i-1];
                s = 2;
            }
        }

        
        if(ans[n-1]==ans[0] && t[n-1] != t[0]) {
            ans[n-1] = 3;
            s = 3;
        }

        cout << s;
        ENT
        for(int x : ans) cout << x << " ";
        ENT

        
    }
    
    return 0;
}


