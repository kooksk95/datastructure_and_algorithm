#include <bits/stdc++.h>

using namespace std;
#define MAX 1001
#define IOS ios::sync_with_stdio(0);cin.tie(0);
#define REP(i,a,b) for(auto i=a; i<=b; i++)
#define pb push_back
#define mp make_pair
#define ENT cout<<"\n";
typedef vector<int> vi;
typedef vector<long long> vl;
typedef long long ll;
typedef pair<int,int> pi;




int main(){
    
    IOS
    
    int n; cin >> n;
    vl dist(n);
    for(ll &x : dist) cin>>x;
    
    double ans = dist[n-1];
    for(int i=n-2; i>=0; i--){
        ans = ceil(ans/dist[i])*dist[i];
    }
    
    cout << (ll)ans;
    
    return 0;
}


