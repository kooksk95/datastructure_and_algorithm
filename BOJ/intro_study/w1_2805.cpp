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
    int n, m; cin>>n>>m;
    vi trees(n);

    for(auto &x : trees) cin>>x;
    sort(trees.begin(), trees.end());

    int ans = 0, low = 0, high = trees.back();

    while (low < high) {
        ll sum = 0;
        int mid = (low + high) / 2;
        for (auto x : trees)
            sum += x > mid ? x - mid : 0;
        if (sum < m) {
            high = mid;
        } else {
            ans = mid;
            low = mid + 1;
        }
    }
    cout << ans;
    
    
    return 0;
}
