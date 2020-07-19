#include <bits/stdc++.h>

using namespace std;
#define MX 1000000000
#define INF 0x3f3f3f3f
#define REP(i,a,b) for(auto i=a;i<b;i++)
#define IOS ios::sync_with_stdio(0);cin.tie(0);
#define ENT cout<<"\n";
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef long long ll;


int main(){
	IOS
	int n; cin>>n;
	int dp[n+1][10] = {{}, {0,1,1,1,1,1,1,1,1,1}};

	REP(i, 2, n+1){
		dp[i][0] = dp[i-1][1];
		REP(j,1,9) dp[i][j] = (dp[i-1][j-1]+dp[i-1][j+1]) % MX;
		dp[i][9] = dp[i-1][8];
	}

	int ans = 0;
	REP(i,0,10) ans = (ans+dp[n][i]) % MX;
	cout<<ans;
	
	return 0;
}