#include <bits/stdc++.h>

using namespace std;
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


int main(){
    IOS
    int n; cin>>n;

    int tmp = n;
    vector<pair<int, string>> words;
    set<string> ss;
    while(tmp--){
        // IN
        string str;
        cin >> str;

        if(ss.count(str)) continue;
        ss.insert(str);        
        int s = str.size();
        words.pb(mp(s, str));
    }

    ////// CODE
    sort(words.begin(), words.end());
    
    // OUT
    tmp = words.size()-1;
    REP(i, 0, tmp) cout << words[i].second << "\n";

    return 0;
}

        
