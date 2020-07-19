#include <bits/stdc++.h>

using namespace std;
#define MX 500
#define INF 0x3f3f3f3f
#define REP(i,a,b) for(auto i=a;i<b;i++)
#define IOS ios::sync_with_stdio(0);cin.tie(0);
#define ENT cout<<"\n";
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef long long ll;

ll dp[91];

int main(){
	IOS
	memset(dp, 0, sizeof(dp));
	int n; cin>>n;
	dp[1] = 1;
	REP(i,2,n+1)
		dp[i] = dp[i-1]+dp[i-2];
	
	cout<<dp[n];

	return 0;
}