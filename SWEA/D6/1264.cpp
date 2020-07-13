/*
	이미지 유사도 검사 - LCS
*/
#include <bits/stdc++.h>
using namespace std;
#define MX 501
#define INF 1000001
#define IOS ios::sync_with_stdio(0);cin.tie(0);
#define ENT cout<<"\n";
#define REP(i,a,b) for(auto i=a; i<b; i++)
typedef pair<int,int> pi;
typedef vector<int> vi;

int n, lcs[MX][MX];
string x, y;

int main(int argc, char** argv){

	int test_case;
	int T;
	cin>>T;
	cout.setf(ios::fixed);
	cout.precision(2);
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin>>n;
		cin>>x>>y;

		REP(i,0,n+1) lcs[0][i] = 0;
		REP(i,0,n+1) lcs[i][0] = 0;

		REP(i,1,n+1)
			REP(j,1,n+1)
				lcs[i][j] = x[i-1]==y[j-1] ? lcs[i-1][j-1]+1
											: max(lcs[i-1][j], lcs[i][j-1]);
				

		double ans = 100.0 * lcs[n][n]/n;
		cout<<"#"<<test_case<<" "<<ans;
		ENT

	}

	return 0;
}