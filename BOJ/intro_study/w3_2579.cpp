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

int dp[300];

int main(){
    IOS
    int n; cin>>n;
    vi step(n);
    for(int& x : step) cin>>x;

    dp[0] = step[0];
    dp[1] = step[0]+step[1];
    dp[2] = step[2] + max(step[0], step[1]);
    
    REP(i, 3, n-1)
        dp[i] = step[i] + max(dp[i-2], dp[i-3] + step[i-1]);
    

    cout << dp[n-1];
    
    return 0;

}   