#include <bits/stdc++.h>

using namespace std;
#define MAX 8
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


int main(){
    IOS
    int n,k; cin>>n>>k;
    vi coins(n);
    for(int& x : coins) cin >> x;

    int dp[k+1] = {1};

    for(int c : coins){
        REP(i, 1, k){
            if(i-c >= 0) dp[i] += dp[i-c];
        }
    }

    cout << dp[k];
    
    return 0;

}