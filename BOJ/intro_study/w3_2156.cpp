#include <bits/stdc++.h>

using namespace std;
#define MAX 1000
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

int dp[10000][3];

int main(){
    IOS
    int n; cin>>n;
    dp[0][0] = 0;
    cin >> dp[0][1];
    dp[0][2] = dp[0][1];

    REP(i, 1, n-1){
        int val; cin >> val;
        dp[i][0] = max(max(dp[i-1][0], dp[i-1][1]), dp[i-1][2]);
        dp[i][1] = val + dp[i-1][0];
        dp[i][2] = val + dp[i-1][1];
    }

    cout << max(max(dp[n-1][0], dp[n-1][1]), dp[n-1][2]);
    
    return 0;

}   