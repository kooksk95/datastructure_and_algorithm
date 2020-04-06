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

ll dp[101][51];

int main(){
    
    IOS

    int l, k; cin>>l>>k;
    
    // DP for binominal Coefficient
    memset(dp, 0, sizeof(dp));
    REP(i, 0, 100) { 
        REP(j, 0, min(i, 50)) { 
            dp[i][j] = j==0 || j==i ? 1 : dp[i-1][j-1]+dp[i-1][j];
        } 
    }
    

    // x = # of thick black, y = # of thin black, z = # of thin white
    ll ans = 0;
    REP(x, 0, l/k){ 
        int len = l - k*x;
        REP(y, 0, len) {
            int z = x+y-1;
            if(z>=0 && k*x+y+z<=l){
                ans += dp[x+y][x];
            }
        }
    }
    
    
    cout << ans;
    
    return 0;
}
