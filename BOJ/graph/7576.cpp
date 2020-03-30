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


int m, n;
int adj[MAX][MAX];
int dr[]={1,-1,0,0}, dc[]={0,0,1,-1};

bool valid(int r, int c){
    bool ret = 1;
    
    if(r==0 || c==0 || r>n || c>m) ret = 0;
    else if(adj[r][c] != 0) ret = 0;
    
    return ret;
}

int main(){
    IOS
    cin >> m>>n;
    
    queue<pi> q;
    
    REP(i, 1, n){
        REP(j, 1, m){
            cin >> adj[i][j];
            if(adj[i][j] == 1) q.push(mp(i,j));
        }
    }
    
    int t = 0;
    while(1){
        int s = q.size();
        
        while(s--){
            int cr = q.front().first, cc=q.front().second; q.pop();
            
            REP(i, 0, 3){
                int vr = cr+dr[i], vc=cc+dc[i];
                if(valid(vr, vc)){
                    adj[vr][vc] = 1;
                    q.push(mp(vr,vc));
                }
            }// visit adj vertice
        } // look of same distance
        
        if(q.empty()) break;
        t++;
    }
    
    bool done = 1;
    REP(i, 1, n){
        REP(j, 1, m){
            if(adj[i][j] == 0) done = 0;
        }
    }
    
    if(done) cout << t;
    else cout << -1;

    return 0;
}

