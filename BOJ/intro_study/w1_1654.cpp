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

int main(){
    IOS
    int k,n; cin>>k>>n;
    vi arr(k);
    for(auto &x : arr) cin >> x;
    sort(arr.begin(), arr.end());

    // CODE
    ll high = arr.back();
    ll low = 1;
    while(low < high){
        ll sum = 0;
        ll mid = (low + high)/2;
        for(auto x : arr) sum += x/mid;

        if(sum < n) high = mid;
        else low = mid+1;
    }


    cout << low-1;
    
    return 0;
}

        
