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
	int dp[41][2] = {{1,0}, {0,1}};
	REP(i,2,41){
		dp[i][0] = dp[i-1][0] + dp[i-2][0];
		dp[i][1] = dp[i-1][1] + dp[i-2][1];
	}

	int T, a; cin>>T;
	
	REP(i,0,T){
		cin>>a;
		cout<<dp[a][0]<<" "<<dp[a][1]<<"\n";
	}

	return 0;
}