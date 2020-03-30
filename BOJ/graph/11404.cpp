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


ll dist[101][101];

int main(){
    IOS

    memset(dist, 0x3f, sizeof(dist));
    int n, m;
    cin >> n>>m;
    REP(i, 1, n) dist[i][i] = 0;
    while(m--){
        int u, v;
        ll w;
        cin>>u>>v>>w;
        dist[u][v] = min(dist[u][v], w);
    }
    
    REP(k, 1, n){
        REP(i, 1, n){
            REP(j, 1, n){
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }

    REP(i, 1, n){
        REP(j, 1, n) {
            if(dist[i][j] < 0x3f3f3f3f) cout << dist[i][j] << " ";
            else cout << "0 ";
        }
        ENT
    }

    return 0;
}
