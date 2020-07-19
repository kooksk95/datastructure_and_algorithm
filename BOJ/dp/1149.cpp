#include <bits/stdc++.h>

using namespace std;
#define MX 500
#define INF 0x3f3f3f3f
#define REP(i,a,b) for(auto i=a;i<b;i++)
#define IOS ios::sync_with_stdio(0);cin.tie(0);
#define ENT cout<<"\n";
typedef vector<int> vi;
typedef pair<int,int> pi;



int main(){
	IOS

	int n,a,b,c; cin>>n;
	cin>>a>>b>>c;
	int dp[n][3] = {{a,b,c}};

	REP(i,1,n){
		cin>>a>>b>>c;
		dp[i][0] = a + min(dp[i-1][1], dp[i-1][2]);
		dp[i][1] = b + min(dp[i-1][0], dp[i-1][2]);
		dp[i][2] = c + min(dp[i-1][0], dp[i-1][1]);
	}

	int ans = min(dp[n-1][0], dp[n-1][1]);
	cout<<min(ans, dp[n-1][2]);

	return 0;
}