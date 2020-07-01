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

int dp[1000][3];

int main(){
    IOS
    int n; cin>>n;
    
    cin >> dp[0][0] >> dp[0][1] >> dp[0][2];
    
    REP(i, 1, n-1){
        int a, b, c;
        cin >> a >> b >> c;
        dp[i][0] = a + min(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = b + min(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = c + min(dp[i-1][0], dp[i-1][1]);
    }

    cout << min(min(dp[n-1][0], dp[n-1][1]), dp[n-1][2]);
   
    return 0;

}