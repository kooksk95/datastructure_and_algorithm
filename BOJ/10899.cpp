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

    int P, N; cin>>P>>N;
    vi t(N);
    for(int &x : t) cin>>x;
    
    sort(t.begin(), t.end());
    
    P--;
    ll ans = 0, solve = 0;
    while(solve < N){
        if(P-t[solve] < 0) break;
        
        ans += P;
        P -= t[solve];
        solve++;
    }
    
    cout << solve << " " << ans;
    
    return 0;
}
