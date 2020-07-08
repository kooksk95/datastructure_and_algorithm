#include <bits/stdc++.h>
using namespace std;
#define MX 100
#define REP(i,a,b) for(auto i=a; i<b; i++)
#define ENT cout << "\n";
typedef pair<int,int> pi;

int graph[MX][MX], dist[MX][MX];
bool visited[MX][MX];
int n, dr[] = {1,-1,0,0}, dc[] = {0,0,1,-1};
vector<pi> v;

bool valid(int r, int c){
	return (r>=0 && r<n && c>=0 && c<n);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(visited, 0, sizeof(visited));
	memset(dist, 0, sizeof(dist));

	cin >> n;
	REP(i,0,n){
		REP(j,0,n){
			cin>> graph[i][j];
			if(graph[i][j]) v.push_back({i,j});
		}
	}

	int answer = 1000;
	for(pi land : v){
		if(visited[land.first][land.second]) continue;

		queue<pi> tmp, q;
		bool island[n][n] = {};
		
		// put ALL adj land in queue
		int lr = land.first, lc = land.second;
		visited[lr][lc] = 1;
		island[lr][lc] = 1;
		tmp.push({lr, lc});
		q.push({lr,lc});

		while(!tmp.empty()){
			int r = tmp.front().first;
			int c = tmp.front().second;
			tmp.pop();

			REP(i, 0, 4){
				int tr = r+dr[i];
				int tc = c+dc[i];
				if(valid(tr, tc) && graph[tr][tc] && !visited[tr][tc]){
					
					island[tr][tc] = 1;
					visited[tr][tc] = 1;
					tmp.push({tr,tc});
					q.push({tr,tc});
				}
			}
		}

		
		int dist = -1;
		while(!q.empty()) {
			int s = q.size();
			dist++;
			bool flag = 0;
			
			while(s--){
				int r = q.front().first;
				int c = q.front().second;
				q.pop();
				
				REP(i, 0, 4){
					int tr = r+dr[i];
					int tc = c+dc[i];
					if(valid(tr, tc) && !island[tr][tc]){
						
						if(graph[tr][tc]) {
							answer = min(dist, answer);
							flag = 1;
							break;
						} else {
							island[tr][tc] = 1;
							q.push({tr,tc});
						}
					}
				}

				if(flag) break;		
			}
			if(flag) break;
		}

	}

	cout << answer;
	return 0;
}