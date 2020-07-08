
#include <bits/stdc++.h>
using namespace std;
#define MAX 50
#define REP(i, a, b) for(auto i=a; i<b; i++)

int n, m, dist[MAX][MAX], dr[4] = {1,-1,0,0}, dc[4] = {0,0,1,-1};
char graph[MAX][MAX];
bool visited[MAX][MAX];

bool valid(int r, int c){
	return (r>=0 && r<n && c>=0 && c<m)
			&& (graph[r][c] == 'L');
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	memset(visited, 0, sizeof(0));
	vector<pair<int,int>> v;
	REP(r, 0, n){
		REP(c, 0, m){
			cin >> graph[r][c];
			if(graph[r][c] == 'L'){
				v.push_back({r,c});
			}
		}
	}

	int answer = 0;
	for(auto points : v){
		// Pre-treatment before bfs
		int sr = points.first;
		int sc = points.second;
		memset(visited, 0, sizeof(visited));
		memset(dist, 0, sizeof(dist));
		
		// bfs
		queue<pair<int, int>> q;
		visited[sr][sc] = 1;
		q.push({sr, sc});
		while(!q.empty()){
			int r = q.front().first;
			int c = q.front().second;
			q.pop();

			REP(i, 0, 4){
				int tr = r + dr[i];
				int tc = c + dc[i];
				if(valid(tr, tc) && !visited[tr][tc]){
					visited[tr][tc] = 1;
					dist[tr][tc] = dist[r][c] + 1;
					q.push({tr,tc});
				}
			}
		}

		// store max distance
		for(auto x : v){
			int r = x.first;
			int c = x.second;
			answer = max(answer, dist[r][c]);
		}

	}


	cout << answer;

	return 0;
}