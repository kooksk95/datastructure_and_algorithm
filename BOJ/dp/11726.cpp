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

	int dp[n+1] = {0,1,2};
	REP(i,3,n+1)
		dp[i] = (dp[i-1]+dp[i-2]) % 10007;
	
	cout<<dp[n];

	return 0;
}