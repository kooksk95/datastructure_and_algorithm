#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
#define IOS ios::sync_with_stdio(false);cin.tie(NULL);
#define REP(i,a,b) for(int i=a; i<=b; i++) //repeat a~b
#define pb push_back
#define ENT cout<<"\n";
#define MAX 1001

vi adj[MAX];
bool visit[MAX];
queue<int> q;

void dfs(int v){
    if(visit[v]) return;

    cout << v << " ";
    visit[v] = 1;
    for(int x:adj[v]) dfs(x);
}


int main(){
    IOS

    int n, e, a; cin >>n>>e>>a;
    REP(i, 1, e){
        int u, v; cin >>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    REP(i, 1, n) sort(adj[i].begin(), adj[i].end());

    dfs(a);
    ENT
    memset(visit, 0, sizeof(visit));
    q.push(a);
    visit[a] = 1;
    while(!q.empty()){
        int v = q.front();
        cout << v << " ";
        q.pop();
        for(int x : adj[v]){
            if(!visit[x]) {
                q.push(x);
                visit[x] = 1;
            }
        }
    }
    
    return 0;
}
