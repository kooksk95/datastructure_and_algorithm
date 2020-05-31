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

ll arr[20], n, s;

int search(int i, int sum){
    if(i == n) return sum == s;

    return search(i+1, sum + arr[i]) + search(i+1, sum);
}

int main(){
    IOS
    cin>>n>>s;
    REP(i, 0, n-1) cin >> arr[i];

    ll ans = search(0, 0);
    
    if(s == 0) ans--; // CASE |s| = 0
    
    cout << ans;

    return 0;
}

        
