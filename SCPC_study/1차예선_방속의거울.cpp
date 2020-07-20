#include <bits/stdc++.h>
using namespace std;
#define MX 1000
#define INF 1<<30
#define REP(i,a,b) for(auto i=a; i<b; i++)
#define ENT cout<<"\n";

struct light { int r,c,d; };

int room[MX][MX], n;
int dr[]={0,1,0,-1, -1,0,1,0, 1,0,-1,0}, dc[]={1,0,-1,0, 0,-1,0,1, 0,1,0,-1}, dd[]={3,2,1,0, 1,0,3,2};
bool visited[MX][MX];

bool valid(int r, int c){
	return (r>=0 && r<n && c>=0 && c<n);
}

int main(int argc, char** argv) {
	int T, test_case, cnt;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		memset(visited, 0, sizeof(visited));
		cnt = 0;
		cin>>n;
		REP(i,0,n)
			REP(j,0,n){
				char c; cin>>c;
				room[i][j] = c-'0';
			}


		light curr = {0,0,0};
		while(valid(curr.r, curr.c)){
			int mirror = room[curr.r][curr.c];
			int r = curr.r;
			int c = curr.c;
			int d = curr.d;

			if(room[r][c] != 0) {
				curr.d = dd[(mirror-1)*4 + d];

				if(!visited[curr.r][curr.c]) cnt++;
			}
			visited[curr.r][curr.c] = 1;

			// update value
			curr.r = r + dr[mirror*4 + d];
			curr.c = c + dc[mirror*4 + d];
		}


		cout << "Case #" << test_case+1 << "\n";
		cout << cnt << "\n";
	}

	return 0;
}