#include <bits/stdc++.h>

using namespace std;
#define MAX 1000001
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

int dp[101][100001];

int main(){
    IOS
    int n, k; cin>>n>>k;
    memset(dp, 0, sizeof(dp));
    
    REP(i, 1, n){
        int w, v; cin >> w >> v;
        REP(j, 1, k){
            dp[i][j] = j < w ? dp[i-1][j]
                        : max(dp[i-1][j], dp[i-1][j-w] + v);
        }
    }

    cout << dp[n][k];
    return 0;
}