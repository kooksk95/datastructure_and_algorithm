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
        int n, m; cin>>n>>m;
        
        cout << 'W';
        REP(j, 1, m-1) cout << 'B';
        ENT
        
        REP(i, 1, n-1){
            REP(j, 0, m-1){
                cout << 'B';
            }
            ENT
        }
    }
    
    return 0;
}


