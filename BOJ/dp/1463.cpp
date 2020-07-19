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
	int n; cin>>n;
	int dp[n+1];
	dp[1] = 0;
	
	REP(i,2,n+1){
		dp[i] = dp[i-1]+1;
		if(i%3 == 0)
			dp[i] = min(dp[i], dp[i/3]+1);
		if (i%2 == 0)
			dp[i] = min(dp[i], dp[i/2]+1);
	}
	
	cout<<dp[n];
	

	return 0;
}