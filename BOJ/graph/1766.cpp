#include <bits/stdc++.h>

using namespace std;
#define MAX 32001
#define IOS ios::sync_with_stdio(0);cin.tie(0);
#define REP(i,a,b) for(auto i=a; i<=b; i++) //repeat a~b
#define pb push_back
#define ENT cout<<"\n";
typedef vector<int> vi;
typedef vector<long long> vl;
typedef long long ll;

int n,m;
vector<vi> adj;
vi indeg;
priority_queue<int, vi, greater<int>> q;

int main(){
    IOS

    cin >>n>>m;
    adj.resize(n+1);
    indeg.clear();
    indeg.resize(n+1);
    
    while(m--){
        int u, k; cin >>u>>k;
        adj[u].pb(k);
        indeg[k]++;
    }
    
    REP(i, 1, n){
        if(indeg[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()){
        int curr = q.top(); q.pop();
        cout << curr << " ";
        
        for(int x : adj[curr]){
            indeg[x]--;
            if(!indeg[x]) q.push(x);
        }
    }
    
    return 0;
}

