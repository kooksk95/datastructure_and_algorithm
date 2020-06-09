#include <bits/stdc++.h>

using namespace std;
#define MAX 8
#define IOS ios::sync_with_stdio(0);cin.tie(0);
#define REP(i,a,b) for(auto i=a; i<=b; i++)
#define pb push_back
#define mp make_pair
#define ENT cout<<"\n";
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<string> vs;
typedef vector<pair<int, int>> vp;
typedef long long ll;
typedef pair<int,int> pi;

int lab[MAX+1][MAX+1];

int main(){
    IOS
    int n,m; cin>>n>>m;
    REP(i, 1, n){
        REP(j, 1, m) cin >> lab[i][j];
    }

    

    cout << ans;

    return 0;
}