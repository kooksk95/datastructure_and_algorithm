#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >>n>>m;
    
    vector<int> adj[n+1];
    vector<int> adj_t[n+1];
    while(m--){
        int s, d; cin >>s>>d;
        adj[s].push_back(d);
        adj_t[d].push_back(s);
    }

    cin >> k;
    vector<int> p(k);
    for(int &x : p) cin >> x;

    // get distance from destination
    bool visited[n+1] = {};
    int dist[n+1] = {};
    queue<int> q;
    int start = p.back();
    
    visited[start] = 1;
    q.push(start);
    while(!q.empty()){
        int v = q.front();
        q.pop();

        for(int x : adj_t[v]){
            if(!visited[x]){
                visited[x] = 1;
                dist[x] = dist[v] + 1;
                q.push(x);
            }
        }
    }

    // track the path
    int must = 0, might = 0;
    for(int i = 1; i<k-1; i++){
        int prev = p[i-1];
        int curr = p[i];

        if(dist[prev]-1 < dist[curr]) must++;
        else {
            for(int x : adj[prev]){
                if(x != curr && dist[x] == dist[curr]){
                    might++;
                    break;
                }
            }
        }


    }

    cout << must << " " << must+might;

    return 0;
}