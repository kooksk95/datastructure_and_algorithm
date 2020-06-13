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
typedef vector<string> vs;
typedef vector<pair<int, int>> vp;
typedef long long ll;
typedef pair<int,int> pi;

int bests[MAX];

int main(){
    IOS
    int n; cin>>n;
    int ans = 0;

    REP(i, 1, n){
        int x; cin >> x;
        int idx = lower_bound(bests, bests+ans+1, x) - bests;
        ans = max(idx, ans);
        bests[idx] = x;
    }

    cout << ans;
    return 0;
}
