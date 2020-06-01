#include <bits/stdc++.h>

using namespace std;
#define MAX 1000001
#define IOS ios::sync_with_stdio(0);cin.tie(0);
#define REP(i,a,b) for(auto i=a; i<=b; i++)
#define pb push_back
#define mp make_pair
#define ENT cout<<"\n";
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<string> vs;
typedef vector<pair<int, int>> vp;
typedef long long ll;
typedef pair<int,int> pi;

int n;

bool solve(int x){
    int ret = x;
    while(x){
        ret += x%10;
        x /= 10;
    }

    return ret == n;
}

int main(){
    IOS

    cin>>n;
    
    int ans = MAX;
    
    REP(i, 1, n)
        if(solve(i))
            ans = min(ans, i);

    if(ans == MAX) ans = 0;
    cout << ans;

    return 0;
}