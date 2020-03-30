#include <bits/stdc++.h>

using namespace std;
#define MAX 6001
#define IOS ios::sync_with_stdio(0);cin.tie(0);
#define REP(i,a,b) for(auto i=a; i<=b; i++) //repeat a~b
#define pb push_back
#define ENT cout<<"\n";
typedef vector<int> vi;
typedef vector<long long> vl;
typedef long long ll;

struct Edge{ int u, v, w; };
Edge a[MAX];
int m, dist[501];

bool relax(){
    bool rel = false;
    REP(i, 0, m-1){
        int u = a[i].u, v = a[i].v, w = a[i].w;
        if(dist[u]!=0x7f7f7f7f && dist[u]+w < dist[v]) {
            dist[v] = dist[u]+w;
            rel = 1;
        }
    }
    return rel;
}

int main(){
    IOS

    int v;
    cin >> v>>m;
    REP(i, 0, m-1){
        int u, v, w;
        cin >> u>>v>>w;
        a[i].u = u;
        a[i].v = v;
        a[i].w = w;
    }
    
    memset(dist, 0x7f, sizeof(dist));
    dist[1] = 0;
    int tmp = v-1;
    while(tmp--) relax();
    
    if(relax()) cout << -1;
    else{
        REP(i, 2, v) {
            if(dist[i] == 0x7f7f7f7f) cout << "-1\n";
            else cout << dist[i] << "\n";
        }
    }

    return 0;
}

