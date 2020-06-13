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

ll arr[MAX], n;

int main(){
    IOS
    cin>>n;
    REP(i, 1, n) cin >> arr[i];

    vi len(n+1);
    int ans = 1;

    REP(k, 1, n){
        len[k] = 1;
        REP(i, 1, k-1){
            if(arr[i] < arr[k]) len[k] = max(len[i]+1, len[k]);
        }
        ans = max(len[k], ans);
    }
    
    
    cout << ans;

    return 0;
}