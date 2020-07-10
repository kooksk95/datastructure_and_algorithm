#include <bits/stdc++.h>
using namespace std;
#define MX 1000
#define REP(i,a,b) for(auto i=a; i<b; i++)
#define ENT cout << "\n";
typedef pair<int,int> pi;


int graph[MX][MX], dist[MX][MX][2];
bool visited[MX][MX][2];
int n, m, dr[4] = {1,0,-1,0}, dc[4] = {0,-1,0,1};

void print_board(){
	REP(i, 0, n){
		REP(j, 0, m){
			cout << dist[i][j];
		}
		ENT
	}
	ENT
}

bool valid(int r, int c){
	return (r>=0 && r<n && c>=0 && c<m);
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(dist, 0, sizeof(dist));
	memset(visited, 0, sizeof(visited));
	


	cin >> n >> m;
	REP(i,0,n){
		REP(j,0,m){
			char val; cin >> val;
			graph[i][j] = val-'0';
		}
	}

	queue<tuple<int,int,bool>> q;
	q.push({0,0,0});
	visited[0][0][0] = 1;
	dist[0][0][0] = 1;
	while(!q.empty()){
		int r=get<0>(q.front());
		int c=get<1>(q.front());
		bool breaked=get<2>(q.front());
		q.pop();

		REP(i,0,4){
			int tr = r+dr[i];
			int tc = c+dc[i];
			if(valid(tr,tc)){
				if(!graph[tr][tc] && !visited[tr][tc][breaked]){
					visited[tr][tc][breaked] = 1;
					dist[tr][tc][breaked] = dist[r][c][breaked] + 1;
					q.push({tr,tc,breaked});
				} else if (!breaked && !visited[tr][tc][0]){
					visited[tr][tc][1] = 1;
					dist[tr][tc][1] = dist[r][c][0] + 1;
					q.push({tr,tc,true});
				}
			}
			
		}
	}


	if(visited[n-1][m-1][1]) cout << dist[n-1][m-1][1];
	else if(visited[n-1][m-1][0]) cout << dist[n-1][m-1][0];
	else cout << -1;

	return 0;
}