#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, m, ans;
    cin >> n >> m;

    queue<int> q;
    bool visited[20001] = {};
    int dist[20001] = {};
    
    q.push(n);
    visited[n] = 1;

    while(!q.empty()){
        int v = q.front();
        
        if(v == m){
            ans = dist[v];
            break;
        }
        
        q.pop();

        if(!visited[v-1]) {
            visited[v-1] = 1;
            dist[v-1] = dist[v] + 1;
            q.push(v-1);
        }
        if(v<m && !visited[2*v]) {
            visited[2*v] = 1;
            dist[2*v] = dist[v] + 1;
            q.push(2*v);
        }

    }

    cout << ans;


    return 0;
}