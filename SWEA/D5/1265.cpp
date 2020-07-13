/*
	달란트2
*/
#include <bits/stdc++.h>
using namespace std;
#define MX 12
#define INF 1000001
#define IOS ios::sync_with_stdio(0);cin.tie(0);
#define ENT cout<<"\n";
#define REP(i,a,b) for(auto i=a; i<b; i++)
typedef pair<int,int> pi;
typedef vector<int> vi;

int n,p;

int main(int argc, char** argv){

	int test_case;
	int T;
	cin>>T;
	cout.setf(ios::fixed);
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin>>n>>p;
		vector<int> d(p,0);

		int idx = 0;
		while(n--){
			d[idx++]++;
			idx %= p;
		}

		long long ans=d[0];
		REP(i,1,p)
			ans*=d[i];

		cout<<"#"<<test_case<<" "<<ans;
		ENT

	}

	return 0;
}