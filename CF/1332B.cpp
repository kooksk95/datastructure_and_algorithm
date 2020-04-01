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

// 2 3 5 7 11 13 17 19 23 29 31


int main(){
    IOS
    int test; cin>>test;
    
    while(test--){
    
        // IN
        int primes[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

        int n; cin>>n;
        vi a(n);
        unordered_map<int, int> m;  // prime[i] - order
        int cnt = 0;
        vi ans;
        for(int &x : a) {
            cin >> x;
            
            REP(i, 1, 11){
                if(x%primes[i-1] == 0) {
                    if(m.count(primes[i-1]))
                        ans.pb(m[primes[i-1]]);
                    else {
                        cnt++;
                        m[primes[i-1]] = cnt;
                        ans.pb(cnt);
                    }
                    break;
                }
            }
        }
        
        
        ////// CODE
        
        
        // OUT
        cout << cnt; ENT
        for(int i : ans) cout << i << " "; ENT
        
    }
    return 0;
}

        
