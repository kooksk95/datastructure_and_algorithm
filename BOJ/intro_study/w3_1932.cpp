#include <bits/stdc++.h>

using namespace std;
#define MAX 501
#define IOS ios::sync_with_stdio(0);cin.tie(0);
#define REP(i,a,b) for(auto i=a; i<=b; i++)
#define pb push_back
#define mp make_pair
#define ENT cout<<"\n";
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<string> vs;
typedef vector<pair<int, int>> vp;
typedef long long ll;
typedef pair<int,int> pi;

int dp[MAX+1][MAX+1];

int main(){
    IOS
    int n; cin>>n;
    memset(dp, 0, sizeof(dp));

    REP(i, 1, n){
        REP(j, 1, i){
            int x; cin >> x;
            dp[i][j] = x + max(dp[i-1][j-1], dp[i-1][j]);
        }
    }
    
    
    int ans = 0;
    REP(i, 1, n){
        ans = max(ans, dp[n][i]);
    }

    cout << ans;

    return 0;
}