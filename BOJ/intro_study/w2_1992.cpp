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

int n, arr[64][64];

void solve(int x, int y, int len){
    if(len == 0) return;

    int a = arr[x][y];
    bool is_same = 1;
    REP(i, x, x+len-1){
        REP(j, y, y+len-1){
            if(arr[i][j] != a){
                is_same = 0;
                break;
            }
        }

        if(!is_same) break;
    }

    if(is_same){
        cout << a;
    } else {
        int l = len/2;
        cout << "(";
        solve(x, y, l);
        solve(x, y+l, l);
        solve(x+l, y, l);
        solve(x+l, y+l, l);
        cout << ")";
    }


}

int main(){
    IOS

    cin>>n;
    REP(i, 0, n-1) {
        REP(j, 0, n-1){
            char c; cin >> c;
            int x = c - '0';
            arr[i][j] = x;
        }
    }
    
    solve(0, 0, n);
    
    return 0;
}