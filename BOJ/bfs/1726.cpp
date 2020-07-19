#include <bits/stdc++.h>

using namespace std;
#define MX 100
#define INF 0x3f
#define REP(i,a,b) for(auto i=a;i<b;i++)
#define IOS ios::sync_with_stdio(0);cin.tie(0);
#define ENT cout<<"\n";
typedef vector<int> vi;
typedef pair<int,int> pi;

struct robot{ int x, y, d; };

int m, n, graph[MX][MX], dist[MX][MX][4];
bool visited[MX][MX][4];
int dd[4][2] = {{2,3},{2,3},{0,1},{0,1}};
queue<robot> q;

bool valid(int r, int c){
	return (r>=0 && r<m && c>=0 && c<n && !graph[r][c]);
}

void move_robot(int r, int c, int d){
	int cost = dist[r][c][d] + 1, tr, tc;
	if(d < 2){
		REP(j,1,4){
			tc = d&1 ? c-j : c+j;
			if(!valid(r, tc)) break;

			if(!visited[r][tc][d]){
				visited[r][tc][d] = 1;
				dist[r][tc][d] = cost;
				q.push({r,tc,d});
			}
		}
	} else {
		REP(i,1,4){
			tr = d&1 ? r-i : r+i;
			if(!valid(tr, c)) break;

			if(!visited[tr][c][d]){
				visited[tr][c][d] = 1;
				dist[tr][c][d] = cost;
				q.push({tr,c,d});
			}
		}
	} 
}

int main(){
	IOS
	memset(dist, INF, sizeof(dist));
	memset(visited, 0, sizeof(visited));
	cin>>m>>n;
	REP(i,0,m)
		REP(j,0,n)
			cin>>graph[i][j];

	int x, y, d;
	cin>>x>>y>>d;
	robot start = {x-1,y-1,d-1};
	cin>>x>>y>>d;
	robot goal = {x-1,y-1,d-1};

	dist[start.x][start.y][start.d] = 0;
	visited[start.x][start.y][start.d] = 1;
	q.push(start);
	while(!q.empty()){
		int r=q.front().x;
		int c=q.front().y;
		int d=q.front().d;
		q.pop();

		// visit other directions
		for(int i=0; i<2; i++){
			int td = dd[d][i];
			if(!visited[r][c][td]){
				visited[r][c][td] = 1;
				dist[r][c][td] = dist[r][c][d]+1;
				q.push({r,c,td});
			}
		}

		// visit other locations
		move_robot(r,c,d);

	}

	cout<<dist[goal.x][goal.y][goal.d];

	return 0;
}