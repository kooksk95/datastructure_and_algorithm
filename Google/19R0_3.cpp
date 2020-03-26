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

vi prime;
        
int Prime(int n){
    for(int x : prime)
        if(n%x == 0) return x;
    
    return -1;
}

int main(){
    IOS
    
    int test; cin >> test;
    
    REP(i, 1, test){
        // IN    
        int N, L; cin >>N>>L;
        
        // Sieve of Eratosthenes
        bool sieve[N+1] = {};
        REP(i, 2, N){
            if(!sieve[i]){
                prime.pb(i);
                for(int j = i+i; j<=N; j+=i)
                    sieve[j] = 1;
            }
        }
        
        vl cyp(L);
        for(ll &x : cyp) cin>>x;
        
        //// ALGORITHM
        // 1. Check repeatation
        vi raw(L+1);
        set<int> alp;
        
        int a1 = Prime(cyp[0]);
        int a2 = cyp[0]/a1;
        alp.insert(a1); alp.insert(a2);
            
        int pos = 0;
        while(1){
            
            if(cyp[pos] != cyp[pos+1]) {
                int x1 = Prime(cyp[pos+1]);
                
                raw[pos+1] = alp.count(x1) ? x1 : cyp[pos+1]/x1;
                raw[pos+2] = cyp[pos+1] / raw[pos+1];
                alp.insert(raw[pos+2]);
                break;
            }
            
            pos++;
        }
        
        
        // 2. Fill raw[0 : pos]
        for(int i = pos; i>=0; i--)
            raw[i] = raw[i+1] == a1 ? a2 : a1;

        // ... and raw[pos+3 : L]
        REP(i, pos+3, L){
            raw[i] = cyp[i-1]/raw[i-1];
            alp.insert(raw[i]);
        }
        
    
        // 3. Map prime number - alphabet
        unordered_map<int,char> trans;
        char a = 'A';
        for(int s : alp)
            trans[s] = a++;
        
        
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



