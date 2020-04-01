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
    int test; cin>>test;
    
    while(test--){
    
        // IN
        ll a, b, c, d; cin >> a>>b>>c>>d;
        ll x,y,x1,y1,x2,y2; cin>>x>>y>>x1>>y1>>x2>>y2;
        
        ////// CODE
        ll u = x+b-a;
        ll v = y+d-c;
        bool valid = 1;
        if(x1==x2 && (b != 0 || a != 0)) valid = 0;
        else if(y1==y2 && (c != 0 || d != 0)) valid = 0;
        else if(u<x1 || u>x2 || v<y1 || v>y2) valid = 0;
        
        // OUT
        if(valid) cout << "Yes\n";
        else cout << "No\n";
        
    }
    return 0;
}

        
