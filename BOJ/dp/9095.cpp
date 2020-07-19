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
	int dp[11] = {1,1,2,4};
	REP(i,3, 11)
		dp[i] = dp[i-1] + dp[i-2] + dp[i-3];

	int T, a; cin>>T;
	
	REP(i,0,T){
		cin>>a;
		cout<<dp[a]<<"\n";
	}

	return 0;
}