#include <bits/stdc++.h>

using namespace std;
#define MAX 100001
#define IOS ios::sync_with_stdio(0);cin.tie(0);
#define REP(i,a,b) for(auto i=a; i<=b; i++) //repeat a~b
#define pb push_back
#define ENT cout<<"\n";
typedef vector<int> vi;
typedef vector<long long> vl;
typedef long long ll;


vi adj[32001];
vi topo;
bool seen[32001];

void dfs(int v){
    if(!seen[v]){
        seen[v] = 1;
        for(int i : adj[v]) dfs(i);
        topo.pb(v);
    }
}

int main(){
    IOS

    memset(seen, 0, sizeof(seen));
    int n, m;
    cin >> n>>m;
    while(m--) {
        int a, b; cin >>a>>b;
        adj[a].pb(b);
    }
    
    REP(i, 1, n) dfs(i);
    reverse(topo.begin(), topo.end());
    for(int i : topo) cout << i << " ";
    
    return 0;
}
