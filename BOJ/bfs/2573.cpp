// 빙산 문제
// 갓 풀이 : https://www.acmicpc.net/source/12373254

#include <bits/stdc++.h>
using namespace std;
#define MAX 300
#define REP(i, a, b) for(auto i=a; i<b; i++)

int ice[MAX][MAX], melt_ice[MAX][MAX];
bool visited[MAX][MAX];
int n, m, tr, tc, dr[4] = {1,-1,0,0}, dc[4] = {0,0,1,-1};


bool valid(int r, int c){
	return (r>=0 && r<n && c>=0 && c<m);
}

void dfs(int r, int c) {
	if(visited[r][c]) return;

	visited[r][c] = 1;
	// melt ice
	REP(i, 0, 4){
		tr = r + dr[i];
		tc = c + dc[i];
		if(melt_ice[r][c] && valid(tr,tc) && !ice[tr][tc])
			melt_ice[r][c]--;
	}

	// visit next
	REP(i, 0, 4){
		tr = r + dr[i];
		tc = c + dc[i];
		if(valid(tr,tc))
			dfs(tr, tc);
	}

}

bool is_double(){
	memset(visited, 0, sizeof(visited));
	bool ice_found = 0;

	REP(r, 0, n){
		REP(c, 0, m){
			if(melt_ice[r][c] && !visited[r][c]){
				if(ice_found == 1) return true;

				ice_found = 1;
				queue<pair<int,int>> q;

				q.push({r,c});
				visited[r][c] = 1;
				while(!q.empty()){
					int cr = q.front().first;
					int cc = q.front().second;
					q.pop();

					REP(i, 0, 4){
						int tr = cr + dr[i];
						int tc = cc + dc[i];
						if(valid(tr,tc) && melt_ice[tr][tc] && !visited[tr][tc]){
							q.push({tr, tc});
							visited[tr][tc] = 1;
						}
					}
				}
			} // BFS 

		} // cols
	} // rows

	return false;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	REP(i, 0, n) 
		REP(j, 0, m) 
			cin>> melt_ice[i][j];

	int answer = 0;
	while(1){
		bool ice_found = 0;

		// do DFS
		memset(visited, 0, sizeof(visited));
		copy(&melt_ice[0][0], &melt_ice[0][0]+MAX*MAX, &ice[0][0]);

		// do DFS
		REP(r, 0, n){ 
			REP(c, 0, m){ 
				if(ice[r][c] != 0 && !visited[r][c]) {					
					
					ice_found = 1;
					dfs(r, c);
				}
			}
		}

		if(ice_found) answer++;
		else {
			answer = 0;
			break;
		}
		if(is_double()) break;

	}

	cout << answer;

	return 0;
}