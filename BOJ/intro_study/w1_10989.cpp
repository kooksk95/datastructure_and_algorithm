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

int arr[10001];

int main(){
    IOS
    int n; cin>>n;
    
    while(n--){
        int x; cin>>x;
        arr[x]++;
    }

    REP(i, 1, 10000){
        while(arr[i]--) cout << i << "\n";
    }

    return 0;
}

        
