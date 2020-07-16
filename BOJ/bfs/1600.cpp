#include<bits/stdc++.h>
using namespace std;
#define MX 200
#define INF 1<<30
#define REP(i,a,b) for(auto i=a; i<b; i++)
#define ENT cout<<"\n";
#define IOS ios::sync_with_stdio(0);cin.tie(0);
typedef vector<int> vi;
typedef pair<int,int> pi;

struct monkey{ int x, y, cnt; };

int k,h,w, dist[MX][MX][31];
int dr[]={1,-1,0,0}, dc[]={0,0,1,-1}, hr[]={2,2,1,1,-1,-1,-2,-2}, hc[]={1,-1,2,-2,2,-2,1,-1};
bool graph[MX][MX];

bool valid(int r, int c){
	return (r>=0 && r<h && c>=0 && c<w && !graph[r][c]);
}

int main() {
	IOS
	memset(dist, -1, sizeof(dist));
	cin>>k>>w>>h;
	REP(i,0,h)
		REP(j,0,w)
			cin>>graph[i][j];

	queue<monkey> q;
	q.push({0,0,k});
	dist[0][0][k] = 0;
	while(!q.empty()){
		int r = q.front().x, c = q.front().y, cnt = q.front().cnt;
		q.pop();

		REP(i,0,4){
			int tr = r+dr[i];
			int tc = c+dc[i];

			if(!valid(tr, tc) || dist[tr][tc][cnt] != -1) continue;

			dist[tr][tc][cnt] = dist[r][c][cnt]+1;
			q.push({tr,tc,cnt});
		}

		if(cnt){
			REP(i,0,8){
				int tr = r+hr[i];
				int tc = c+hc[i];

				if(!valid(tr, tc) || dist[tr][tc][cnt-1] != -1) continue;

				dist[tr][tc][cnt-1] = dist[r][c][cnt]+1;
				q.push({tr,tc,cnt-1});
			}
		}
	}

	int answer = INF;
	REP(i,0,k+1){
		if(dist[h-1][w-1][i] > -1)
			answer = min(answer, dist[h-1][w-1][i]);
	}
	
	if(answer == INF) cout<<-1;
	else cout<<answer;

	return 0;
}
