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


struct word{int s, k;}; // size, alphabet known

int main(){
    
    IOS
    int N, M; cin>>N>>M;
    
    
    set<int> abc[26];
    word words[N];
    
    REP(i, 0, N-1){
        word cur;
        
        string str; cin>>str;
        set<int> cnt;
        
        REP(j, 0, str.size()-1) {
            int ch = str[j] - 'a';
            
            abc[ch].insert(i);
            cnt.insert(ch);
        }
        cur.s = cnt.size();
        cur.k = cur.s;
        
        words[i] = cur;
    }
    
    
    int know = N;
    REP(i, 1, M){
        char o, x; cin >> o >> x;
        int val = x - 'a';
        
        for (int a : abc[val]){
            
            word cur = words[a];
            
            if(o == '1'){
                if(cur.k == cur.s) know--;
                cur.k--;
            } else {
                cur.k++;
                if(cur.k == cur.s) know++;
            }
            
            words[a] = cur;
        }
        
        cout << know; ENT
    }
    

    return 0;
}
