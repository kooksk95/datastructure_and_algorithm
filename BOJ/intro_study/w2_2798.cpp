#include <bits/stdc++.h>

using namespace std;
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

int main(){
    IOS
    ll n,m; cin>>n>>m;
    vi arr(n);
    for(auto &x : arr) cin >> x;

    // CODE
    int ans = 0;
    REP(i, 0, n-1){
        REP(j, i+1, n-1){
            REP(k, j+1, n-1){
                int sum = arr[i] + arr[j] + arr[k];
                if(sum <= m) ans = max(ans, sum);
            }
        }
    }

    cout << ans;

    return 0;
}

        
