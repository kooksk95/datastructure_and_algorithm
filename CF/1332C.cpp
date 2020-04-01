#include <bits/stdc++.h>

using namespace std;
#define MAX 200001
#define IOS ios::sync_with_stdio(0);cin.tie(0);
#define REP(i,a,b) for(auto i=a; i<=b; i++)
#define pb push_back
#define mp make_pair
#define ENT cout<<"\n";
typedef vector<int> vi;
typedef vector<long long> vl;
typedef long long ll;
typedef pair<int,int> pi;

int n, k, ans;
int cnt[MAX][26] = {};
string s;

int differ(int u, int v){
    int total = 0, mx = 0;
    REP(i, 0, 25){
        total += cnt[u][i]+cnt[v][i];
        mx = max(mx, cnt[u][i]+cnt[v][i]);
    }
    return total-mx;
}

int main(){
    IOS
    int test; cin>>test;

    while(test--){
        cin>>n>>k>>s;
        REP(i, 0, k-1){
            REP(j, 0, 25) cnt[i][j] = 0;
        }
        REP(i, 0, n-1){
            cnt[i%k][s[i]-'a']++;
        }
        ans = 0;
        REP(i, 0, k-1){
            ans += differ(i, k-1-i);
        }
        cout << ans/2; ENT
    } 


    return 0;
}

        
