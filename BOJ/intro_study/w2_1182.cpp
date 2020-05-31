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

ll arr[20], n, s, ans;
vector<int> subset;

void search(int i){
    if(i == n){
        
    } else {
        subset.pb(arr[i]);
        search(i+1);
        subset.pop_back();
        search(i+1);
    }
}

int main(){
    IOS
    cin>>n>>s;
    REP(i, 0, n-1) cin >> arr[i];

    memset(arr, 0, sizeof(arr));
    ans = 0;

    search(0);





    return 0;
}

        
