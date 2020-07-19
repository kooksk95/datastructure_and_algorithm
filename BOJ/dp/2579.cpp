#include <bits/stdc++.h>

using namespace std;
#define MX 500
#define INF 0x3f3f3f3f
#define REP(i,a,b) for(auto i=a;i<b;i++)
#define IOS ios::sync_with_stdio(0);cin.tie(0);
#define ENT cout<<"\n";
typedef vector<int> vi;
typedef pair<int,int> pi;


// 풀이 1
int main(){
	IOS
	int n,a,b; cin>>n>>a>>b;

	int dp[n][2] = {{a,0}, {b,a+b}};
	REP(i,2,n){
		cin>>a;
		dp[i][0] = a + max(dp[i-2][0], dp[i-2][1]);
		dp[i][1] = a + dp[i-1][0];
	}

	cout<<max(dp[n-1][0],dp[n-1][1]);

	return 0;
}


// 풀이 2
int dp[300];

int main(){
    IOS
    int n; cin>>n;
    vi step(n);
    for(int& x : step) cin>>x;

    dp[0] = step[0];
    dp[1] = step[0]+step[1];
    dp[2] = step[2] + max(step[0], step[1]);
    
    REP(i, 3, n-1)
        dp[i] = step[i] + max(dp[i-2], dp[i-3] + step[i-1]);
    

    cout << dp[n-1];
    
    return 0;

}   