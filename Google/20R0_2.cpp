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

int ans[101][2];


void nest(int s, int e){
    //cout << s << "~" << e;
    if(s <= e){
    //    cout << ": insert";
        ans[s][0]++, ans[e+1][1]++;
    }
    //ENT
}

int main(){
    
    IOS

    int test; cin >> test;
    
    REP(t, 1, test){
        
        string str, out; cin>>str;
        string in = str;
        int s = in.size();
        memset(ans, 0, sizeof(ans));
        
        while(1){
            
            vi pos;
            REP(i, 0, s) {
                if(in[i] == '0') {
                    pos.pb(i);
                } else {
                    in[i]--;
                }
            }
            
            int ps = pos.size();
            if(ps == s) break;
            else if (ps == 0){
                ans[0][0]++, ans[s][1]++;
                continue;
            }
            
            nest(0, pos[0] - 1);
            REP(i, 1, ps-1){
                nest(pos[i-1]+1, pos[i] - 1);
            }
            nest(pos[ps-1]+1, s-1);
            
        }
        
        // OUT
        cout << "Case #"<<t<<": ";
        REP(i, 0, s-1){
            while(ans[i][1]--) cout << ")";
            while(ans[i][0]--) cout << "(";
            cout << str[i];
        }
        
        while(ans[s][1]--) cout << ")";
        
        ENT
        
    }
    
    
    return 0;
}
