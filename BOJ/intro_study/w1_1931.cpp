#include <bits/stdc++.h>

using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);
#define REP(i,a,b) for(int i=a; i<=b; i++) //repeat a~b
#define pb push_back
#define ENT cout<<"\n";
typedef vector<int> vi;



int main(){
    IOS

    int n;
    cin >> n;
    vector<pair<int, int>> mt;
    REP(i, 1, n){
        int a, b;
        cin >> a>>b;
        mt.pb(make_pair(b, a));
    }

    sort(mt.begin(), mt.end());

    int cnt = 1;
    int prev = mt[0].first;
    REP(i, 1, n-1){
        if(mt[i].second >= prev){
            cnt++;
            prev = mt[i].first;
        }
    }

    cout << cnt;

    return 0;
}


