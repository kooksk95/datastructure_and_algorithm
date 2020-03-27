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




int main(){
    
    IOS
    
    int test; cin >> test;
    while(test--){
        int n, k; cin>>n>>k;
        int num = 0;
        int p0 = 1, p1=1;
        
        while(1){
            num += p0;
            if(num >= k) break;
            
            p0++;
            p1 = k-num;
        }
        
        vector<char> ans(n, 'a');
        ans[n-p1] = 'b';
        ans[n-1-p0] = 'b';
        
        for(char x : ans) cout << x;
        ENT
    }
    
    return 0;
}

