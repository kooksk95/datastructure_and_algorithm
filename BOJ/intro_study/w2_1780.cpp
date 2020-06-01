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

int n, arr[2188][2188], ans[3];

void solve(int x, int y, int l){
    if(l==0) return;

    int a = arr[x][y];
    bool same = true;

    REP(i, x, x+l-1){
        REP(j, y, y+l-1){
            if(arr[i][j] != a){
                same = false;
                break;
            }
        }
        
        if(!same) break;
    }
    
    if(same)
        ans[a+1]++;
    else {
        int len = l/3;

        REP(i, 0, 2)
            REP(j, 0, 2)
                solve(x+i*len, y+j*len, len);
    }
    
}

int main(){
    IOS
    memset(ans, 0, sizeof(ans));

    cin>>n;
    REP(i, 1, n)
        REP(j, 1, n)
            cin >> arr[i][j];

    solve(1, 1, n);

    cout << ans[0] << "\n" << ans[1] << "\n" << ans[2];

    return 0;
}