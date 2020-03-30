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

string add(string a) {
    int s = a.size();
    while(s--){
        if(a[s] == '9') {
            a[s] = '0';
            if(s == 0) a.insert(a.begin(), '1');
        }else {
            a[s]++;
            break;
        }
    }

    return a;
}

bool comp(string a, string b){
    bool res;
    // a < b = 1;
    return res;
}

string min_ab(string a, string b){
    int s1 = a.size(), s2 = b.size();
    bool next = 0;
    while(s2--){
        s1--, s2--;
        if(next) a[s1]--;
        if(s2 < 0) break;
        
        int tmp = a[s1] - b[s2];
        if(tmp<0) {
            a[s1] += 10;
            next = 1;
        } else next = 0;
    }

    return a;
}

string div_ab(string a, string b, int m){
    // m: 0 = div, 1 = mod
    string cnt = "0";
    while(1){
        string tmp = min_ab(a, b);
        if(comp(0, tmp)) break;

        a = tmp;
        cnt = add(cnt);
    }

    return m ? a : cnt;
}

string gcd(string a, string b){
    if(b == "0") return a;
    
    string a_mod_b = div_ab(a, b, 1);
    return gcd(b, a_mod_b);
}


int main(){
    IOS
    
    int test; cin >> test;
    
    REP(i, 1, test){
        // IN    
        string N;
        int L;
        cin >> N >> L;
        
        vector<string> cyp(L);
        for(string &x : cyp) cin>>x;
        
        //// ALGORITHM - KEY is to do simple arithmatic with string
        vector<string> raw(L+1);
        set<string> s;

        // 0. Skip repeatation
        int pos = 0;
        while(!cyp[pos].compare(cyp[pos+1])){
            pos++;
        }
        
        // 1. Get GCD from pos & pos+1
        // gcd(a > b)
        // raw[pos+1] = gcd(cyp[pos], cyp[pos+1]);
        raw[pos] = div_ab(cyp[pos], raw[pos+1], 0);
        s.insert(raw[pos+1]);
        s.insert(raw[pos]);
        
        // 2. Fill raw[0 : pos-1]
        for(int i = pos-1; i>=0; i--)
            raw[i] = raw[i+2];

        // ... and raw[pos+2 : L]
        REP(i, pos+2, L){
            raw[i] = div_ab(cyp[i-1], raw[i-1], 0);
            s.insert(raw[i]);
        }
        
    
        // 3. Map prime number - alphabet
        unordered_map<string,char> trans;
        char a = 'A';
        for(string str : s)
            trans[str] = a++;
        
        
        // 4. Final answer
        vector<char> ans(L+1);
        ans[0] = trans[raw[0]];
        
        REP(i, 1, L)
            ans[i] = trans[raw[i]];
        
        
        // OUT
        cout << "Case #"<<i<<": ";
        for(char x : ans) cout << x;
        ENT
        
    }
    
    
    return 0;
}



