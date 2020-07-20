#include <bits/stdc++.h>
using namespace std;
#define MX 1000001
#define INF 1<<30
#define REP(i,a,b) for(auto i=a; i<b; i++)

int dp[MX];

int main(int argc, char** argv) {
	int T, test_case, n, k;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		memset(dp, -1, sizeof(dp));
		cin>>n;
		vector<int> arr(n+1);
		REP(i,1,n+1) cin>>arr[i];
		cin>>k;

		int prev = 0;
		dp[0] = 0;
		for(int i=1; i<=n; i++){
			while (arr[i]-arr[prev]>k) prev++;
			if(prev == i) break;
			
			dp[i] = dp[prev] + 1;
		}


		cout << "Case #" << test_case+1 << "\n";
		cout << dp[n] << "\n";
	}

	return 0;
}