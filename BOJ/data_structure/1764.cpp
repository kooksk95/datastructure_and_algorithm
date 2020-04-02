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
    
    int n,m; cin >> n>>m;
    set<string> hear, ans;
    
    while(n--){
        string x;
        cin >> x;
        hear.insert(x);
    }
    
    while(m--){
        string x;
        cin >> x;
        if(hear.count(x)) ans.insert(x);
    }
    
    cout << ans.size(); ENT
    for(string s : ans) cout << s << "\n";
    
    
    return 0;
}
