#include <bits/stdc++.h>
using namespace std;
#define MX 30
#define REP(i,a,b) for(auto i=a; i<b; i++)
#define ENT cout << "\n";
typedef pair<int,int> pi;

struct point{ int z,x,y; };

char graph[MX][MX][MX];
bool visited[MX][MX][MX];
int dist[MX][MX][MX], L, R, C;
int dx[]={1,-1,0,0,0,0}, dy[]={0,0,1,-1,0,0}, dz[]={0,0,0,0,1,-1};

// void print_board(){
// 	REP(i, 0, h){
// 		REP(j, 0, w){
// 			cout << dist[i][j];
// 		}
// 		ENT
// 	}
// 	ENT
// }

bool valid(int z, int x, int y){
	return (x>=0 & y>=0 & z>=0
			& x<R & y<C & z<L);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	point start, end;
	while(getline(cin, s)){
		memset(visited, 0, sizeof(visited));

		stringstream ss(s);
		ss >>L>>R>>C;
		if(L == 0) break;


		REP(i, 0, L){
			REP(j,0,R){
				REP(k,0,C){
					cin >> graph[i][j][k];
					if(graph[i][j][k] == 'S')
						start = {i,j,k};
					else if(graph[i][j][k] == 'E')
						end = {i,j,k};
				}
			}
			getline(cin,s);
			getline(cin,s);
		}

		queue<point> q;
		int x=start.x, y=start.y, z=start.z;
		visited[z][x][y] = 1;
		dist[z][x][y] = 0;
		q.push({z,x,y});
		while(!q.empty()){
			x=q.front().x, y=q.front().y, z=q.front().z;
			// cout<<"L"<<z<<": "<<x<<","<<y; ENT
			q.pop();

			REP(i,0,6){
				int tx = x+dx[i];
				int ty = y+dy[i];
				int tz = z+dz[i];

				if(!valid(tz, tx, ty) 
					|| graph[tz][tx][ty]=='#'
					|| visited[tz][tx][ty]) continue;

				visited[tz][tx][ty] = 1;
				dist[tz][tx][ty] = dist[z][x][y]+1;
				q.push({tz,tx,ty});
			}
		}

		if(visited[end.z][end.x][end.y])
			cout<<"Escaped in "<<dist[end.z][end.x][end.y]<<" minute(s).\n";
		else cout << "Trapped!\n";
	}

	return 0;
}