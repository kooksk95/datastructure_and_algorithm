#include <bits/stdc++.h>

using namespace std;
#define MAX 1001
#define IOS ios::sync_with_stdio(0);cin.tie(0);
#define REP(i,a,b) for(auto i=a; i<=b; i++)
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ENT cout<<"\n";
typedef vector<int> vi;
typedef vector<long long> vl;
typedef long long ll;
typedef pair<int,int> pi;



int main(){
    
    IOS
    int n, a, b; cin>>n>>a>>b;
    vi A(a), B(b);
    for(int &x : A) cin>>x;
    for(int &x : B) cin>>x;
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    
    
    int ans = 0;
    
    REP(i, 0, n/2) {
        int k = n - 2*i;
        if (k > a || i > b) continue;
        
        int sum = 0;
        REP (j, 0, k-1) sum += A[j];
        REP (j, 0, i-1) sum += B[j];
        
        ans = max(ans, sum);
    }
    
    cout << ans;
    
    return 0;
}
