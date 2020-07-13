/*
	사람 네트워크2 - 다른 노드들과의 거리가 가장 가까운 노드 찾기
*/
#include <bits/stdc++.h>
using namespace std;
#define MX 1000
#define INF 1000001
#define IOS ios::sync_with_stdio(0);cin.tie(0);
#define ENT cout<<"\n";
#define REP(i,a,b) for(auto i=a; i<b; i++)
typedef pair<int,int> pi;
typedef vector<int> vi;

int n, dist[MX][MX];

int CC(){
	int ret = INF;
	REP(i,0,n){
		int tmp = 0;
		REP(j,0,n) tmp+=dist[i][j];

		ret = min(ret, tmp);
	}

	return ret;
}

int main(int argc, char** argv){

	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin>>n;
		REP(i,0,n){
			REP(j,0,n){
				bool val; cin>>val;

				if(i==j) dist[i][j] = 0;
				else if(val) dist[i][j] = 1;
				else dist[i][j] = INF;
			}
		}

		REP(k,0,n){
			REP(i,0,n){
				REP(j,0,n){
					dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
				}
			}
		}

		cout<<"#"<<test_case<<" "<<CC();
		ENT

	}

	return 0;
}