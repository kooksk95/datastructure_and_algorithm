#include <bits/stdc++.h>

using namespace std;
#define MAX 21
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

ll mem[91];

ll solve(int n){
    if(mem[n] == -1){
        if(n == 0 || n == 1) mem[n] = n;
        else mem[n] = solve(n-1) + solve(n-2);
    }

    return mem[n];
}

int main(){
    IOS
    int n; cin>>n;

    // CODE
    memset(mem, -1, sizeof(mem));
    cout << solve(n); ENT

    return 0;
}

        
