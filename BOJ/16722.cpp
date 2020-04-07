#include <bits/stdc++.h>

using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);
#define REP(i,a,b) for(auto i=a; i<=b; i++)
#define ENT cout << "\n";

struct card{int shape, col, bg;};
unordered_map<string, int> m = {
    {"CIRCLE", 1}, {"TRIANGLE", 2}, {"SQUARE", 3},
    {"YELLOW", 1}, {"RED", 2},      {"BLUE", 3},
    {"GRAY", 1},   {"WHITE", 2},    {"BLACK", 3}
};
card cards[10];

bool is_hap(int i, int j, int k, int mode){
    int a, b, c;
    if(mode == 1){
        a = cards[i].shape;
        b = cards[j].shape;
        c = cards[k].shape;
    } else if(mode == 2){
        a = cards[i].col;
        b = cards[j].col;
        c = cards[k].col;
    } else {
        a = cards[i].bg;
        b = cards[j].bg;
        c = cards[k].bg;
    }
    
    return (a==b && a==c) || (a!=b && a!=c && b!=c);
}

    
int main(){
    
    IOS
    REP(i, 1, 9){
        string a, b, c; cin>>a>>b>>c;
        cards[i].shape = m[a];
        cards[i].col = m[b];
        cards[i].bg = m[c];
    }

    // store all combinations in set
    set<int> comb;
    REP(i, 1, 9){
        REP(j, i+1, 9){
            REP(k, j+1, 9){
                bool h1 = is_hap(i, j, k, 1);
                bool h2 = is_hap(i, j, k, 2);
                bool h3 = is_hap(i, j, k, 3);
                
                if(h1 && h2 && h3) comb.insert(100*i + 10*j + k);              
            }
        }
    }
    
    // match with set and erase
    int n, ans=0; cin >> n;
    bool g = 0;
    while(n--){
        char hg; cin>> hg;
        
        if(hg == 'H'){
            int a[3];
            cin >> a[0] >> a[1] >> a[2];
            sort(a, a+3);
            int tmp = 100*a[0] + 10*a[1] + a[2];
            
            if(comb.count(tmp)) {
                ans++;
                comb.erase(tmp);
            } else ans--;
            
        } else {
            if(!g && comb.size()==0) {
                ans += 3;
                g = 1;
            } else ans--;
        }        
    }
    
    cout << ans;
    
    return 0;
}
