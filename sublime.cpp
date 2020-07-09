
// https://www.acmicpc.net/problem/11559
#include <bits/stdc++.h>
using namespace std;
#define MX 10001
#define IOS ios::sync_with_stdio(0);cin.tie(0);
#define ENT cout<<"\n";
#define REP(i,a,b) for(auto i=a; i<b; i++)
typedef vector<int> vi;
typedef pair<int,int> pi;

bool visited[12][6];
char graph[12][6];

int main(){

	IOS
	vector<pi> v;
	REP(i,0,12){
		REP(j,0,6){
			cin >> graph[i][j];
			if(graph[i][j] != '.')
				v.push_back({i,j});
		}
	}

	for(pi p : v){
		if(visited[p.first][p.second])
			continiue;

		int r = p.first, c = p.second;
		char puyo = graph[r][c];
		visited

	}


	return 0;
}