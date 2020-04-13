
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



int main(){
    IOS
    
    int test; cin >> test;
    
    while(test--){
        string p, x;
        int n, num = 0;
        cin >> p >> n >> x;
        
        deque<int> dq;
        REP(i, 1, x.size()-2){
            if(x[i] == ',') {
                dq.pb(num);
                num = 0;
            } else {
                num *= 10;
                num += x[i] - '0';
            }
            
        }
        if(num) dq.pb(num);
        
        bool err = 0, rev = 0;
        REP(i, 0, p.size()-1){
            if(p[i] == 'R')
                rev = !rev;
            else {
                
                if(!dq.size()) {
                    err = 1;
                    break;
                }
                
                if(rev) dq.pop_back();
                else dq.pop_front();
                
            }
            
        }
        
        if(err) cout << "error\n";
        else {
            cout << "[";
            if(!dq.empty()){
                if(rev){
                    cout << dq.back();
                    dq.pop_back();
                    while(!dq.empty()){
                        cout << "," << dq.back();
                        dq.pop_back();
                    }
                } else {
                    cout << dq.front();
                    dq.pop_front();
                    while(!dq.empty()){
                        cout << "," << dq.front();
                        dq.pop_front();
                    }
                }
            }
            cout << "]\n";
        }
        
    }
    
    
    
    return 0;
}

