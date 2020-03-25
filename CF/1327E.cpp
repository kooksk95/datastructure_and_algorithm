
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

int dr[] = {1,-1,0,0}, dc[]={0,0,1,-1};


int main(){
    IOS
    
    // IN
    ll n; cin>>n;
    
    
    // CODE
    vector<ll> ans(n);
    
    ll tmp = n;
    ll add = 81;
    while(tmp--){
        //cout << "######### LEN " << tmp+1 <<" ############\n";
        if(tmp == n-1) ans[tmp] = 10;
        else if (tmp == n-2) ans[tmp] = 180;
        else {
            add *= 10;
            //cout << add << ">";
            add %= 998244353;
            //cout << add; ENT
            //cout << ">>>" << (ans[tmp+1]*10) + add;
            
            ans[tmp] = ((ans[tmp+1]*10)%998244353 + add)%998244353;
            
            //cout << " ====> " << ans[tmp]; ENT

        }
    }
    
    
    // OUT
    for(int x : ans) cout << x << " ";
    
    return 0;
}

