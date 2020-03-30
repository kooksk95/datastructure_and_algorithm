#include <bits/stdc++.h>

using namespace std;
#define MAX 1001
#define IOS ios::sync_with_stdio(0);cin.tie(0);
#define REP(i,a,b) for(auto i=a; i<=b; i++) //repeat a~b
#define pb push_back
#define mp make_pair
#define ENT cout<<"\n";
typedef vector<int> vi;
typedef vector<long long> vl;
typedef long long ll;
typedef pair<int,int> pi;

int r, c;
char maze[MAX][MAX];
int dr[]={-1,1,0,0}, dc[]={0,0,1,-1};

int main(){
    IOS
    cin >> r>>c;
    queue<pi> jq, fq;
    REP(i, 1, r){
        REP(j, 1, c){
            cin >> maze[i][j];
            switch (maze[i][j]) {
                case 'F':
                    fq.push(mp(i,j));
                    break;
                case 'J':
                    jq.push(mp(i, j));
                    maze[i][j] = 'J';
                    break;
            }
        }
    }
    
    int ans = 0;
    while(!jq.empty()){
        int s = jq.size();
        ans++;
        while(s--){
            int cr = jq.front().first, cc = jq.front().second;
            jq.pop();
            // on fire
            if(maze[cr][cc] == 'F') continue;
            
            // keep move
            REP(i, 0, 3){
                int vr = cr+dr[i], vc = cc+dc[i];

                if(vr==0 || vr==r+1 || vc==0 || vc==c+1){
                    cout << ans;
                    return 0;
                } // current position is edge -> exit
                
                if(maze[vr][vc] == '.'){
                    jq.push(mp(vr,vc));
                    maze[vr][vc] = 'J';
                }
            }
        } // J's move
        
        s = fq.size();
        while(s--){
            int cr = fq.front().first, cc = fq.front().second;
            fq.pop();
            
            REP(i, 0, 3){
                int vr = cr+dr[i], vc = cc+dc[i];
                if(vr==0 || vr==r+1 || vc==0 || vc==c+1) continue;
                if(maze[vr][vc] != '#' && maze[vr][vc] != 'F'){
                    fq.push(mp(vr,vc));
                    maze[vr][vc] = 'F';
                }
            }
        }
    }
    
    cout << "IMPOSSIBLE";
    
    return 0;
}

        
