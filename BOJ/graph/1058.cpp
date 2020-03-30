#include <bits/stdc++.h>

using namespace std;
#define MAX 51
#define IOS ios::sync_with_stdio(0);cin.tie(0);
#define REP(i,a,b) for(auto i=a; i<=b; i++) //repeat a~b
#define pb push_back
#define mp make_pair
#define ENT cout<<"\n";
typedef vector<int> vi;
typedef vector<long long> vl;
typedef long long ll;
typedef pair<int,int> pi;

int n; 
bool adj[MAX][MAX];
vi fr;
int dist[MAX];
bool seen[MAX];

void bfs(int v){
    queue<int> q;
    memset(seen, 0, sizeof(seen));
    memset(dist, 0, sizeof(dist));
    q.push(v);
    seen[v] = 1;
    int cnt = -1;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        
        REP(i, 1, n){
            if(dist[cur]<2 && adj[cur][i] && !seen[i]){
                dist[i] = dist[cur]+1;
                q.push(i);
                seen[i] = 1;
            }
        }
        cnt++;
    }
    
    fr[v-1] = cnt;
    
}

int main(){
    IOS
    cin>>n;
    fr.resize(n);
    
    REP(i, 1, n){
        REP(j, 1, n){
            char x; cin >> x;
            adj[i][j] = x=='N' ? 0 : 1;
        }
    }

    REP(i, 1, n) bfs(i);
    
    cout << *max_element(fr.begin(), fr.end());
    
    return 0;
}

