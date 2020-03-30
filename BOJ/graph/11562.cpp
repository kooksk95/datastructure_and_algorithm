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


int main(){
    IOS

    int n, m, k; cin>>n>>m;
    int dist[n+1][n+1];
    memset(dist, 0x3f, sizeof(dist));
    REP(i, 1, n) dist[i][i] = 0;
    REP(i, 1, m){
        int u,v,b; cin >> u>>v>>b;
        dist[u][v] = 0;
        if(b) dist[v][u] = 0;
        else dist[v][u] = 1;
    }
    
    // floyd warchall
    REP(k, 1, n){
        REP(i, 1, n){
            REP(j, 1, n){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
    cin >> k;
    REP(t, 1, k){
        int s, e; cin>>s>>e;
        cout << dist[s][e]; ENT
    }

    
    return 0;
}

