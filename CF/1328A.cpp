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
        int a, b; cin>>a>>b;
        
        if(a%b == 0) {
            cout << "0\n";
            continue;
        }
        
        cout << b-a%b;
        ENT
        
    }
    
    return 0;
}

