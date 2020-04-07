#include <bits/stdc++.h>

using namespace std;
#define MAX 1001
#define IOS ios::sync_with_stdio(0);cin.tie(0);
#define REP(i,a,b) for(auto i=a; i<=b; i++)
#define pb push_back
#define mp make_pair
#define ENT cout<<"\n";
typedef vector<int> vi;
typedef vector<long long> vl;
typedef long long ll;
typedef pair<int,int> pi;


ll memo[31];

char solve(int n, int s){
    char ret;
    
    if(n <= memo[s-1]) ret = solve(n, s-1);
    else if(n == memo[s-1] + 1) ret = 'm';
    else if (n <= memo[s-1] + s+2) ret = 'o';
    else ret = solve(n-(memo[s-1] + s+2), s-1);
    
    return ret;
}


int main(){
    
    IOS
    int n; cin>>n;
    
    memo[0] = 0;
    
    int cur = 1;
    REP(i, 1, 31){
        memo[i] = 2*memo[i-1] + i+2;
        if(memo[i] >= n) {
            cur = i;
            break;
        }
    }
    
    cout << solve(n, cur);

    return 0;
}
