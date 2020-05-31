#include <bits/stdc++.h>

using namespace std;
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

bool button[10];

int reachable(int n){
    if(n == 0 && button [0]) return 1;

    int val = 0;
    while(n){
        int x = n%10;

        if(!button[x]) {
            val = -1;
            break;
        }
        val++;
        n /= 10;
    }

    return val;
}

int main(){
    IOS
    memset(button, 1, sizeof(button));

    int target,m; cin>>target>>m;
    while(m--){
        int x; cin >> x;
        button[x] = false;
    }

    // CODE
    int ans = abs(target - 100);
    int range = max(100, target*2);
    REP(i, 0, range){
        int digits = reachable(i);
        
        if(digits >= 1){
            int tmp = digits + abs(target - i);
            ans = min(ans, tmp);
        }
    }

    cout << ans;

    return 0;
}

        
