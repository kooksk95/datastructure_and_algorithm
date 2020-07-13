/*
	최적경로 - 모든 점을 방문하는 최단 거리를 구하여라 BF -> DP
*/
#include<bits/stdc++.h>
using namespace std;
#define ENT cout<<"\n";
#define IOS ios::sync_with_stdio(0);cin.tie(0);
#define MX 10001
#define INF 100001
#define REP(i,a,b) for(auto i=a; i<b; i++)
typedef vector<int> vi;
typedef pair<int,int> pi;

int n, points[12][2];
vector<pair<int,int>> memo; // last customer, dist

int get_dist(int a, int b){
	return ( abs(points[a][0]-points[b][0]) + abs(points[a][1]-points[b][1]) );
}

void solve(int curr, int dist, int visited){
	if(visited == (1<<(n+1))-1)
		memo.push_back({curr, dist});


	REP(i,1,n+1){
		int tmp = INF;
		if((visited&(1<<i)) == 0){
			solve(i, dist+get_dist(curr, i), visited|(1<<i));
		}
	}

}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		memo.clear();

		cin>>n;
		cin>>points[0][0]>>points[0][1];
		cin>>points[n+1][0]>>points[n+1][1];
		REP(i,1,n+1){
			cin>>points[i][0]>>points[i][1];
		}

		solve(0, 0, 1);

		int ans = INF;
		REP(i,0,memo.size()){
			int calc = memo[i].second + get_dist(memo[i].first, n+1);
			ans = min(ans, calc);
		}

		cout <<"#"<<test_case<<" "<<ans;
		ENT

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}