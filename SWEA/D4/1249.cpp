/*
	보급로 - (0,0) -> (N-1,N-1)으로 가는 경로의 최소비용을 구하라
*/
#include<bits/stdc++.h>
using namespace std;
#define ENT cout<<"\n";
#define IOS ios::sync_with_stdio(0);cin.tie(0);
#define MX 101
#define INF 100000
#define REP(i,a,b) for(auto i=a; i<b; i++)
typedef vector<int> vi;
typedef pair<int,int> pi;

int n, graph[MX][MX], memo[MX][MX];
int dr[]={1,-1,0,0}, dc[]={0,0,1,-1};

bool valid(int r, int c){
	return (r>=0 && r<n && c>=0 && c<n);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin>>n;
		REP(i,0,n){
			REP(j,0,n){
				char c; cin>>c;
				graph[i][j] = c-'0';
			}
		}
		REP(i,0,n){
			REP(j,0,n){
				memo[i][j] = INF;
			}
		}

		queue<pi> q;
		q.push({0,0});
		memo[0][0] = graph[0][0];
		while(!q.empty()){
			int r=q.front().first;
			int c=q.front().second;
			q.pop();

			REP(i,0,4){
				int tr=r+dr[i];
				int tc=c+dc[i];
				
				if(!valid(tr, tc)) continue;

				int tmp = graph[tr][tc]+memo[r][c];
				if(tmp<memo[tr][tc]){
					memo[tr][tc] = tmp;
					q.push({tr,tc});
				}
			}
		}

		cout <<"#"<<test_case<<" "<<memo[n-1][n-1];
		ENT

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}