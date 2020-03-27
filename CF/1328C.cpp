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
        string x; cin >> x;
        vector<int> a(n), b(n);
        
        a[0] = 1;
        b[0] = 1;
        int pos = 1;
        while(pos<n && x[pos] != '1'){
            
            if(x[pos] == '2'){
                a[pos] = 1;
                b[pos] = 1;
            } else {
                a[pos] = 0;
                b[pos] = 0;
            }
            pos++;
        }
        
        if(pos<n){
            a[pos] = 1;
            b[pos] = 0;
            REP(i, pos+1, n-1){
                a[i] = 0;
                b[i] = x[i] - '0';
            }
        }
        
        for(int x : a) cout<<x; ENT
        for(int x : b) cout<<x; ENT
        
    }
    
    return 0;
}
