#include <bits/stdc++.h>
using namespace std;
#define MAX 100
#define REP(i, a, b) for(auto i = a; i<b; i++)

bool visited[MAX][MAX];
int dist[MAX][MAX];
int n, m;
int dr[4] = {1, -1, 0, 0}, dc[4] = {0, 0, 1, -1};

bool valid(int r, int c){
    return (r>=0 && r<n && c>=0 && c<m);
}

int main(){

    cin >> n >> m;
    REP(i, 0, n) {
        REP(j, 0, m){
            char c; cin >> c;
            visited[i][j] = c-'0';
        }
    }
    
    memset(dist, 0, sizeof(dist));

    queue<pair<int,int>> q;
    visited[0][0] = 0;
    dist[0][0] = 1;
    q.push({0,0});
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        
        REP(i, 0, 4){
            int tr = r + dr[i];
            int tc = c + dc[i];
            if(valid(tr, tc) & visited[tr][tc]){
                visited[tr][tc] = 0;
                dist[tr][tc] = dist[r][c] +1;
                q.push({tr, tc});
            }
        }

    }

    cout << dist[n-1][m-1];
    return 0;
}