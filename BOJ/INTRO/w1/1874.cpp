
#include <bits/stdc++.h>

using namespace std;
#define MAX 51
#define IOS ios::sync_with_stdio(false);cin.tie(NULL);
#define REP(i,a,b) for(auto i=a; i<=b; i++) //repeat a~b
#define pb push_back
#define mp make_pair
#define ENT cout<<"\n";
typedef vector<int> vi;
typedef vector<long long> vl;
typedef long long ll;
typedef pair<int,int> pi;

int dr[] = {1,-1,0,0}, dc[]={0,0,1,-1};


int main(){
    IOS
    
    int n; cin >> n;
    vi a(n);
    for(int &x : a) cin >> x;
    
    stack<int> st;
    string ans = "";
    int idx = 0;
    REP(i, 1, n){
        st.push(i);
        ans += "+\n";
        while(!st.empty() && st.top() == a[idx]){
            st.pop();
            ans += "-\n";
            idx++;
        }
    }
    
    if(st.empty()) cout << ans;
    else cout << "NO";
    
    
    return 0;
}

