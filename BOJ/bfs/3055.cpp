
#include <bits/stdc++.h>
using namespace std;
#define MX 50
#define REP(i,a,b) for(auto i=a; i<b; i++)
#define ENT cout << "\n";
typedef pair<int,int> pi;


char graph[MX][MX];
int dist[MX][MX];
bool visited[MX][MX];
int n, m, dr[4] = {1,-1,0,0}, dc[4] = {0,0,1,-1};


bool valid(int r, int c){
	return (r>=0 && r<n && c>=0 && c<m)
			&& (graph[r][c] == '.' || graph[r][c] == 'D');
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(visited, 0, sizeof(visited));
	cin >> n>>m;
		
	pi S, D;
	queue<pi> q, waters;
	REP(r,0,n){
		REP(c,0,m){
			cin >> graph[r][c];
			
			if(graph[r][c] == 'S')
				S = {r,c};
			else if (graph[r][c] == 'D')
				D = {r,c};
			else if (graph[r][c] == '*')
				waters.push({r,c});
		}
	}


	q.push(S);
	visited[S.first][S.second] = 1;
	dist[S.first][S.second] = 0;
	while(!q.empty()){
		int s, r, c;

		// Water expands first
		s = waters.size();
		while(s--){
			r = waters.front().first;
			c = waters.front().second;
			waters.pop();

			REP(i,0,4){
				int tr = r + dr[i];
				int tc = c + dc[i];
				if(valid(tr,tc) && graph[tr][tc] != 'D'){
					graph[tr][tc] = '*';
					waters.push({tr,tc});
				}
			}
		}


		// ... then the animal moves
		s = q.size();
		while(s--){
			r = q.front().first;
			c = q.front().second;
			q.pop();
			
			REP(i, 0, 4){
				int tr = r + dr[i];
				int tc = c + dc[i];
				if(valid(tr,tc) && !visited[tr][tc]){
					visited[tr][tc] = 1;
					dist[tr][tc] = dist[r][c] + 1;
					q.push({tr,tc});
				}
			}
		}
	}


	if(dist[D.first][D.second] == 0) cout << "KAKTUS";
	else cout << dist[D.first][D.second];

	return 0;
}