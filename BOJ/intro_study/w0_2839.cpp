
#include <bits/stdc++.h>

using namespace std;
#define MAX 51
#define IOS ios::sync_with_stdio(false);cin.tie(NULL);
#define REP(i,a,b) for(auto i=a; i<=b; i++) //repeat a~b
#define pb push_back
#define mp make_pair
#define ENT cout<<"\n";
typedef vector<int> vi;
typedef vector<long long> vl;
typedef long long ll;
typedef pair<int,int> pi;



int main(){
    IOS
    
    int n, x=0; cin>>n;
    while(n%5!=0 && n>=0){
        n -= 3;
        x++;
    }
    
    if(n<0) cout << -1;
    else cout << n/5 + x;
    
    
    return 0;
}

