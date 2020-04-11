#include <bits/stdc++.h>

using namespace std;
#define MAX 1000001
#define IOS ios::sync_with_stdio(0);cin.tie(0);
#define REP(i,a,b) for(auto i=a; i<=b; i++)
#define pb push_back
#define mp make_pair
#define ENT cout<<"\n";
typedef vector<int> vi;
typedef vector<long long> vl;
typedef long long ll;
typedef pair<int,int> pi;

int parent[MAX];

int find_root(int i){
    if(parent[i] == i) return i;
    return parent[i] = find_root(parent[i]);
}

bool same_set(int i, int j){
    return find_root(i) == find_root(j);
}

void join_set(int i, int j){
    int pi = find_root(i), pj = find_root(j);
    if(pi != pj) parent[pi] = pj;
}


int main(){

    IOS
    int n, m; cin >> n>>m;
    REP(i, 0, n) parent[i] = i;
    
    while(m--){
        int a, b, c;
        cin >> a>>b>>c;
        if(a){
            if(same_set(b, c))
                cout << "YES\n";
            else
                cout << "NO\n";
        } else join_set(b, c);
        
    }
    
    
    
    return 0;
}
