
#include <bits/stdc++.h>

using namespace std;
#define MAX 1001
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
    
    int n, ans; cin>>n;
    
    if(n < 100) ans = n;
    else {
        ans = 99;
        REP(i, 100, n) {
            int num = i;
            int a = num%10;
            num /= 10;
            int b =num%10;
            int c = num/10;
            if(a-b == b-c) ans++;
        }
        
    }
    
    cout << ans;

    return 0;
}
