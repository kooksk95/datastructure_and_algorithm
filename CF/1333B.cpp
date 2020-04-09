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
    
    int test; cin >> test;
    while(test--){
        int n; cin>>n;
        vi a(n), b(n);
        for(int &x : a) cin >> x;
        for(int &x : b) cin >> x;
        
        bool yes = 1;
        set<int> seen;
        
        if(a[0] != b[0]) yes = 0;

        REP(i, 1, n-1){
            if(seen.size() == 3) break;
            
            seen.insert(a[i-1]);

            int target = b[i] - a[i];
            
            if(target>0 && !seen.count(1)) yes = 0;
            if (target<0 && !seen.count(-1)) yes = 0;
            
            if(yes == 0) break;
            
        }
        
        
        if(yes) cout << "YES";
        else cout << "NO";
        ENT
    
    }
    
    return 0;
}


