#include <bits/stdc++.h>

using namespace std;
#define MX 401
#define INF 0x3f
#define REP(i,a,b) for(auto i=a;i<b;i++)
#define IOS ios::sync_with_stdio(0);cin.tie(0);
#define ENT cout<<"\n";
typedef vector<int> vi;
typedef pair<int,int> pi;

int n, k, ss, dist[MX][MX];

int main(){
	IOS
	memset(dist, INF, sizeof(dist));
	cin>>n>>k;
	REP(i,0,n+1)
		dist[i][i] = 0;

	int s, d;
	while(k--){
		cin>>s>>d;
		dist[s][d] = 1;
	}

	REP(k,1,n+1){
		REP(i,1,n+1){
			REP(j,1,n+1)
				dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
		}
	}

	cin>>ss;
	while(ss--){
		cin>>s>>d;
		if(dist[s][d] < INF) cout<<-1;
		else if(dist[d][s] < INF) cout<<1;
		else cout<<0;
		ENT
	}

	return 0;
}