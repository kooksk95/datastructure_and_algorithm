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

ll mem[21];

ll hanoi(int n){
    if(mem[n] == -1){
        if(n == 1) mem[n] = 1;
        else mem[n] = hanoi(n-1)*2 + 1;
    }
    return mem[n];
}

void solve(int n, int from, int to){
    if(n==1) {
        cout << from << " " << to <<"\n";
        return;
    }
    int transfer = 6 - from - to;
    solve(n-1, from, transfer);
    cout << from << " " << to <<"\n";
    solve(n-1, transfer, to);

}

int main(){
    IOS
    int n; cin>>n;

    // CODE
    memset(mem, -1, sizeof(mem));
    cout << hanoi(n); ENT
    solve(n, 1, 3);


    return 0;
}

        
