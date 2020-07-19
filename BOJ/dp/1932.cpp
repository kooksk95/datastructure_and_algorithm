#include <bits/stdc++.h>

using namespace std;
#define MX 500
#define INF 0x3f3f3f3f
#define REP(i,a,b) for(auto i=a;i<b;i++)
#define IOS ios::sync_with_stdio(0);cin.tie(0);
#define ENT cout<<"\n";
typedef vector<int> vi;
typedef pair<int,int> pi;

int dp[MAX+1][MAX+1];


//풀이 1
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
    REP(i, 1, n)
        ans = max(ans, dp[n][i]);

    cout << ans;

    return 0;
}

//풀이 2
int main(){
	IOS
	memset(dp, 0, sizeof(dp));
	int n; cin>>n>>dp[0][0];

	REP(i,1,n){
		REP(j,0,i+1){
			cin>>dp[i][j];

			if (j==0)
				dp[i][0] += dp[i-1][0];
			else if (j==i)
				dp[i][i] += dp[i-1][i-1];
			else
				dp[i][j] += max(dp[i-1][j-1], dp[i-1][j]);
		}
	}

	int ans = dp[n-1][0];
	REP(i,1,n)
		ans = max(ans, dp[n-1][i]);
	
	cout<<ans;

	return 0;
}